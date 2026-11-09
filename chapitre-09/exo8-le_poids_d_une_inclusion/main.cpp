#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

int main() 
{
    // Optimisation des entrées/sorties
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (!(std::cin >> n)) return 0;

    std::vector<std::string> all_files(n);
    std::set<std::string> file_set;
    std::map<std::string, std::vector<std::string>> inverse_graph; // Qui inclut quoi (inversé)
    std::set<std::string> cpp_files;
    std::set<std::string> h_files;

    // 1. Lecture des fichiers et construction du graphe inversé
    for (int i = 0; i < n; ++i) 
    {
        std::string file;
        int k;
        std::cin >> file >> k;
        all_files[i] = file;
        file_set.insert(file);

        if (file.size() >= 4 && file.compare(file.size() - 4, 4, ".cpp") == 0) 
        {
            cpp_files.insert(file);
        } else if (file.size() >= 2 && file.compare(file.size() - 2, 2, ".h") == 0) 
        {
            h_files.insert(file);
        }

        for (int j = 0; j < k; ++j) 
        {
            std::string inc;
            std::cin >> inc;
            // On ne garde que les inclusions qui font partie de la liste connue
            inverse_graph[inc].push_back(file);
        }
    }

    // Fonction pour calculer combien de .cpp sont impactés si un fichier change
    auto get_recompiled_cpp_count = [&](const std::string& start_file) 
    {
        std::set<std::string> visited;
        std::queue<std::string> q;

        q.push(start_file);
        visited.insert(start_file);

        int cpp_count = 0;
        // Si le fichier de départ est lui-même un .cpp, il se recompile
        if (cpp_files.count(start_file)) 
        {
            cpp_count++;
        }

        while (!q.empty()) 
        {
            std::string curr = q.front();
            q.pop();

            // Parcourir tous les fichiers qui incluent 'curr'
            if (inverse_graph.count(curr)) {
                for (const auto& parent : inverse_graph[curr]) 
                {
                    if (!visited.count(parent)) 
                    {
                        visited.insert(parent);
                        q.push(parent);
                        if (cpp_files.count(parent)) 
                        {
                            cpp_count++;
                        }
                    }
                }
            }
        }
        return cpp_count;
    };

    // 2. Lecture des questions
    int q_count;
    if (!(std::cin >> q_count)) return 0;

    std::vector<int> answers(q_count);
    for (int i = 0; i < q_count; ++i) 
    {
        std::string target;
        std::cin >> target;
        answers[i] = get_recompiled_cpp_count(target);
    }

    // 3. Recherche du PLUS_LOURD parmi les .h
    std::string heaviest_h = "AUCUN";
    int max_impact = -1;

    for (const auto& file : all_files) 
    {
        if (h_files.count(file)) 
        {
            int impact = get_recompiled_cpp_count(file);
            if (impact > max_impact) 
            {
                max_impact = impact;
                heaviest_h = file;
            }
        }
    }

    // 4. Affichage du résultat au format strict
    for (int ans : answers) 
    {
        std::cout << ans << "\n";
    }

    std::cout << "PLUS_LOURD " << heaviest_h;
    if (max_impact != -1) 
    {
        std::cout << " " << max_impact;
    }
    std::cout << "\n";

    return 0;
}
