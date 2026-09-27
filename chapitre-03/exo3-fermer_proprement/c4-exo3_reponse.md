
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
}`

## principe

 Afin de respecter la consigne exigeant un seul et unique point de fermeture dans tout le programme :

1. **Centralisation par un bool (`shouldClose`)** :
   - L'appui sur la touche **Échap** (`NkKeyPressEvent`) met `shouldClose = true`.
   - L'événement de fermeture système **Croix / Alt+F4** (`NkWindowCloseEvent`) met également `shouldClose = true`.

2. **Point de fermeture unique** :
   La méthode `window.Close()` n'est appelée qu'à **un seul endroit dans tout le fichier**, à la fin du traitement des événements lorsque `shouldClose == true`.



## Trace d'exécution (Preuve de passage)

Chaque type d'action emprunte exactement le même chemin et affiche le même log dans la console :

`[LOG] Fermeture unique declenchee pour la fenetre.`
 
