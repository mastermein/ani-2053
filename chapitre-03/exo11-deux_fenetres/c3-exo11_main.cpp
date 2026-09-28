#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkWindowEvent.h"
#include "NKEvent/NkKeyboardEvent.h"
#include <iostream>

using namespace nkentseu;

int nkmain(const NkEntryState& state) {
    // Configuration de la première fenêtre (Gauche)
    NkWindowConfig cfgA;
    cfgA.title  = "Vue Gauche";
    cfgA.width  = 500;
    cfgA.height = 350;
    cfgA.x      = 150;
    cfgA.y      = 150;

    // Configuration de la deuxième fenêtre (Droite)
    NkWindowConfig cfgB;
    cfgB.title  = "Vue Droite";
    cfgB.width  = 500;
    cfgB.height = 350;
    cfgB.x      = 700;
    cfgB.y      = 150;

    NkWindow winA(cfgA);
    NkWindow winB(cfgB);

    if (!winA.IsOpen() || !winB.IsOpen()) return -1;

    // Boucle d'événements tant qu'au moins une fenêtre est ouverte
    while (winA.IsOpen() || winB.IsOpen()) {
        while (NkEvent* ev = NkEvents().PollEvent()) {
            
            // 1. Fermeture individuelle des fenêtres
            if (ev->Is<NkWindowCloseEvent>()) {
                if (ev->GetWindowId() == winA.GetId()) {
                    winA.Close();
                    std::cout << "\n Vue Gauche fermee.";
                } else if (ev->GetWindowId() == winB.GetId()) {
                    winB.Close();
                    std::cout << "\n Vue Droite fermee.";
                }
            }
            // 2. Touche ÉCHAP pour fermer les deux fenêtres d'un coup
            else if (auto* kp = ev->As<NkKeyPressEvent>()) {
                if (kp->GetKey() == NkKey::NK_ESCAPE) {
                    winA.Close();
                    winB.Close();
                }
            }
            // 3. Identification du clic selon la fenêtre
            else if (auto* mp = ev->As<NkMouseButtonPressEvent>()) {
                bool isWinA = (ev->GetWindowId() == winA.GetId());
                std::cout << "\n[Clic] " << (isWinA ? "Vue Gauche" : "Vue Droite")
                          << " -> Position: (" << mp->GetX() << ", " << mp->GetY() << ")";
            }
        }
    }

    return 0;
}
