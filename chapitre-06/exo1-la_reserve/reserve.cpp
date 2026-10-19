#include <iostream>
#include <vector>
#include "NKThreading/NkThreadPool.h"
#include "NKThreading/NkThread.h"
#include "NkTime/NkChrono.h"

using namespace nkentseu;
using namespace nkentseu::threading;

void TacheCourte(void*) {
    volatile long long somme = 0;
    for (int i = 0; i < 1000; ++i) somme += i;
}

void TacheLongue(void*) {
    volatile long long somme = 0;
    for (int i = 0; i < 100000; ++i) somme += i;
}

int main() {
    NkThreadPool pool;
    std::cout << "Ouvriers : " << pool.GetNumWorkers() << std::endl;

    NkChrono chrono;
    void* q = nullptr;
    const int nbTaches = 200;

    // Échauffement de la réserve pour éviter les retards de démarrage
    for (int i = 0; i < nbTaches; ++i) {
        pool.Enqueue([&](auto&&...) { TacheCourte(q); });
    }
    pool.Join();

    // --- Fonctions utilitaires pour éviter la répétition du code ---
    auto mesurerReserve = [&](auto tache) {
        chrono.Reset();
        for (int i = 0; i < nbTaches; ++i) {
            pool.Enqueue([&](auto&&...) { tache(q); });
        }
        pool.Join();
        return static_cast<long long>(chrono.Elapsed().ToMilliseconds());
    };

    auto mesurerFils = [&](auto tache) {
        chrono.Reset();
        std::vector<NkThread*> fils;
        fils.reserve(nbTaches);
        for (int i = 0; i < nbTaches; ++i) {
            fils.push_back(new NkThread([=](void*) { tache(nullptr); }));
        }
        for (auto* fil : fils) {
            fil->Join();
            delete fil;
        }
        return static_cast<long long>(chrono.Elapsed().ToMilliseconds());
    };

    // 1. Tâche courte : 3 mesures pour la réserve et les fils
    long long tempsReserve[3], tempsFils[3];
    for (int m = 0; m < 3; ++m) tempsReserve[m] = mesurerReserve(TacheCourte);
    for (int m = 0; m < 3; ++m) tempsFils[m] = mesurerFils(TacheCourte);

    std::cout << "Réserve : " << tempsReserve[0] << "ms, " << tempsReserve[1] << "ms, " << tempsReserve[2] << "ms" << std::endl;
    std::cout << "Fils : " << tempsFils[0] << "ms, " << tempsFils[1] << "ms, " << tempsFils[2] << "ms" << std::endl;

    // 2. Tâche longue : 1 mesure pour chaque méthode
    long long tempsReserveLong = mesurerReserve(TacheLongue);
    long long tempsFilsLong = mesurerFils(TacheLongue);

    std::cout << "Tâche longue : " << tempsReserveLong << "ms, " << tempsFilsLong << "ms" << std::endl;

    return 0;
}
