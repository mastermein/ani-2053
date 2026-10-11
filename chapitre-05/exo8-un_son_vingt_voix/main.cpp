#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
    // Désactivation de la synchronisation pour accélérer les entrées/sorties
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Variable pour la durée du son (en millisecondes)
    long long dureeSon = 0;
    // Variable pour le temps de chargement d'un fichier audio (en millisecondes)
    long long tempsChargement = 0;
    // Variable entière pour stocker le nombre total de lectures demandées
    int nombreLectures = 0;

    std::cin >> dureeSon >> tempsChargement >> nombreLectures;

    // Tableau dynamique (vecteur) pour stocker les instants précis de chaque lecture
    std::vector<long long> instantsLectures(static_cast<size_t>(nombreLectures));
    for (int i = 0; i < nombreLectures; ++i) 
    {
        std::cin >> instantsLectures[static_cast<size_t>(i)];
    }

    // Variables pour les bilans finaux
    long long maxVoixSimultanees = 0;
    long long maxRetardAccumule = 0;
    int totalCoupes = 0;

    // Variables de suivi pour le calcul
    long long finDernierChargement = 0; // Fin du chargement précédent
    int indexPremiereVoixActive = 0;     // Indice de la première lecture qui n'est pas encore finie

    // Boucle pour analyser chaque lecture de la rafale une par une
    for (int i = 0; i < nombreLectures; ++i) 
    {
        size_t indexCourant = static_cast<size_t>(i);
        long long instantActuel = instantsLectures[indexCourant];

        // 1. Calcul du nombre de voix actives en même temps à cet instant
        // On retire du compte les lectures dont le son est déjà terminé (instant de départ + durée <= instant actuel)
        while (indexPremiereVoixActive < i && instantsLectures[static_cast<size_t>(indexPremiereVoixActive)] + dureeSon <= instantActuel) 
        {
            ++indexPremiereVoixActive;
        }
        long long nombreVoixActives = i - indexPremiereVoixActive + 1;

        // 2. Calcul du chargement séquentiel : le chargement commence au plus tard entre l'instant demandé et la fin du chargement précédent
        long long debutChargement = (i == 0) ? instantActuel : std::max(instantActuel, finDernierChargement);
        finDernierChargement = debutChargement + tempsChargement;

        // 3. Le retard est égal à la fin du chargement moins l'instant où la lecture était demandée
        long long retardActuel = finDernierChargement - instantActuel;

        // 4. Une seule voix rejouée : elle est coupée si une nouvelle lecture commence avant la fin de celle-ci (instant + durée)
        bool estCoupee = (i + 1 < nombreLectures) && (instantsLectures[indexCourant + 1] < instantActuel + dureeSon);

        // Affichage du résultat pour cette lecture précise
        std::cout << instantActuel << " " << nombreVoixActives << " " << retardActuel << " " << (estCoupee ? "COUPE" : "ENTIER") << "\n";

        // Mise à jour des valeurs maximales pour les bilans
        maxVoixSimultanees = std::max(maxVoixSimultanees, nombreVoixActives);
        maxRetardAccumule = std::max(maxRetardAccumule, retardActuel);
        if (estCoupee) 
        {
            totalCoupes++;
        }
    }

    // Affichage des bilans finaux obligatoires exigés par la plateforme
    std::cout << "VOIX_MAX " << maxVoixSimultanees << "\n";
    std::cout << "RETARD_MAX " << maxRetardAccumule << "\n";
    std::cout << "COUPES " << totalCoupes << "\n";

    return 0;
}
