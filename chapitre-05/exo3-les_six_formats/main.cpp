#include <iostream>
#include <string>

// Structure pour stocker les proprietes d'un format d'image (nom, taille en octets, et options)
struct CaracteristiquesFormat 
{
    const char *nomFormat;       // Le nom du format sous forme de texte
    long long octetsParPixel;    // Le nombre d'octets occupes par un seul pixel
    bool possedeCouleur;         // Vrai si le format gere la couleur, faux sinon
    bool possedeTransparence;    // Vrai si le format gere la transparence, faux sinon
    bool possedeFlottants;       // Vrai si le format utilise des nombres flottants, faux sinon
};

// Tableau constant qui repertorie les six formats autorises et leurs caracteristiques
const CaracteristiquesFormat tableFormats[] = 
{
    {"GRAY8", 1, false, false, false},
    {"GRAY_A16", 2, false, true, false},
    {"RGB24", 3, true, false, false},
    {"RGBA32", 4, true, true, false},
    {"RGB96F", 12, true, false, true},
    {"RGBA128F", 16, true, true, true},
};

// Fonction pour rechercher un format dans notre tableau en comparant son nom
const CaracteristiquesFormat* chercherFormat(const std::string &nomRecherche) 
{
    // On parcourt les 6 formats un par un pour trouver une correspondance exacte
    for (int i = 0; i < 6; ++i) 
    {
        if (nomRecherche == tableFormats[i].nomFormat) 
        {
            return &tableFormats[i]; // On retourne l'adresse du format trouve
        }
    }
    return nullptr; // Si le format n'existe pas dans la table, on retourne un pointeur vide
}

int main() 
{
    // Variables entieres sur 64 bits pour stocker la largeur et la hauteur de l'image
    long long largeur = 0;
    long long hauteur = 0;
    
    // Variable pour stocker le nombre de lignes de conversion a tester
    int nombreConversions = 0;

    // Lecture des dimensions et du nombre de tests depuis l'entree standard
    std::cin >> largeur >> hauteur >> nombreConversions;

    // Calcul du nombre total de pixels (utilise 64 bits pour eviter les depassements de memoire)
    const long long nombreTotalPixels = largeur * hauteur;

    // Variables pour les totaux et compteurs du bilan final
    long long memoireTotale = 0;
    int compteurSansPerte = 0;
    int compteurRefuses = 0;

    // Boucle principale pour traiter chaque conversion demandee une par une
    for (int i = 0; i < nombreConversions; ++i) 
    {
        std::string formatSource;
        std::string formatCible;
        std::cin >> formatSource >> formatCible;

        // Recuperation des caracteristiques des deux formats (depart et arrivee)
        const CaracteristiquesFormat *infoSource = chercherFormat(formatSource);
        const CaracteristiquesFormat *infoCible = chercherFormat(formatCible);

        // Si l'un des deux formats est inconnu, on refuse la ligne
        if (infoSource == nullptr || infoCible == nullptr) 
        {
            std::cout << formatSource << " " << formatCible << " REFUSE\n";
            compteurRefuses++;
            continue; // On passe directement au tour de boucle suivant
        }

        // Calcul de la memoire occupee par l'image source et l'image cible (en octets)
        const long long memoireSource = nombreTotalPixels * infoSource->octetsParPixel;
        const long long memoireCible = nombreTotalPixels * infoCible->octetsParPixel;

        // Chaine de caracteres pour stocker les pertes enumerees lors de la conversion
        std::string pertesDetectees = "";

        // Regle 1 : Verification de la perte de transparence
        if (infoSource->possedeTransparence && !infoCible->possedeTransparence) 
        {
            pertesDetectees = "TRANSPARENCE";
        }

        // Regle 2 : Verification de la perte de couleur
        if (infoSource->possedeCouleur && !infoCible->possedeCouleur) 
        {
            if (pertesDetectees != "") 
            {
                pertesDetectees = pertesDetectees + "+";
            }
            pertesDetectees = pertesDetectees + "COULEUR";
        }

        // Regle 3 : Verification de la perte des nombres flottants (etendue)
        if (infoSource->possedeFlottants && !infoCible->possedeFlottants) 
        {
            if (pertesDetectees != "") 
            {
                pertesDetectees = pertesDetectees + "+";
            }
            pertesDetectees = pertesDetectees + "ETENDUE";
        }

        // Si aucune perte n'a ete trouvee, la conversion est parfaite ("AUCUNE")
        if (pertesDetectees == "") 
        {
            pertesDetectees = "AUCUNE";
            compteurSansPerte++;
        }

        // On additionne la memoire de la cible au total general
        memoireTotale = memoireTotale + memoireCible;

        // Affichage du resultat de cette conversion precise
        std::cout << formatSource << " " << formatCible << " " << memoireSource << " " << memoireCible << " " << pertesDetectees << "\n";
    }

    // Affichage du bilan final obligatoire exigé par l'exercice
    std::cout << "TOTAL " << memoireTotale << "\n";
    std::cout << "SANS_PERTE " << compteurSansPerte << "\n";
    std::cout << "REFUSES " << compteurRefuses << "\n";

    return 0;
}
