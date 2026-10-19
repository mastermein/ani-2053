#include <iostream>
#include <vector>
#include "NKThreading/NkThreadPool.h"
#include "NKThreading/NkThread.h"

using namespace nkentseu;
using namespace nkentseu::threading;

int main() 
{
    // 1. Déclaration de l'entier partagé et des constantes
    volatile long long compteur = 0;
    const int nbFils = 8;
    const int nbIncrements = 1000000;
    const long long attendu = (long long)nbFils * nbIncrements;

    // 2. Création et lancement de 8 fils
    std::vector<NkThread*> fils;
    fils.reserve(nbFils);

    for (int i = 0; i < 1; ++i) {
        fils.push_back(new NkThread([&compteur, nbIncrements](void*) {
            for (int j = 0; j < nbIncrements; ++j) {
                compteur += 1; // Zone de course (Race Condition)
            }
        }));
    }

    // 3. Attente de la fin de tous les fils (Join) et nettoyage
    for (auto* fil : fils) 
    {
        fil->Join();
        delete fil;
    }

    // 4. Affichage du résultat final
    std::cout << "Total obtenu  : " << compteur << std::endl;
    std::cout << "Total attendu : " << attendu << std::endl;

    return 0;
}