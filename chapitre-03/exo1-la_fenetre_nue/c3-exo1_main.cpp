#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkEventSystem.h"
#include "NKEvent/NkWindowEvent.h"

using namespace nkentseu;

// Métadonnées de l'application
NKENTSEU_DEFINE_APP_DATA(([]() {
    NkAppData d{};
    d.appName = "La fenetre nue";
    d.appVersion = "1.0.0";
    return d;
})());

int nkmain(const NkEntryState& state) {
    // 1) Configuration de la fenêtre
    NkWindowConfig cfg;
    cfg.title = "La fenetre nue";
    cfg.width = 800;
    cfg.height = 600;

    // 2) Création de la fenêtre
    NkWindow window;
    if (!window.Create(cfg)) {
        return -1;
    }

    // 3) Boucle principale
    while (window.IsOpen()) {
        // Vider toute la file d'événements de la frame
        while (NkEvent* ev = NkEvents().PollEvent()) {
            // Traiter la demande de fermeture (clic sur la croix ou Alt+F4)
            if (ev->Is<NkWindowCloseEvent>()) {
                window.Close();
            }
        }
    }

    return 0;
}
