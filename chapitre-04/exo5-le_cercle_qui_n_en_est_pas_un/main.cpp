#include <iostream>
#include <cmath> // Pour std::cos, std::floor et std::ceil

int main() 
{

    // Valeur de Pi imposée par la règle
    const double pi = 3.141592653589793;

    int n = 0; // Nombre de cercles à lire
    if (!(std::cin >> n)) 
    {
        return 0;
    }

    int totalVisibles = 0; // Compteur des cercles avec verdict VISIBLE
    int totalRefuses = 0;  // Compteur des cercles avec moins de 3 segments

    for (int i = 0; i < n; ++i) 
    {
        long long r = 0;        // Rayon du cercle (pixels)
        long long segments = 0; // Nombre de segments du polygone

        if (!(std::cin >> r >> segments)) 
        {
            break;
        }

        // Moins de 3 segments n'est pas un cercle
        if (segments < 3) 
        {
            std::cout << r << " " << segments << " REFUSE\n";
            ++totalRefuses;
            continue;
        }

        // Calcul de l'écart géométrique g = r * (1 - cos(pi / n))
        const double g = static_cast<double>(r) * (1.0 - std::cos(pi / static_cast<double>(segments)));

        // Écart en millièmes de pixel, arrondi vers LE BAS
        const long long ecartMilliemes = static_cast<long long>(std::floor(g * 1000.0));

        //Cas où le rayon est nul (g == 0.0) -> ne divise pas par zéro
        if (g == 0.0) 
        {
            std::cout << r << " " << segments << " " << ecartMilliemes << " JAMAIS\n";
            continue;
        }

        //Zoom minimum pour que l'écart atteigne 1 px, arrondi vers LE HAUT
        const long long zoomPercent = static_cast<long long>(std::ceil(100.0 / g));

        //Verdict VISIBLE si zoom <= 100 %, sinon INVISIBLE
        const bool estVisible = (zoomPercent <= 100);
        if (estVisible) 
        {
            ++totalVisibles;
        }

        // Affichage de la ligne : rayon segments ecart zoom verdict
        std::cout << r << " " << segments << " " << ecartMilliemes << " " << zoomPercent << " "
                  << (estVisible ? "VISIBLE" : "INVISIBLE") << "\n";
    }

    //Bilan final
    std::cout << "VISIBLES " << totalVisibles << "\n";
    std::cout << "REFUSES " << totalRefuses << "\n";

    return 0;
}
