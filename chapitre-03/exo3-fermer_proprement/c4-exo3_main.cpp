#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkEventSystem.h"
#include "NKEvent/NkWindowEvent.h"
#include "NKEvent/NkKeyboardEvent.h"

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
        while (NkEvent* ev = NkEvents().PollEvent()) {
            
            // 1. Touche Échap pressée -> demande de fermeture
            if (auto* kp = ev->As<NkKeyPressEvent>()) {
                if (kp->GetKey() == NkKey::NK_ESCAPE) {
                    window.Close();
                }
            }

            // 2. Événement de fermeture (Croix système, Alt+F4 ou suite à window.Close())
            if (ev->Is<NkWindowCloseEvent>()) {
                window.Close();
            }
        }
    }

    return 0;
}