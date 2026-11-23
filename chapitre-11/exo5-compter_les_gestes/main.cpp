#include <iostream>
#include <string>

std::string formaterTemps(long long secondes) 
{
    long long minutes = secondes / 60;
    long long reste = secondes % 60;

    std::string texte = std::to_string(minutes) + ":";
    if (reste < 10) 
    {
        texte += "0";  // les secondes s'écrivent sur deux chiffres
    }
    texte += std::to_string(reste);
    return texte;
}

int main() 
{
    // Est-ce qu'une tâche est en cours ? Si oui, on retient ses informations.
    bool tacheEnCours = false;
    std::string nomTache;
    int minGestes = 0;           // nombre de gestes que la tâche demande logiquement
    long long parJour = 0;       // nombre de fois que la tâche revient dans une journée
    long long instantDebut = 0;  // instant du DEBUT
    int gestes = 0;              // gestes comptés depuis le DEBUT
    long long attente = 0;       // total des ATTENTE depuis le DEBUT

    long long totalJourSecondes = 0;  // somme des coûts "JOUR" de toutes les tâches terminées

    // Chaque ligne commence par un instant t, puis une commande.
    long long t = 0;
    std::string commande;
    while (std::cin >> t >> commande) 
    {

        if (commande == "DEBUT") 
        {
            std::string nom;
            int minimum = 0;
            long long parjour = 0;
            std::cin >> nom >> minimum >> parjour;

            // On démarre la tâche et on remet les compteurs à zéro.
            tacheEnCours = true;
            nomTache = nom;
            minGestes = minimum;
            parJour = parjour;
            instantDebut = t;
            gestes = 0;
            attente = 0;

        } 
        else if (commande == "FIN") 
        {
            std::string nom;
            std::cin >> nom;

            if (tacheEnCours) 
            {
                // Gestes en trop : jamais négatif.
                int enTrop = 0;
                if (gestes > minGestes) 
                {
                    enTrop = gestes - minGestes;
                }

                // Durée : seuls les instants du DEBUT et du FIN comptent.
                long long duree = t - instantDebut;

                // Coût de l'attente sur une journée :
                // attente * parJour millisecondes, converties en secondes entières
                // (la division entière arrondit déjà vers le bas).
                long long jourSecondes = attente * parJour / 1000;
                totalJourSecondes += jourSecondes;

                std::cout << nomTache
                          << " GESTES " << gestes
                          << " EN_TROP " << enTrop
                          << " DUREE " << duree
                          << " ATTENTE " << attente
                          << " JOUR " << formaterTemps(jourSecondes) << "\n";

                tacheEnCours = false;
            }

        } 
        else if (commande == "CLIC" || commande == "MOLETTE" || commande == "GLISSE") 
        {
            // Un geste. Hors de toute tâche, on l'ignore.
            if (tacheEnCours) {
                gestes++;
            }

        } 
        else if (commande == "TOUCHE") 
        {
            std::string touche;
            std::cin >> touche;  // on doit lire la touche même si on ignore le geste
            if (tacheEnCours) 
            {
                gestes++;
            }

        } 
        else if (commande == "ATTENTE") 
        {
            long long d = 0;
            std::cin >> d;  // on doit lire la durée même si on ignore l'attente
            if (tacheEnCours) 
            {
                attente += d;  // une attente n'est PAS un geste
            }
        }
    }

    // Si une tâche n'a pas eu de FIN, on l'écrit INACHEVEE,
    // après toutes les tâches terminées (et elle ne compte pas dans le total).
    if (tacheEnCours) 
    {
        std::cout << nomTache << " INACHEVEE\n";
    }

    std::cout << "TOTAL_JOUR " << formaterTemps(totalJourSecondes) << "\n";

    return 0;
}

