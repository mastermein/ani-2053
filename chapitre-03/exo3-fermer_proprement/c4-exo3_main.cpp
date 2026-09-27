#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkEventSystem.h"
#include "NKEvent/NkWindowEvent.h"
#include "NKEvent/NkKeyboardEvent.h"
#include <iostream>

using namespace nkentseu;

NKENTSEU_DEFINE_APP_DATA(([]() {
    NkAppData d{};
    d.appName = "Fermer Proprement";
    d.appVersion = "1.0.0";
    return d;
})());

int nkmain(const NkEntryState& state) {
    NkWindowConfig cfg;
    cfg.title = "Fermer proprement";
    cfg.width = 800;
    cfg.height = 600;

    NkWindow window;
    if (!window.Create(cfg)) {
        return -1;
    }

    while (window.IsOpen()) {
        bool shouldClose = false; // Drapeau unique pour demander la fermeture

        while (NkEvent* ev = NkEvents().PollEvent()) {
            
            // 1. Touche Échap pressée -> pose uniquement la demande de fermeture
            if (auto* kp = ev->As<NkKeyPressEvent>()) {
                if (kp->GetKey() == NkKey::NK_ESCAPE) {
                    shouldClose = true;
                }
            }

            // 2. Événement de fermeture système (Croix ou Alt+F4)
            if (ev->Is<NkWindowCloseEvent>()) {
                shouldClose = true;
            }
        }

        // UNIQUE ENDROIT DE FERMETURE :
        // La fenêtre ne se ferme QUE si le drapeau est activé
        if (shouldClose) {
            std::cout << "[LOG] Fermeture unique declenchee pour la fenetre." << std::endl;
            window.Close();
        }
    }

    return 0;
}
