#include <iostream>
#include <string>

int main() 
{
 
    long long vitesse = 0; // v : vitesse du carré en pixels par image
    int nbImages = 0;     // n : nombre d'images à simuler

    if (!(std::cin >> vitesse >> nbImages)) 
    {
        return 0;
    }

    // État courant des touches (true = enfoncée, false = relâchée)
    bool toucheEspace = false;
    bool toucheGauche = false;
    bool toucheDroite = false;

    // Positions des deux carrés
    long long posXEvenement = 0;     // xe : position gérée par événements
    long long posXInterrogation = 0; // xi : position gérée par interrogation

    // Compteurs globaux pour le bilan
    long long sautsEvenements = 0;
    long long sautsInterrogation = 0;
    long long appuisManques = 0;

    // Boucle sur chaque image (de 1 à n)
    for (int image = 1; image <= nbImages; ++image) 
    {
        int k = 0; // Nombre d'événements pour cette image
        if (!(std::cin >> k)) 
        {
            break;
        }

        long long nbAppuisEspaceImage = 0; // Compte les +SPACE reçus durant cette image

        //LECTURE ET TRAITEMENT DES ÉVÉNEMENTS DE L'IMAGE
        for (int j = 0; j < k; ++j) 
        {
            std::string evt;
            std::cin >> evt;

            if (evt.size() < 2) 
            {
                continue; // Ignore les entrées invalides
            }

            bool estEnfonce = (evt[0] == '+'); // '+' = enfoncée, '-' = relâchée
            std::string nomTouche = evt.substr(1);

            // Traitement selon la touche
            if (nomTouche == "SPACE") 
            {
                toucheEspace = estEnfonce;
                if (estEnfonce) 
                {
                    ++sautsEvenements;         // Chaque +SPACE déclenche un saut
                    ++nbAppuisEspaceImage;     // Suivi pour le calcul des appuis manqués
                }
            } 
            else if (nomTouche == "RIGHT") 
            {
                toucheDroite = estEnfonce;
                if (estEnfonce) 
                {
                    posXEvenement += vitesse; //Chaque +RIGHT avance le carré
                }
            } 
            else if (nomTouche == "LEFT") 
            {
                toucheGauche = estEnfonce;
                if (estEnfonce) 
                {
                    posXEvenement -= vitesse; // Chaque +LEFT recule le carré
                }
            }
        }

        //LOGIQUE PAR INTERROGATION (après avoir lu tous les événements de l'image)
        if (toucheEspace) 
        {
            ++sautsInterrogation; //Si SPACE est enfoncée à la fin, compte un saut
        }
        else 
        {
            //Si +SPACE a eu lieu mais que SPACE n'est plus enfoncée, l'interrogation l'a manqué
            appuisManques += nbAppuisEspaceImage;
        }

        if (toucheDroite) 
        {
            posXInterrogation += vitesse; //Si RIGHT est enfoncée, ajoute v à xi
        }
        if (toucheGauche) 
        {
            posXInterrogation -= vitesse; //Si LEFT est enfoncée, retire v à xi
        }

        //AFFICHAGE DE LA LIGNE POUR CETTE IMAGE
        std::cout << image << " " << posXEvenement << " " << posXInterrogation << "\n";
    }

    //BILAN FINAL (3 LIGNES)
    std::cout << "SAUTS EVENEMENTS " << sautsEvenements << "\n";
    std::cout << "SAUTS INTERROGATION " << sautsInterrogation << "\n";
    std::cout << "MANQUES " << appuisManques << "\n";

    return 0;
}
