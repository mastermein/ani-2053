#include <iostream>
#include <string>
#include <map>
#include <algorithm>

// Structure pour stocker les mesures d'un caractère (ses dimensions et son déplacement)
struct InformationsGlyphe 
{
    long long avanceCurseur; // De combien le curseur s'avance horizontalement après avoir écrit la lettre
    long long coinGauche;    // Position horizontale de début du dessin (x0)
    long long haut;          // Position verticale haute du dessin, négative si ça monte au-dessus de la ligne (y0)
    long long coinDroit;     // Position horizontale de fin du dessin (x1)
    long long bas;           // Position verticale basse du dessin (y1)
};

int main() 
{
    // Désactivation de la synchronisation pour accélérer les entrées/sorties (pratique standard)
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Variable entière pour stocker le nombre total de glyphes disponibles dans la table
    int nombreGlyphes = 0;
    std::cin >> nombreGlyphes;

    // Dictionnaire (map) pour associer chaque caractère (clé) à ses mesures géométriques (valeur)
    std::map<char, InformationsGlyphe> tableGlyphes;

    // Boucle pour lire un par un tous les glyphes de la table
    for (int i = 0; i < nombreGlyphes; ++i) 
    {
        std::string caractereTexte;
        InformationsGlyphe glypheActuel;
        std::cin >> caractereTexte 
                 >> glypheActuel.avanceCurseur 
                 >> glypheActuel.coinGauche 
                 >> glypheActuel.haut 
                 >> glypheActuel.coinDroit 
                 >> glypheActuel.bas;
        
        // On enregistre le glyphe dans le dictionnaire en utilisant le premier caractère de la chaîne
        tableGlyphes[caractereTexte[0]] = glypheActuel;
    }

    // Variable entière pour stocker le nombre de règles de correction d'espacement (crénage)
    int nombreCrenages = 0;
    std::cin >> nombreCrenages;

    // Dictionnaire pour associer une paire de caractères collés (ex: "Ty") à sa valeur de correction
    std::map<std::string, long long> tableCrenage;

    // Boucle pour lire chaque règle de crénage
    for (int i = 0; i < nombreCrenages; ++i) 
    {
        std::string coupleLettres;
        long long valeurCorrection = 0;
        std::cin >> coupleLettres >> valeurCorrection;
        tableCrenage[coupleLettres] = valeurCorrection;
    }

    // Chaîne de caractères représentant le texte à afficher, et coordonnées de départ (origine x et y)
    std::string texteAAfficher;
    long long origineX = 0;
    long long origineY = 0;
    std::cin >> texteAAfficher >> origineX >> origineY;

    // Position horizontale actuelle du curseur, qui commence au point de départ ox
    long long positionCurseurX = origineX;

    // Indicateur booléen pour savoir si au moins un caractère visible a été dessiné
    bool texteDessine = false;

    // Variables pour déterminer la plus petite boîte englobante de tout le texte dessiné
    long long boiteMinX = 0;
    long long boiteMinY = 0;
    long long boiteMaxX = 0;
    long long boiteMaxY = 0;

    // Compteur pour les caractères du texte qui ne se trouvent pas dans la table
    int compteurAbsents = 0;

    // Boucle pour parcourir chaque lettre du texte à afficher, de gauche à droite
    for (size_t index = 0; index < texteAAfficher.size(); ++index) 
    {
        char lettreCourante = texteAAfficher[index];

        // On cherche si le caractère existe dans notre dictionnaire de glyphes
        auto rechercheGlyphe = tableGlyphes.find(lettreCourante);
        if (rechercheGlyphe == tableGlyphes.end()) 
        {
            // Si le caractère est introuvable, on l'indique et on compte un absent de plus
            std::cout << lettreCourante << " ABSENT\n";
            compteurAbsents++;
            continue; // On passe directement au caractère suivant sans avancer le curseur
        }

        // On récupère les mesures du glyphe trouvé
        const InformationsGlyphe &glyphe = rechercheGlyphe->second;

        // Affichage de la position exacte du curseur où ce caractère se pose
        std::cout << lettreCourante << " " << positionCurseurX << "\n";

        // Le caractère est réellement dessiné si sa largeur et sa hauteur sont valides
        if (glyphe.coinDroit > glyphe.coinGauche && glyphe.bas > glyphe.haut) 
        {
            // Calcul des coordonnées du rectangle du glyphe par rapport à l'écran
            long long rectangleGauche = positionCurseurX + glyphe.coinGauche;
            long long rectangleHaut = origineY + glyphe.haut;
            long long rectangleDroit = positionCurseurX + glyphe.coinDroit;
            long long rectangleBas = origineY + glyphe.bas;

            // Si c'est le premier dessin, on initialise la boîte englobante avec ces valeurs
            if (!texteDessine) 
            {
                boiteMinX = rectangleGauche;
                boiteMinY = rectangleHaut;
                boiteMaxX = rectangleDroit;
                boiteMaxY = rectangleBas;
                texteDessine = true;
            } else 
            {
                // Sinon, on élargit la boîte existante pour englober ce nouveau rectangle
                boiteMinX = std::min(boiteMinX, rectangleGauche);
                boiteMinY = std::min(boiteMinY, rectangleHaut);
                boiteMaxX = std::max(boiteMaxX, rectangleDroit);
                boiteMaxY = std::max(boiteMaxY, rectangleBas);
            }
        }

        // On avance le curseur horizontalement de la valeur d'avance du glyphe
        positionCurseurX += glyphe.avanceCurseur;

        // On vérifie s'il y a un crénage à appliquer avec le caractère suivant dans le texte
        if (index + 1 < texteAAfficher.size()) 
        {
            std::string couple;
            couple += lettreCourante;
            couple += texteAAfficher[index + 1];

            auto rechercheCrenage = tableCrenage.find(couple);
            if (rechercheCrenage != tableCrenage.end()) 
            {
                // On applique la correction d'espacement (souvent négative pour rapprocher les lettres)
                positionCurseurX += rechercheCrenage->second;
            }
        }
    }

    // Affichage des bilans finaux requis par la plateforme
    std::cout << "CURSEUR " << positionCurseurX << "\n";

    if (!texteDessine) 
    {
        std::cout << "BOITE AUCUNE\n";
        std::cout << "MONTE 0\n";
        std::cout << "DESCEND 0\n";
        std::cout << "ECRAN RIEN\n";
    } else 
    {
        std::cout << "BOITE " << boiteMinX << " " << boiteMinY << " " << boiteMaxX << " " << boiteMaxY << "\n";
        
        // Calcul de la distance entre la ligne de base et le point le plus haut du texte
        long long hauteurMonte = (boiteMinY < origineY ? origineY - boiteMinY : 0);
        std::cout << "MONTE " << hauteurMonte << "\n";

        // Calcul de la distance entre la ligne de base et le point le plus bas du texte
        long long hauteurDescend = (boiteMaxY > origineY ? boiteMaxY - origineY : 0);
        std::cout << "DESCEND " << hauteurDescend << "\n";

        // Analyse de la position du texte par rapport au haut de l'écran (y = 0)
        if (boiteMaxY <= 0) 
        {
            std::cout << "ECRAN HORS\n";
        } else if (boiteMinY < 0) {
            std::cout << "ECRAN COUPE\n";
        } else {
            std::cout << "ECRAN VISIBLE\n";
        }
    }

    std::cout << "ABSENTS " << compteurAbsents << "\n";

    return 0;
}
