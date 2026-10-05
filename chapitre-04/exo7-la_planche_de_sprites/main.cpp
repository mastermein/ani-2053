#include <iostream>

int main() {
  
    //Lecture de la première ligne de configuration : C R W H F D P
    long long colonnes = 0; // C : nombre de colonnes de la planche
    long long lignes = 0;   // R : nombre de lignes de la planche
    long long w = 0;        // W : largeur d'une case (pixels)
    long long h = 0;        // H : hauteur d'une case (pixels)
    long long nbCases = 1;  // F : nombre de cases de l'animation
    long long duree = 1;    // D : durée d'une case (ms)
    long long plafond = 1;  // P : plafond du temps écoulé (ms)

    if (!(std::cin >> colonnes >> lignes >> w >> h >> nbCases >> duree >> plafond)) 
    {
        return 0;
    }

    //Lecture du nombre d'intervalles N
    int n = 0;
    if (!(std::cin >> n)) 
    {
        return 0;
    }

    // État de l'animation
    long long caseCourante = 0; // L'animation commence sur la case 0
    long long tempsAccumule = 0; // Temps accumulé (ms)
    long long avances = 0;       // Compteur global du nombre de passages de cases
    long long plafonnes = 0;     // Compteur du nombre de dt qui ont été plafonnés

    //Traitement de chaque intervalle dt
    for (int i = 0; i < n; ++i) 
    {
        long long dt = 0;
        if (!(std::cin >> dt)) 
        {
            break;
        }

        //Si dt dépasse le plafond, on le ramène à P et on incrémente le compteur
        if (dt > plafond) 
        {
            dt = plafond;
            ++plafonnes;
        }

        //Ajouter dt au temps accumulé
        tempsAccumule += dt;

        //Calculer combien de cases l'animation doit avancer
        long long pas = tempsAccumule / duree;
        tempsAccumule -= pas * duree; // Retirer la durée consommée sans remettre à zéro

        // Passage à la case suivante avec retour à 0 après la case (F - 1)
        caseCourante = (caseCourante + pas) % nbCases;
        avances += pas;

        // Règle 4 & 5 : Calcul des coordonnées X et Y de la case dans la planche
        long long col = caseCourante % colonnes;
        long long lig = caseCourante / colonnes;
        long long x = col * w;
        long long y = lig * h;

        // Affichage de la ligne : case x y w h
        std::cout << caseCourante << " " << x << " " << y << " " << w << " " << h << "\n";
    }

    // Bilan final
    std::cout << "AVANCES " << avances << "\n";
    std::cout << "PLAFONNES " << plafonnes << "\n";

    return 0;
}
