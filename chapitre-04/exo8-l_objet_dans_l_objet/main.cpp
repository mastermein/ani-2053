#include <iostream>
#include <string>
#include <map>

// Fonction pour ramener un angle (positif ou négatif) dans l'intervalle [0, 360[
long long normaliserAngle(long long angle) 
{
    long long mod = angle % 360;
    if (mod < 0) 
    {
        mod += 360; // En C++, un modulo négatif (ex: -90 % 360 = -90) devient positif (+360 = 270)
    }
    return mod;
}

// Structure stockant les propriétés calculées d'un objet dans le monde
struct ObjetMonde 
{
    long long x = 0;         // Position X finale dans le monde
    long long y = 0;         // Position Y finale dans le monde
    long long angle = 0;     // Angle cumulé dans le monde [0, 270]
    long long echelle = 1;   // Échelle cumulée dans le monde
    int niveau = 1;          // Profondeur de l'objet dans la hiérarchie
};

int main() 
{
    // Optimisation des entrées/sorties standard C++
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 0;
    if (!(std::cin >> n)) 
    {
        return 0;
    }

    // Dictionnaire pour retrouver chaque objet calculé par son nom
    std::map<std::string, ObjetMonde> dictionnaireObjets;
    int profondeurMaximale = 0;

    for (int i = 0; i < i + 1 && i < n; ++i) 
    { // Traitement de chaque objet
        std::string nom, parent;
        long long tx = 0, ty = 0;
        long long anglePropre = 0;
        long long echellePropre = 1;

        std::cin >> nom >> parent >> tx >> ty >> anglePropre >> echellePropre;

        ObjetMonde obj;
        auto itParent = dictionnaireObjets.find(parent);

        // Cas 1 : Objet sans parent (racine)
        if (parent == "-" || itParent == dictionnaireObjets.end()) 
        {
            obj.x = tx;
            obj.y = ty;
            obj.angle = normaliserAngle(anglePropre);
            obj.echelle = echellePropre;
            obj.niveau = 1;
        } 
        // Cas 2 : Objet attaché à un parent
        else 
        {
            const ObjetMonde& p = itParent->second; // Propriétés du parent dans le monde

            // Règle 2 : Appliquer l'échelle du parent aux coordonnées locales
            long long ax = tx * p.echelle;
            long long ay = ty * p.echelle;

            // Règle 3 : Déterminer cosinus (c) et sinus (s) de l'angle du parent
            long long c = 1, s = 0;
            if (p.angle == 90) 
            {
                c = 0; s = 1;
            } 
            else if (p.angle == 180) 
            {
                c = -1; s = 0;
            }
            else if (p.angle == 270) 
            {
                c = 0; s = -1;
            }

            // Règle 3 et 5 : Rotation et ajout de la position du parent
            obj.x = p.x + (ax * c - ay * s);
            obj.y = p.y + (ax * s + ay * c);

            // Règle 5 et 6 : Calcul de l'angle cumulé, échelle cumulée et niveau
            obj.angle = normaliserAngle(p.angle + anglePropre);
            obj.echelle = p.echelle * echellePropre;
            obj.niveau = p.niveau + 1;
        }

        // Mise à jour de la profondeur maximale observée
        if (obj.niveau > profondeurMaximale) 
        {
            profondeurMaximale = obj.niveau;
        }

        // Sauvegarde de l'objet pour qu'il puisse servir de parent aux objets suivants
        dictionnaireObjets[nom] = obj;

        // Affichage du résultat pour cet objet : nom x y angle echelle
        std::cout << nom << " " << obj.x << " " << obj.y << " " << obj.angle << " " << obj.echelle << "\n";
    }

    // Affichage de la ligne de bilan finale
    std::cout << "PROFONDEUR " << profondeurMaximale << "\n";

    return 0;
}
