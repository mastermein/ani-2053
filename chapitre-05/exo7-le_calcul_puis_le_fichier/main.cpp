#include <iostream>
#include <string>

int main() 
{
    // Désactivation de la synchronisation pour accélérer les entrées/sorties
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Variable sur 64 bits pour stocker le seuil limite en octets qui sépare la mémoire du flux
    long long seuilLimite = 0;
    
    // Variable entière pour stocker le nombre de fichiers sonores à analyser
    int nombreSons = 0;

    // Lecture du seuil et du nombre de sons depuis l'entrée standard
    std::cin >> seuilLimite >> nombreSons;

    // Variables pour les bilans finaux
    long long sommeMemoireTotale = 0;
    int compteurFlux = 0;
    int compteurRefuses = 0;

    // Boucle pour traiter chaque son un par un
    for (int i = 0; i < nombreSons; ++i) 
    {
        std::string nomSon;
        long long frequenceEchantillonnage = 0;
        long long nombreCanaux = 0;
        long long profondeurBits = 0;
        long long dureeMillisecondes = 0;
        long long tailleFichierDisque = 0;

        std::cin >> nomSon 
                 >> frequenceEchantillonnage 
                 >> nombreCanaux 
                 >> profondeurBits 
                 >> dureeMillisecondes 
                 >> tailleFichierDisque;

        // Règle 1 : Seules les profondeurs de 8, 16, 24 et 32 bits sont acceptées par le module
        if (profondeurBits != 8 && profondeurBits != 16 && profondeurBits != 24 && profondeurBits != 32) 
        {
            std::cout << nomSon << " REFUSE\n";
            compteurRefuses++;
            continue; // On passe directement au son suivant
        }

        // Règle 2 : Calcul de la taille brute non compressée (en octets)
        // On effectue d'abord toutes les multiplications sur 64 bits, puis on divise par 1000 à la fin
        long long tailleBruteOctets = frequenceEchantillonnage * nombreCanaux * (profondeurBits / 8) * dureeMillisecondes / 1000;

        // Règle 3 : Calcul du pourcentage d'occupation du fichier par rapport à la taille brute
        long long pourcentageFichier = tailleFichierDisque * 100 / tailleBruteOctets;

        // Règle 4 & 5 : Si la taille brute dépasse strictement le seuil, c'est un FLUX, sinon c'est en MEMOIRE
        if (tailleBruteOctets > seuilLimite) 
        {
            std::cout << nomSon << " " << tailleBruteOctets << " " << pourcentageFichier << " FLUX\n";
            compteurFlux++;
        } else 
        {
            std::cout << nomSon << " " << tailleBruteOctets << " " << pourcentageFichier << " MEMOIRE\n";
            sommeMemoireTotale += tailleBruteOctets;
        }
    }

    // Affichage des bilans finaux obligatoires exigés par la plateforme
    std::cout << "MEMOIRE " << sommeMemoireTotale << "\n";
    std::cout << "FLUX " << compteurFlux << "\n";
    std::cout << "REFUSES " << compteurRefuses << "\n";

    return 0;
}
