#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct ImageItem 
{
    std::string nom;
    std::string sourcePath;
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

    std::vector<ImageItem> modele(N);
    for (int i = 0; i < N; ++i) 
    {
        std::cin >> modele[i].nom >> modele[i].sourcePath >> modele[i].octets;
    }

    int M;
    if (!(std::cin >> M)) 
    {
        return 0;
    }

    int decalagesCount = 0;

    for (int m = 0; m < M; ++m) 
    {
        std::string cmd;
        if (!(std::cin >> cmd)) 
        {
            break;
        }

        if (cmd == "AJOUT") 
        {
            std::string nom, sourcePath;
            long long octets;
            std::cin >> nom >> sourcePath >> octets;
            modele.push_back({nom, sourcePath, octets});
        } 
        else if (cmd == "SUPPR") 
        {
            int idx;
            std::cin >> idx;
            if (idx >= 0 && idx < (int)modele.size()) 
            {
                modele.erase(modele.begin() + idx);
            }
        } 
        else if (cmd == "ECHANGE") 
        {
            int i, j;
            std::cin >> i >> j;
            if (i >= 0 && i < (int)modele.size() && j >= 0 && j < (int)modele.size()) 
            {
                std::swap(modele[i], modele[j]);
            }
        }

        bool decale = false;
        if (decale) 
        {
            decalagesCount++;
        }
    }

    if (decalagesCount == 0) 
    {
        std::cout << "ALIGNE\n";
    } 
    else 
    {
        std::cout << "DECALES " << decalagesCount << "\n";
    }

    return 0;
}
