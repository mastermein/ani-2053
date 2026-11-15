#include <iostream>
#include <vector>
#include <string>

struct ImageRecord 
{
    long long id;
    double x, y;
    double echelle, rotation, opacite;
    int miroirX, miroirY;
    long long largeur, hauteur;
    int selectionne;
    std::string chemin;
    long long octets;
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

    std::vector<ImageRecord> images(N);
    for (int i = 0; i < N; ++i) 
    {
        std::cin >> images[i].id >> images[i].x >> images[i].y
            >> images[i].echelle >> images[i].rotation >> images[i].opacite
            >> images[i].miroirX >> images[i].miroirY
            >> images[i].largeur >> images[i].hauteur
            >> images[i].selectionne >> images[i].chemin >> images[i].octets;
    }

    int nouvellePlace = 0;
    int restent = 0;
    int totalChanges = 0;

    for (int i = 0; i < N; ++i) 
    {
        if (images[i].octets == 0) 
        {
            continue;
        }

        nouvellePlace++;
        restent++;


        bool idChanged = (images[i].id != 0);
        bool selectedChanged = (images[i].selectionne != 0);
        bool pathChanged = (!images[i].chemin.empty());

        int countChanges = 0;
        if (idChanged) 
        {
            countChanges++;
        }
        if (selectedChanged) 
        {
            countChanges++;
        }
        if (pathChanged) 
        {
            countChanges++;
        }

        totalChanges += countChanges;

        std::cout << "ITEM " << nouvellePlace << " " << nouvellePlace;
        if (countChanges == 0) 
        {
            std::cout << " AUCUN";
        } else 
        {
            if (idChanged) 
            {
                std::cout << " id";
            }
            if (selectedChanged) 
            {
                std::cout << " selected";
            }
            if (pathChanged) 
            {
                std::cout << " sourcePath";
            }
        }
        std::cout << "\n";
    }

    std::cout << "RESTENT " << restent << "\n";
    std::cout << "CHANGES " << totalChanges << "\n";

    return 0;
}
