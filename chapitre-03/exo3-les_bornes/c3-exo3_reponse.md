 ## Fixez une taille minimale, puis essayez de réduire la fenêtre en dessous. Retirez-la, recommencez, et notez la plus petite taille que le système accepte.


## Fichier initial `c3-exo3_main.cpp`
 
   * **contenu**
     * `#include "NKWindow/NKWindow.h"
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
    cfg.minWidth = 800;
    cfg.minHeight = 600;

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
}`
   * **remaque**
     * `je peux redimensionner la fenetre autant que je veux`


 ## Fixation des tailles minimales

   * **parselle de code modifier**
     * `NkWindowConfig cfg;
    cfg.title = "La fenetre nue";
    cfg.width = 800;
    cfg.height = 600;
    cfg.minWidth = 800;
    cfg.minHeight = 600;`

   * **remarque**
     * `je peux toujours redimensionner la fenetre , cependant sa hauteur n'arrive plus en dessous de 600px et la largeur n'arrive plus en dessous de 800px`

 ## Retirez-la taille minimale, recommencez, et notez la plus petite taille que le système accepte.

 * **retour au code intitial**

 * **remarque**
  * `en dessous de 60px de hauteur et 60px de largeur la fenetre ne peux plus etre reduite`