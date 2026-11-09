#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

enum class Etat { ABSENT, ECRIT, DEFAUT, SUPPRIME };

std::string etatToString(Etat e) 
{
    switch (e) {
        case Etat::ABSENT:   return "ABSENT";
        case Etat::ECRIT:    return "ECRIT";
        case Etat::DEFAUT:   return "DEFAUT";
        case Etat::SUPPRIME: return "SUPPRIME";
    }
    return "ABSENT";
}

int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string className;
    if (!(std::cin >> className)) 
    {
        return 0;
    }

    // Konsommer le reste de la première ligne
    std::string line;
    std::getline(std::cin, line);

    Etat status[5] = { Etat::ABSENT, Etat::ABSENT, Etat::ABSENT, Etat::ABSENT, Etat::ABSENT };

    // Modèles de recherche pour les 5 membres (sans espaces)
    std::string patternDestr = "~" + className + "(";
    std::string patternCopy = className + "(const" + className + "&";
    std::string patternCopyAssign = className + "&operator=(const" + className + "&";
    std::string patternMove = className + "(" + className + "&&";
    std::string patternMoveAssign = className + "&operator=(" + className + "&&";

    while (std::getline(std::cin, line)) 
    {
        // 1. Couper au premier //
        size_t commentPos = line.find("//");
        if (commentPos != std::string::npos) 
        {
            line = line.substr(0, commentPos);
        }

        // 2. Retirer tous les espaces / tabulations / retours chariot
        std::string clean;
        clean.reserve(line.size());
        for (char c : line) {
            if (c != ' ' && c != '\t' && c != '\r' && c != '\n') 
            {
                clean.push_back(c);
            }
        }

        if (clean.empty()) continue;

        // 3. Identifier le membre
        int recognizedIndex = -1;

        if (clean.rfind(patternDestr, 0) == 0) 
        {
            recognizedIndex = 0; // DESTRUCTEUR
        }
        else if (clean.rfind(patternCopyAssign, 0) == 0) {
            // Vérifier qu'il n'y a pas un second '&' après le premier '&'
            size_t pos = patternCopyAssign.size();
            if (pos < clean.size() && clean[pos] != '&') 
            {
                recognizedIndex = 2; // AFFECTATION_COPIE
            }
        }
        else if (clean.rfind(patternCopy, 0) == 0) {
            // Distinguer const C& et const C&&
            size_t pos = patternCopy.size();
            if (pos < clean.size() && clean[pos] != '&') 
            {
                recognizedIndex = 1; // COPIE
            }
        }
        else if (clean.rfind(patternMoveAssign, 0) == 0) 
        {
            recognizedIndex = 4; // AFFECTATION_DEPLACEMENT
        }
        else if (clean.rfind(patternMove, 0) == 0) 
        {
            recognizedIndex = 3; // DEPLACEMENT
        }

        if (recognizedIndex != -1) {
            // 4. Déterminer l'état
            if (clean.size() >= 8 && clean.compare(clean.size() - 8, 8, "=delete;") == 0) 
            {
                status[recognizedIndex] = Etat::SUPPRIME;
            }
            else if (clean.size() >= 9 && clean.compare(clean.size() - 9, 9, "=default;") == 0) 
            {
                status[recognizedIndex] = Etat::DEFAUT;
            }
            else {
                status[recognizedIndex] = Etat::ECRIT;
            }
        }
    }

    // Affichage des 5 lignes d'état
    const std::string names[5] = {
        "DESTRUCTEUR",
        "COPIE",
        "AFFECTATION_COPIE",
        "DEPLACEMENT",
        "AFFECTATION_DEPLACEMENT"
    };

    for (int i = 0; i < 5; ++i) {
        std::cout << names[i] << " " << etatToString(status[i]) << "\n";
    }

    bool decl[5];
    int countDecl = 0;
    for (int i = 0; i < 5; ++i) {
        decl[i] = (status[i] != Etat::ABSENT);
        if (decl[i]) countDecl++;
    }

    // Application de la règle
    std::string regle;
    if (countDecl == 0) 
    {
        regle = "ZERO";
    }
    else if (countDecl == 5) 
    {
        regle = "CINQ";
    }
    else if (decl[0] && decl[1] && decl[2] && !decl[3] && !decl[4]) 
    {
        regle = "TROIS";
    }
    else {
        regle = "INCOMPLETE";
    }

    std::cout << "REGLE " << regle << "\n";

    if (regle == "INCOMPLETE") {
        bool hasMoveDecl = decl[3] || decl[4];
        int limit = hasMoveDecl ? 5 : 3;
        for (int i = 0; i < limit; ++i) {
            if (!decl[i]) {
                std::cout << "MANQUE " << names[i] << "\n";
            }
        }
    }

    // POSSEDE OUI / NON
    bool possede = (status[0] == Etat::ECRIT);
    std::cout << "POSSEDE " << (possede ? "OUI" : "NON") << "\n";

    // UNIQUE OUI / NON
    bool unique = (status[1] == Etat::SUPPRIME) && (status[3] == Etat::ECRIT || status[3] == Etat::DEFAUT);
    std::cout << "UNIQUE " << (unique ? "OUI" : "NON") << "\n";

    return 0;
}
