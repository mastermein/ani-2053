#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

// Dit si une annonce est vraie, face à l'état des fonctions à un commit.
bool annonceVraie(const std::set<std::string>& etat,
                  const std::string& etatAnnonce,
                  const std::string& fonction) {
    bool presente = (etat.count(fonction) == 1);
    if (etatAnnonce == "A_VENIR") 
    {
        // "A_VENIR" est vraie tant que la fonction n'existe pas encore.
        return !presente;
    }
    // "DISPONIBLE" est vraie si la fonction existe.
    return presente;
}

int main() 
{
    // 1. On lit l'historique : H commits, du plus ancien au plus récent.
    int nbCommits = 0;
    std::cin >> nbCommits;

    std::vector<std::string> hashs;            // le nom de chaque commit
    std::vector<std::set<std::string> > etats; // les fonctions présentes APRES chaque commit
    std::map<std::string, int> positionDuHash; // pour retrouver un commit par son nom

    std::set<std::string> etatCourant;  // au début, aucune fonction n'existe

    for (int i = 0; i < nbCommits; i++) 
    {
        std::string hash;
        std::string action;
        int k = 0;
        std::cin >> hash >> action >> k;

        for (int j = 0; j < k; j++) 
        {
            std::string fonction;
            std::cin >> fonction;
            if (action == "AJOUTE") 
            {
                etatCourant.insert(fonction);  // déjà présente : rien ne change
            } 
            else 
            {
                etatCourant.erase(fonction);   // absente : rien ne change
            }
        }

        // On garde une photo de l'état après ce commit.
        hashs.push_back(hash);
        etats.push_back(etatCourant);
        positionDuHash[hash] = i;
    }

    // 2. On lit les annonces.
    int nbAnnonces = 0;
    std::cin >> nbAnnonces;

    int mensonges = 0;

    for (int numero = 1; numero <= nbAnnonces; numero++) 
    {
        std::string hashEcrit;
        std::string etatAnnonce;
        std::string fonction;
        std::cin >> hashEcrit >> etatAnnonce >> fonction;

        int ecrite = positionDuHash[hashEcrit];  // le commit où l'annonce a été écrite
        int dernier = nbCommits - 1;             // le tout dernier commit

        // 3. Vraie au dernier commit ?
        if (annonceVraie(etats[dernier], etatAnnonce, fonction)) 
        {
            std::cout << "ANNONCE " << numero << " VRAI\n";
        } 
        else 
        {
            // 4. Elle ment. On remonte depuis le dernier commit tant que
            int h = dernier;
            while (h > ecrite && !annonceVraie(etats[h - 1], etatAnnonce, fonction)) 
            {
                h--;
            }
            std::cout << "ANNONCE " << numero << " MENT " << hashs[h] << "\n";
            mensonges++;
        }
    }

    // 5. Le total, toujours affiché (même sans aucune annonce).
    std::cout << "MENSONGES " << mensonges << "\n";

    return 0;
}

