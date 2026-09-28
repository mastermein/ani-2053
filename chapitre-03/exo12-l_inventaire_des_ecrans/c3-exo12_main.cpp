#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkWindowEvent.h"
#include "NKEvent/NkKeyboardEvent.h"
#include <iostream>

using namespace nkentseu;

// Affiche la liste des écrans et marque celui qui contient la fenêtre
void DisplayMonitors(const NkWindow& win) {
    auto monitors = win.EnumerateMonitors();
    auto currentMon = win.GetCurrentMonitor();

    std::cout << "\n--- LISTE DES ECRANS (" << win.GetMonitorCount() << " detecte(s)) ---" << std::endl;

    for (usize i = 0; i < monitors.Size(); ++i) {
        const auto& m = monitors[i];
        bool isCurrent = (m.index == currentMon.index);

        std::cout << "Ecran [" << (i + 1) << "] : " << m.name << std::endl;
        std::cout << "  * Position : (" << m.posX << ", " << m.posY << ")" << std::endl;
        std::cout << "  * Taille   : " << m.width << "x" << m.height << " px" << std::endl;
        std::cout << "  * Echelle  : " << m.dpiScale << "x (" << static_cast<int>(m.dpiScale * 100) << "%)" << std::endl;
        std::cout << "  * Fenetre ici : " << (isCurrent ? "OUI" : "Non") << std::endl;
    }
}

int nkmain(const NkEntryState& state) {
    NkWindowConfig cfg;
    cfg.title  = "Exo12 - Moniteurs";
    cfg.width  = 640;
    cfg.height = 480;

    NkWindow window(cfg);
    if (!window.IsOpen()) return -1;

    // Premier affichage au lancement
    DisplayMonitors(window);

    usize activeMonitorIndex = window.GetCurrentMonitor().index;

    while (window.IsOpen()) {
        while (NkEvent* ev = NkEvents().PollEvent()) {
            
            // 1. Fermeture
            if (ev->Is<NkWindowCloseEvent>()) {
                window.Close();
            }
            // 2. Raccourcis clavier (Echap = Quitter, Espace/I = Actualiser)
            else if (auto* kp = ev->As<NkKeyPressEvent>()) {
                if (kp->GetKey() == NkKey::NK_ESCAPE) {
                    window.Close();
                } else if (kp->GetKey() == NkKey::NK_SPACE || kp->GetKey() == NkKey::NK_I) {
                    DisplayMonitors(window);
                }
            }
            // 3. Changement d'écran lors du déplacement de la fenêtre
            else if (ev->Is<NkWindowMoveEvent>()) {
                auto currentMon = window.GetCurrentMonitor();
                if (currentMon.index != activeMonitorIndex) {
                    activeMonitorIndex = currentMon.index;
                    std::cout << "\n>> Fenetre deplacee sur un autre ecran !";
                    DisplayMonitors(window);
                }
            }
        }
    }

    return 0;
}
