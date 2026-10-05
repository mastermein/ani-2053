#include <iostream>
#include <string>

// Structure contenant le résultat calculé pour une politique de redimensionnement
struct PolitiqueResultat 
{
    std::string nom;
    long long vx = 0; // Coordonnée X du viewport
    long long vy = 0; // Coordonnée Y du viewport
    long long vw = 0; // Largeur du viewport
    long long vh = 0; // Hauteur du viewport
    long long mw = 0; // Largeur du monde visible
    long long mh = 0; // Hauteur du monde visible
};

// Formule d'arrondi à l'entier le plus proche : (2*a + b) / (2*b)
long long arrondi(long long a, long long b) 
{
    return (2 * a + b) / (2 * b);
}

// Fonction de secours quand aucune référence n'est posée (RW = 0, RH = 0)
PolitiqueResultat suivreFenetre(const std::string &nom, long long w, long long h) 
{
    PolitiqueResultat r;
    r.nom = nom;
    r.vx = 0; r.vy = 0;
    r.vw = w; r.vh = h;
    r.mw = w; r.mh = h;
    return r;
}

// Calcul de FIT_LETTERBOX
PolitiqueResultat calculerLetterbox(const std::string &nom, long long w, long long h, long long rw, long long rh) 
{
    PolitiqueResultat r;
    r.nom = nom;
    
    // Comparaison des rapports par multiplication croisée pour éviter les divisions à virgule
    if (w * rh <= h * rw) 
    {
        r.vw = w;
        r.vh = arrondi(rh * w, rw); // Hauteur ajustée
    } 
    else 
    {
        r.vh = h;
        r.vw = arrondi(rw * h, rh); // Largeur ajustée
    }
    
    // Centrage du viewport
    r.vx = (w - r.vw) / 2;
    r.vy = (h - r.vh) / 2;
    r.mw = rw;
    r.mh = rh;
    return r;
}

int main() 
{
    // Optimisation des I/O C++
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long rw = 0, rh = 0; // Taille de référence
    long long aw = 0, ah = 0; // Ancienne taille de fenêtre
    long long w = 1, h = 1;   // Nouvelle taille de fenêtre

    if (!(std::cin >> rw >> rh >> aw >> ah >> w >> h)) 
    {
        return 0;
    }

    bool aReference = (rw > 0 && rh > 0);
    PolitiqueResultat liste[6];

    //FOLLOW_WINDOW
    liste[0] = suivreFenetre("FOLLOW_WINDOW", w, h);

    //STRETCH
    if (aReference) 
    {
        PolitiqueResultat r;
        r.nom = "STRETCH";
        r.vx = 0; r.vy = 0;
        r.vw = w; r.vh = h;
        r.mw = rw; r.mh = rh;
        liste[1] = r;
    } 
    else 
    {
        liste[1] = suivreFenetre("STRETCH", w, h);
    }

    //FIT_LETTERBOX
    if (aReference) 
    {
        liste[2] = calculerLetterbox("FIT_LETTERBOX", w, h, rw, rh);
    } 
    else 
    {
        liste[2] = suivreFenetre("FIT_LETTERBOX", w, h);
    }

    //INTEGER_SCALE
    if (aReference) 
    {
        if (w >= rw && h >= rh) 
        {
            long long kw = w / rw;
            long long kh = h / rh;
            long long k = (kw < kh) ? kw : kh; // Le plus petit agrandissement entier
            
            PolitiqueResultat r;
            r.nom = "INTEGER_SCALE";
            r.vw = rw * k;
            r.vh = rh * k;
            r.vx = (w - r.vw) / 2;
            r.vy = (h - r.vh) / 2;
            r.mw = rw;
            r.mh = rh;
            liste[3] = r;
        } 
        else 
        {
            // Si k = 0, on retombe exactement sur FIT_LETTERBOX
            liste[3] = calculerLetterbox("INTEGER_SCALE", w, h, rw, rh);
        }
    } 
    else 
    {
        liste[3] = suivreFenetre("INTEGER_SCALE", w, h);
    }

    // FIT_CROP
    if (aReference) 
    {
        PolitiqueResultat r;
        r.nom = "FIT_CROP";
        r.vx = 0; r.vy = 0;
        r.vw = w; r.vh = h;
        
        if (w * rh > h * rw) 
        {
            r.mw = rw;
            r.mh = arrondi(rw * h, w); // Monde moins haut
        } else {
            r.mw = arrondi(rh * w, h); // Monde moins large
            r.mh = rh;
        }
        liste[4] = r;
    } 
    else 
    {
        liste[4] = suivreFenetre("FIT_CROP", w, h);
    }

    // MANUAL
    {
        PolitiqueResultat r;
        r.nom = "MANUAL";
        r.vx = 0; r.vy = 0;
        r.vw = aw; r.vh = ah;
        r.mw = aw; r.mh = ah;
        liste[5] = r;
    }

    // --- AFFICHAGE ET CALCUL DES BILANS ---
    int nbBandes = 0;

    for (const PolitiqueResultat &r : liste) 
    {
        std::cout << r.nom << " " << r.vx << " " << r.vy << " " << r.vw << " " << r.vh << " "
                  << r.mw << " " << r.mh << "\n";
        
        //Seul un viewport plus étroit ou plus bas que la fenêtre compte comme bande
        if (r.vw < w || r.vh < h) 
        {
            ++nbBandes;
        }
    }

    // Déformation si une référence existe et que le rapport d'aspect a changé
    bool aDeformation = aReference && (w * rh != h * rw);

    std::cout << "BANDES " << nbBandes << "\n";
    std::cout << "DEFORMATION " << (aDeformation ? "OUI" : "NON") << "\n";

    return 0;
}
