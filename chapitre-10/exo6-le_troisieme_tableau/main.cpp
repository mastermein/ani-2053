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

    std::vector<ImageItem> textures = modele;
    std::vector<ImageItem> sources = modele;

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
            textures.push_back({nom, sourcePath, octets});
            sources.push_back({nom, sourcePath, octets});
        } 
        else if (cmd == "SUPPR") 
        {
            int idx;
            std::cin >> idx;
            if (idx >= 0 && idx < (int)modele.size()) 
            {
                modele.erase(modele.begin() + idx);
            }
            if (idx >= 0 && idx < (int)textures.size()) 
            {
                textures.erase(textures.begin() + idx);
            }
            if (idx >= 0 && idx < (int)sources.size()) 
            {
                sources.erase(sources.begin() + idx);
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
            if (i >= 0 && i < (int)textures.size() && j >= 0 && j < (int)textures.size()) 
            {
                std::swap(textures[i], textures[j]);
            }
            if (i >= 0 && i < (int)sources.size() && j >= 0 && j < (int)sources.size()) 
            {
                std::swap(sources[i], sources[j]);
            }
        }

        for (size_t i = 0; i < modele.size(); ++i) 
        {
            std::cout << i << " " << modele[i].nom << " " << textures[i].nom << " " << sources[i].nom << "\n";
        }

        if (modele.size() != textures.size() || modele.size() != sources.size()) 
        {
            decalagesCount++;
        }
    }

    if (decalagesCount == 0 && modele.size() == textures.size() && modele.size() == sources.size()) 
    {
        std::cout << "ALIGNE\n";
    } else 
    {
        std::cout << "DECALES " << (decalagesCount > 0 ? decalagesCount : 2) << "\n";
    }

    return 0;
}
