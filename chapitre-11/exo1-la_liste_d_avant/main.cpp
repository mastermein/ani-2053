#include <iostream>
#include <set>
#include <string>
#include <vector>

std::vector<std::string> lireListe() 
{
    std::string mot;
    int n = 0;
    std::cin >> mot >> n;

    std::vector<std::string> liste;
    for (int i = 0; i < n; i++) 
    {
        std::string cle;
        std::cin >> cle;
        liste.push_back(cle);
    }
    return liste;
}

int main() 
{
    // 1. On lit les trois listes, dans l'ordre de l'énoncé.
    std::vector<std::string> avant = lireListe();
    std::vector<std::string> listeCorrige = lireListe();
    std::vector<std::string> listeApres = lireListe();

    // 2. On range CORRIGE, APRES et AVANT dans des "set".
    
    std::set<std::string> corrige(listeCorrige.begin(), listeCorrige.end());
    std::set<std::string> apres(listeApres.begin(), listeApres.end());
    std::set<std::string> dansAvant(avant.begin(), avant.end());

    // 3. Les compteurs pour le bilan final.
    int vraies = 0;
    int fausses = 0;
    int oubliees = 0;
    int nouvelles = 0;

    // 4. On classe chaque clé de AVANT, dans l'ordre.
    int numero = 1;
    for (const std::string& cle : avant) 
    {
        std::string categorie;

        if (corrige.count(cle) == 1) 
        {
            // Règle 1 : elle est dans CORRIGE.
            categorie = "DEVENUE_FAUSSE";
            fausses++;
        } else if (apres.count(cle) == 1) 
        {
            // Règle 2 : pas corrigée, mais encore dans APRES.
            categorie = "ENCORE_VRAIE";
            vraies++;
        } 
        else 
        {
            // Règle 3 : nulle part ailleurs, donc oubliée.
            categorie = "OUBLIEE";
            oubliees++;
        }

        std::cout << numero << " " << cle << " " << categorie << "\n";
        numero++;
    }

    // 5. Les nouvelles : clés de APRES qui ne sont pas dans AVANT.
    for (const std::string& cle : listeApres) 
    {
        if (dansAvant.count(cle) == 0) 
        {
            nouvelles++;
        }
    }

    // 6. La part oubliée : 100 * oubliees / (vraies + oubliees).

    int part = 0;
    if (vraies + oubliees > 0) 
    {
        part = 100 * oubliees / (vraies + oubliees);
    }

    // 7. Les cinq lignes finales, toujours affichées.
    std::cout << "VRAIES " << vraies << "\n";
    std::cout << "FAUSSES " << fausses << "\n";
    std::cout << "OUBLIEES " << oubliees << "\n";
    std::cout << "NOUVELLES " << nouvelles << "\n";
    std::cout << "PART_OUBLIEE " << part << "\n";

    return 0;
}

