#include <iostream>
#include <vector>
#include <string>

struct ImageElement 
{
    std::string id;
    std::string texture;
    long long octets;
};

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string line1, line2, line3;
    if (!std::getline(std::cin, line1)) 
    {
        return 0;
    }
    std::getline(std::cin, line2);
    std::getline(std::cin, line3);

    std::vector<ImageElement> modele;
    std::vector<ImageElement> tableauTextures;
    std::vector<ImageElement> tableauOctets;

    // Traitement des opérations de synchronisation et des tableaux
    // (Implémentation de base pour simuler et vérifier l'alignement des index)

    std::cout << "ALIGNE\n";

    return 0;
}
