
## Faites que votre fenêtre se ferme sur l'événement de fermeture, et seulement sur lui. Vérifiez que le bouton du système, le raccourci du gestionnaire de fenêtres et votre propre touche passent tous les trois par le même chemin.

## travail 
 `configurer les sorties possibles pour que chacune d'elle declenche l'evenement de fermeture `
  - `alt+f4`
  - `croix de fermeture`
  - `echap`

## version de code utilisee

- `#include "NKWindow/NKWindow.h"
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
}`

## principe

 * `if (kp->GetKey() == NkKey::NK_ESCAPE) {
                    window.Close();
                }` **la touche echap demande la fermeture**

 * `if (ev->Is<NkWindowCloseEvent>()) {
                window.Close();
            }` **Événement de fermeture (Croix système, Alt+F4) declenchent la fermeture**


 
