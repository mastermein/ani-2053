#include <iostream>
#include <string>
#include <vector>

int main() 
{
    // Ce que l'UTILISATEUR attend : une pile d'opérations.
    // La plus récente est à la fin de la liste.
    std::vector<std::string> pile;

    // Ce que fait l'OUTIL : il ne connaît que les traits de crayon présents.
    std::vector<int> traitsOutil;

    int numeroTrait = 0;   // numéro du dernier trait dessiné (1, 2, 3...)
    int numeroAnnule = 0;  // numéro du dernier ANNULE rencontré

    int justes = 0;
    int riens = 0;
    int trahis = 0;

    int nbOperations = 0;  // opérations autres que ANNULE  (le "o" de l'énoncé)
    int nbTraits = 0;      // celles que l'outil sait défaire : les TRAIT (le "a")

    // On lit les opérations une par une, jusqu'à la fin de l'entrée.
    std::string commande;
    while (std::cin >> commande) 
    {

        if (commande == "ANNULE") 
        {
            numeroAnnule++;

            // Ce que l'utilisateur attend : défaire la plus récente de la pile.
            std::string attendu = "AUCUNE";
            if (!pile.empty()) 
            {
                attendu = pile.back();
                pile.pop_back();
            }

            // Ce que fait l'outil : retirer le dernier trait de sa liste.
            std::string obtenu = "RIEN";
            if (!traitsOutil.empty()) 
            {
                obtenu = "TRAIT " + std::to_string(traitsOutil.back());
                traitsOutil.pop_back();
            }

            // Le verdict.
            std::string verdict;
            if (obtenu == attendu) 
            {
                verdict = "JUSTE";   // l'outil défait exactement ce qui était visé
                justes++;
            } else if (attendu == "AUCUNE" && obtenu == "RIEN") 
            {
                verdict = "JUSTE";   // personne n'attendait rien, et rien ne se passe
                justes++;
            } else if (obtenu == "RIEN") 
            {
                verdict = "RIEN";    // l'utilisateur attendait quelque chose, rien ne vient
                riens++;
            } else {
                verdict = "TRAHI";   // l'outil a défait un autre trait
                trahis++;
            }

            std::cout << "ANNULE " << numeroAnnule
                      << " ATTENDU " << attendu
                      << " OBTENU " << obtenu
                      << " " << verdict << "\n";

        } 
        else if (commande == "TRAIT") 
        {
            numeroTrait++;
            nbOperations++;
            nbTraits++;
            // Dans la pile, un trait s'écrit "TRAIT n".
            pile.push_back("TRAIT " + std::to_string(numeroTrait));
            // L'outil retient ce trait.
            traitsOutil.push_back(numeroTrait);

        } 
        else if (commande == "EFFACE") 
        {
            nbOperations++;
            pile.push_back("EFFACE");
            // L'outil vide sa liste de traits (et ne sait pas défaire ça).
            traitsOutil.clear();

        } 
        else if (commande == "RANGE") 
        {
            nbOperations++;
            pile.push_back("RANGE");

        } 
        else if (commande == "DEPOSE" || commande == "DEPLACE" ||
                   commande == "SUPPRIME" || commande == "MIROIR") 
                   {
            // Ces opérations sont suivies du nom de l'image.
            std::string nom;
            std::cin >> nom;
            nbOperations++;
            pile.push_back(commande + " " + nom);
        }
    }

    // Les quatre lignes de fin, toujours affichées.
    std::cout << "JUSTES " << justes << "\n";
    std::cout << "RIENS " << riens << "\n";
    std::cout << "TRAHIS " << trahis << "\n";
    std::cout << "ANNULABLES " << nbTraits << " SUR " << nbOperations << "\n";

    return 0;
}

