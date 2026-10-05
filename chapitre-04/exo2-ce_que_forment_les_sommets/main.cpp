
#include <iostream>
#include <string>

int main() {

    int n = 0;
    if (!(std::cin >> n)) 
    {
        return 0; // Quitter si la lecture échoue ou si l'entrée est vide
    }

    // Compteurs pour le bilan final
    long long totalPoints = 0;
    long long totalSegments = 0;
    long long totalTriangles = 0;
    long long totalRefuses = 0;

    // Traitement de chaque ligne
    for (int i = 0; i < n; ++i) 
    {
        std::string type;
        long long s = 0;
        std::cin >> type >> s;

        // Un nombre négatif de sommets est ramené à 0
        if (s < 0) 
        {
            s = 0;
        }

        // POINTS
        if (type == "POINTS") 
        {
            long long count = s;
            long long reste = 0;
            std::cout << type << " " << s << " " << count << " POINTS " << reste << "\n";
            totalPoints += count;
        }
        //LINES (Segments indépendants)
        else if (type == "LINES") 
        {
            long long count = s / 2;
            long long reste = s % 2;
            std::cout << type << " " << s << " " << count << " SEGMENTS " << reste << "\n";
            totalSegments += count;
        }
        // LINE_STRIP (Ligne brisée continue)
        else if (type == "LINE_STRIP") 
        {
            long long count = (s >= 2) ? (s - 1) : 0;
            long long reste = (s >= 2) ? 0 : s;
            std::cout << type << " " << s << " " << count << " SEGMENTS " << reste << "\n";
            totalSegments += count;
        }
        // TRIANGLES (Triangles indépendants)
        else if (type == "TRIANGLES")
        {
            long long count = s / 3;
            long long reste = s % 3;
            std::cout << type << " " << s << " " << count << " TRIANGLES " << reste << "\n";
            totalTriangles += count;
        }

        else if (type == "TRIANGLE_STRIP" || type == "TRIANGLE_FAN") 
        {
            long long count = (s >= 3) ? (s - 2) : 0;
            long long reste = (s >= 3) ? 0 : s;
            std::cout << type << " " << s << " " << count << " TRIANGLES " << reste << "\n";
            totalTriangles += count;
        }
        // TYPES REFUSÉS (ex: QUADS, minuscules ou mots inconnus)
        else 
        {
            std::cout << type << " " << s << " REFUSE\n";
            totalRefuses++;
        }
    }

    // BILAN FINAL
    std::cout << "POINTS " << totalPoints << "\n";
    std::cout << "SEGMENTS " << totalSegments << "\n";
    std::cout << "TRIANGLES " << totalTriangles << "\n";
    std::cout << "REFUSES " << totalRefuses << "\n";

    return 0;
}
