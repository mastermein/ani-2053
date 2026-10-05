#include <iostream>
#include <string>
#include <algorithm> // Pour std::min et std::max

// Fonction qui ramène n'importe quel angle (positif ou négatif) dans l'intervalle [0, 360[
long long normaliserAngle(long long angle) 
{
    long long mod = angle % 360;
    if (mod < 0) 
    {
        mod += 360; // En C++, -90 % 360 vaut -90. On ajoute 360 pour obtenir 270.
    }
    return mod;
}

int main() 
{

    int n = 0;
    if (!(std::cin >> n)) 
    {
        return 0;
    }

    int totalRefuses = 0; // Compteur des angles non multiples de 90°

    for (int i = 0; i < n; ++i) 
    {
        std::string nom;
        long long w = 0, h = 0;     // Largeur et hauteur du rectangle
        long long px = 0, py = 0;   // Position dans le monde
        long long ox = 0, oy = 0;   // Origine (pivot) en coordonnées locales
        long long sx = 0, sy = 0;   // Échelle sur chaque axe
        long long angleEntree = 0; // Angle en degrés

        std::cin >> nom >> w >> h >> px >> py >> ox >> oy >> sx >> sy >> angleEntree;

        // Normalisation de l'angle
        long long angleNorm = normaliserAngle(angleEntree);

        // Vérification : seul un multiple de 90° est accepté
        if (angleNorm % 90 != 0) 
        {
            std::cout << nom << " ANGLE REFUSE\n";
            totalRefuses++;
            continue;
        }

        //Détermination du cosinus (c) et sinus (s) pour les angles multiples de 90°
        long long c = 0, s = 0;
        if (angleNorm == 0) 
        {
            c = 1; s = 0;
        } else if (angleNorm == 90) 
        {
            c = 0; s = 1;
        } else if (angleNorm == 180) 
        {
            c = -1; s = 0;
        } else if (angleNorm == 270) 
        {
            c = 0; s = -1;
        }

        // Définition des 4 coins locaux : Haut-Gauche, Haut-Droit, Bas-Droit, Bas-Gauche
        long long localX[4] = {0, w, w, 0};
        long long localY[4] = {0, 0, h, h};

        long long worldX[4];
        long long worldY[4];

        // Calcul des coordonnées de chaque coin dans le monde
        for (int k = 0; k < 4; ++k) {
            // Étape A : Soustraire l'origine puis appliquer l'échelle
            long long ax = (localX[k] - ox) * sx;
            long long ay = (localY[k] - oy) * sy;

            // Étape B : Rotation (L'axe Y descend vers le bas, angle positif = sens horaire)
            long long rx = ax * c - ay * s;
            long long ry = ax * s + ay * c;

            // Étape C : Ajouter la position dans le monde
            worldX[k] = px + rx;
            worldY[k] = py + ry;
        }

        // Affichage des 4 coins calculés
        std::cout << nom << " COINS "
                  << worldX[0] << " " << worldY[0] << " "
                  << worldX[1] << " " << worldY[1] << " "
                  << worldX[2] << " " << worldY[2] << " "
                  << worldX[3] << " " << worldY[3] << "\n";

        // Calcul de la boîte englobante (AABB) à partir des 4 coins dans le monde
        long long minX = std::min({worldX[0], worldX[1], worldX[2], worldX[3]});
        long long maxX = std::max({worldX[0], worldX[1], worldX[2], worldX[3]});
        long long minY = std::min({worldY[0], worldY[1], worldY[2], worldY[3]});
        long long maxY = std::max({worldY[0], worldY[1], worldY[2], worldY[3]});

        std::cout << nom << " BOITE " << minX << " " << minY << " " << maxX << " " << maxY << "\n";
    }

    // Bilan final
    std::cout << "REFUSES " << totalRefuses << "\n";

    return 0;
}
