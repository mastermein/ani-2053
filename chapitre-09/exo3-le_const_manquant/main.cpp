#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

struct Method 
{
    std::string name;
    bool is_const;
    int modifies;
    std::vector<std::string> calls;
};

int main() 
{
    // Optimisation des entrees/sorties pour la rapidite
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (!(std::cin >> n)) return 0;

    std::vector<Method> methods(n);
    std::map<std::string, int> name_to_index;

    // 1. Lecture des données de chaque méthode
    for (int i = 0; i < n; ++i) 
    {
        std::string const_str;
        std::cin >> methods[i].name >> const_str >> methods[i].modifies;
        methods[i].is_const = (const_str == "const");
        
        int k;
        std::cin >> k;
        methods[i].calls.resize(k);
        for (int j = 0; j < k; ++j) 
        {
            std::cin >> methods[i].calls[j];
        }
        name_to_index[methods[i].name] = i;
    }

    // Cache pour mémoriser si une méthode peut être const
    std::map<std::string, bool> can_be_const_cache;

    // Fonction récursive pour déterminer si une méthode peut devenir const
    auto check_can_be_const = [&](auto& self, const std::string& mname) -> bool 
  {
        if (can_be_const_cache.count(mname)) return can_be_const_cache[mname];
        
        int idx = name_to_index[mname];
        if (methods[idx].is_const) return true;
        if (methods[idx].modifies == 1) return can_be_const_cache[mname] = false;

        bool possible = true;
        for (const auto& called : methods[idx].calls) 
        {
            if (name_to_index.count(called)) 
            {
                if (!self(self, called)) 
                {
                    possible = false;
                    break;
                }
            }
        }
        return can_be_const_cache[mname] = possible;
    };

    // 2. Détermination de la liste POURRAIT (méthodes non const qui pourraient l'être)
    std::vector<std::string> pourrait;
    for (int i = 0; i < n; ++i) 
    {
        if (!methods[i].is_const)
        {
            if (check_can_be_const(check_can_be_const, methods[i].name)) 
            {
                pourrait.push_back(methods[i].name);
            }
        }
    }

    // 3. Détermination de la liste RACINES (méthodes de POURRAIT dont les appelées sont DÉJÀ const)
    std::vector<std::string> racines;
    for (const auto& mname : pourrait) 
    {
        int idx = name_to_index[mname];
        bool all_called_already_const = true;
        for (const auto& called : methods[idx].calls) 
        {
            if (name_to_index.count(called)) 
            {
                int called_idx = name_to_index[called];
                if (!methods[called_idx].is_const) 
                {
                    all_called_already_const = false;
                    break;
                }
            }
        }
        if (all_called_already_const) 
        {
            racines.push_back(mname);
        }
    }

    // 4. Simulation des PASSES en cascade pour corriger tout le monde
    int passes = 0;
    if (!pourrait.empty()) 
    {
        std::map<std::string, bool> simulated_const;
        for (int i = 0; i < n; ++i)
          {
            simulated_const[methods[i].name] = methods[i].is_const;
        }

        std::vector<std::string> remaining = pourrait;
        while (!remaining.empty()) 
        {
            passes++;
            std::vector<std::string> current_pass_cleared;
            std::vector<std::string> next_remaining;

            for (const auto& mname : remaining) 
            {
                int idx = name_to_index[mname];
                bool ready = true;
                for (const auto& called : methods[idx].calls) 
                {
                    if (name_to_index.count(called)) 
                    {
                        if (!simulated_const[called]) 
                        {
                            ready = false;
                            break;
                        }
                    }
                }
                if (ready)
                {
                    current_pass_cleared.push_back(mname);
                } else 
                {
                    next_remaining.push_back(mname);
                }
            }

            for (const auto& mname : current_pass_cleared) 
            {
                simulated_const[mname] = true;
            }
            remaining = next_remaining;
        }
    }

    // 5. Affichage au format strict exigé
    std::cout << "POURRAIT";
    if (pourrait.empty()) 
    {
        std::cout << " AUCUN";
    } else 
    {
        for (const auto& name : pourrait) 
        {
            std::cout << " " << name;
        }
    }
    std::cout << "\n";

    std::cout << "RACINES";
    if (racines.empty()) 
    {
        std::cout << " AUCUN";
    } else 
    {
        for (const auto& name : racines) 
        {
            std::cout << " " << name;
        }
    }
    std::cout << "\n";

    std::cout << "PASSES " << passes << "\n";

    return 0;
}
