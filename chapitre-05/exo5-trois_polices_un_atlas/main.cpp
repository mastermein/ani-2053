#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Structure pour enregistrer les informations d'un groupe de glyphes d'une police
struct GroupeGlyphes 
{
    std::string nomPolice;       // Le nom de la police et sa taille
    long long nombreGlyphes;     // Le nombre de lettres/glyphes dans ce groupe
    long long largeurGlyphe;     // La largeur d'un glyphe en pixels
    long long hauteurGlyphe;     // La hauteur d'un glyphe en pixels
};

// Structure pour stocker la position du premier et du dernier glyphe d'un groupe dans l'atlas
struct CoordonneesPlace 
{
    long long x1;
    long long y1;
    long long x2;
    long long y2;
};

// Fonction pour essayer de ranger tous les glyphes dans une texture de dimensions donnees
bool tenterRangementTexture(const std::vector<GroupeGlyphes> &listeGroupes, long long marge, long long largeurTexture, long long hauteurTexture, std::vector<CoordonneesPlace> &listePlaces) 
{
    // On prepare le tableau des places avec des valeurs de depart a zero
    listePlaces.assign(listeGroupes.size(), CoordonneesPlace{0, 0, 0, 0});
    
    // Le curseur commence au niveau de la marge, et l'etagere commence a une hauteur de zero
    long long curseurX = marge;
    long long curseurY = marge;
    long long hauteurEtagere = 0;

    // On parcourt chaque groupe de glyphes un par un
    for (size_t indiceGroupe = 0; indiceGroupe < listeGroupes.size(); ++indiceGroupe) 
    {
        // On place chaque glyphe du groupe dans la texture
        for (long long k = 0; k < listeGroupes[indiceGroupe].nombreGlyphes; ++k) 
        {
            // Taille totale du glyphe en comptant la marge autour
            const long long largeurAvecMarge = listeGroupes[indiceGroupe].largeurGlyphe + marge;
            const long long hauteurAvecMarge = listeGroupes[indiceGroupe].hauteurGlyphe + marge;

            // Si on depasse sur la droite de la texture, on passe a l'etagere du dessous
            if (curseurX + largeurAvecMarge > largeurTexture - marge) 
            {
                curseurX = marge;
                curseurY = curseurY + hauteurEtagere + marge;
                hauteurEtagere = 0;
                // Si meme sur la nouvelle etagere cela depasse en largeur, l'essai echoue
                if (curseurX + largeurAvecMarge > largeurTexture - marge) 
                {
                    return false;
                }
            }

            // Si on depasse en bas de la texture, l'essai echoue
            if (curseurY + hauteurAvecMarge > hauteurTexture - marge) 
            {
                return false;
            }

            // Si c'est le tout premier glyphe du groupe, on note sa position de debut (x1, y1)
            if (k == 0) 
            {
                listePlaces[indiceGroupe].x1 = curseurX;
                listePlaces[indiceGroupe].y1 = curseurY;
            }

            // On met toujours a jour la position du dernier glyphe pose (x2, y2)
            listePlaces[indiceGroupe].x2 = curseurX;
            listePlaces[indiceGroupe].y2 = curseurY;

            // On avance le curseur vers la droite pour le prochain glyphe
            curseurX += largeurAvecMarge;
            // On retient la plus grande hauteur de l'etagere courante
            hauteurEtagere = std::max(hauteurEtagere, hauteurAvecMarge);
        }
    }
    
    // Si la boucle se termine sans encombre, c'est que tout a tenu !
    return true;
}

int main() 
{
    // Variables pour lire la marge, la largeur voulue et le nombre de groupes
    long long marge = 0;
    long long largeurVoulue = 0;
    int nombreGroupes = 0;

    std::cin >> marge >> largeurVoulue >> nombreGroupes;

    // Lecture de tous les groupes de glyphes depuis l'entree standard
    std::vector<GroupeGlyphes> listeGroupes;
    for (int i = 0; i < nombreGroupes; ++i) 
    {
        GroupeGlyphes unGroupe;
        std::cin >> unGroupe.nomPolice >> unGroupe.nombreGlyphes >> unGroupe.largeurGlyphe >> unGroupe.hauteurGlyphe;
        listeGroupes.push_back(unGroupe);
    }

    // Si aucun groupe n'est fourni, on affiche "AUCUN" et on s'arrete
    if (listeGroupes.empty()) 
    {
        std::cout << "AUCUN\n";
        return 0;
    }

    // Determination de la largeur de depart de la texture
    long long largeurTexture = largeurVoulue;
    if (largeurVoulue == 0) 
    {
        largeurTexture = 512;
        long long besoinTotal = 0;
        // On calcule la place necessaire pour tous les glyphes
        for (const GroupeGlyphes &g : listeGroupes) 
        {
            besoinTotal += g.nombreGlyphes * (g.largeurGlyphe + marge) * (g.hauteurGlyphe + marge);
        }
        // On double la largeur tant que la surface est trop petite et sous la limite de 4096 pixels
        while (largeurTexture * largeurTexture < 2 * besoinTotal && largeurTexture < 4096) {
            largeurTexture *= 2;
        }
    }
    
    // Par defaut, la hauteur de depart est egale a la largeur
    long long hauteurTexture = largeurTexture;

    std::vector<CoordonneesPlace> listePlaces;
    int tentativeReussie = 0;

    // On teste le rangement avec un maximum de 8 essais, en agrandissant la texture si besoin
    for (int tentative = 1; tentative <= 8; ++tentative) 
    {
        if (tenterRangementTexture(listeGroupes, marge, largeurTexture, hauteurTexture, listePlaces)) 
        {
            tentativeReussie = tentative;
            break; // Tout tient, on arrete de chercher
        }
        // Si l'essai echoue, on agrandit la texture selon les regles
        if (largeurTexture == hauteurTexture) 
        {
            largeurTexture *= 2;
        } else 
        {
            hauteurTexture = largeurTexture;
        }
    }

    // Si au bout de 8 essais rien n'a fonctionne, on affiche l'echec
    if (tentativeReussie == 0) 
    {
        std::cout << "ESSAIS 8\n";
        std::cout << "ECHEC\n";
        return 0;
    }

    // Calcul de la surface occupee par les dessins et du pourcentage perdu
    long long surfaceOccupee = 0;
    for (const GroupeGlyphes &g : listeGroupes) 
    {
        surfaceOccupee += g.nombreGlyphes * g.largeurGlyphe * g.hauteurGlyphe;
    }
    const long long surfaceTotale = largeurTexture * hauteurTexture;
    const long long pourcentagePerdu = (surfaceTotale - surfaceOccupee) * 100 / surfaceTotale;

    // Affichage des resultats finaux dans l'ordre strict demande par la plateforme
    std::cout << "ESSAIS " << tentativeReussie << "\n";
    std::cout << "TEXTURE " << largeurTexture << " " << hauteurTexture << "\n";
    for (size_t i = 0; i < listeGroupes.size(); ++i) 
    {
        std::cout << listeGroupes[i].nomPolice << " " 
                  << listePlaces[i].x1 << " " << listePlaces[i].y1 << " "
                  << listePlaces[i].x2 << " " << listePlaces[i].y2 << "\n";
    }
    std::cout << "OCCUPE " << surfaceOccupee << "\n";
    std::cout << "PERDU " << pourcentagePerdu << "\n";

    return 0;
}
