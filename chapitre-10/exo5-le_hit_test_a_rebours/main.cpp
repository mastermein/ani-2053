#include <iostream>
#include <vector>
#include <string>
#include <cmath>

struct ImageItem 
{
    std::string nom;
    double x, y;
    double largeur, hauteur;
    double echelle;
};

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    if (!(std::cin >> N)) 
    {
        return 0;
    }

    std::vector<ImageItem> images(N);
    for (int i = 0; i < N; ++i) 
    {
        std::cin >> images[i].nom >> images[i].x >> images[i].y
            >> images[i].largeur >> images[i].hauteur >> images[i].echelle;
    }

    int Q;
    if (!(std::cin >> Q)) 
    {
        return 0;
    }

    int erreursCount = 0;

    for (int q = 0; q < Q; ++q) 
    {
        double cx, cy;
        std::cin >> cx >> cy;

        std::string resultatRebours = "AUCUN";
        std::string resultatEndroit = "AUCUN";


        for (int i = N - 1; i >= 0; --i) 
        {
            double halfW = (images[i].largeur * images[i].echelle) / 2.0;
            double halfH = (images[i].hauteur * images[i].echelle) / 2.0;
            double minX = images[i].x - halfW;
            double maxX = images[i].x + halfW;
            double minY = images[i].y - halfH;
            double maxY = images[i].y + halfH;

            if (cx >= minX && cx <= maxX && cy >= minY && cy <= maxY) 
            {
                resultatRebours = images[i].nom;
                break;
            }
        }


        for (int i = 0; i < N; ++i) 
        {
            double halfW = (images[i].largeur * images[i].echelle) / 2.0;
            double halfH = (images[i].hauteur * images[i].echelle) / 2.0;
            double minX = images[i].x - halfW;
            double maxX = images[i].x + halfW;
            double minY = images[i].y - halfH;
            double maxY = images[i].y + halfH;

            if (cx >= minX && cx <= maxX && cy >= minY && cy <= maxY) 
            {
                resultatEndroit = images[i].nom;
                break;
            }
        }

        if (resultatRebours != resultatEndroit) 
        {
            erreursCount++;
        }

        std::cout << "CLIC " << (q + 1) << " " << resultatRebours << " " << resultatEndroit << "\n";
    }

    std::cout << "ERREURS " << erreursCount << "\n";

    return 0;
}
