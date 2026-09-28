## Ouvrez deux fenêtres et affichez, pour chaque clic, laquelle l'a reçu. Dites ensuite ce qui vous manquerait pour dessiner dans les deux.

## code global

`#include "NKWindow/NKWindow.h"
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
                    std::cout << "\n[Fermeture] Vue Gauche fermee.";
                } else if (ev->GetWindowId() == winB.GetId()) {
                    winB.Close();
                    std::cout << "\n[Fermeture] Vue Droite fermee.";
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
}`

## config des fenetres
 * **fenetre A**
   * `NkWindowConfig cfgA;
    cfgA.title  = "Vue Gauche";
    cfgA.width  = 500;
    cfgA.height = 350;
    cfgA.x      = 150;
    cfgA.y      = 150;`
 * **fenetre B**
   * `NkWindowConfig cfgB;
    cfgB.title  = "Vue Droite";
    cfgB.width  = 500;
    cfgB.height = 350;
    cfgB.x      = 700;
    cfgB.y      = 150;`
* **Ces blocs préparent les paramètres d'initialisation pour chaque fenêtre. On y définit leur titre, leur taille (largeur/hauteur) ainsi que leur emplacement initial sur l'écran.**

## affichage des fenetres 

* `NkWindow winA(cfgA);
    NkWindow winB(cfgB);
  if (!winA.IsOpen() || !winB.IsOpen()) return -1;`
* **Ces lignes créent et affichent réellement les deux fenêtres à l'écran en leur appliquant les réglages cfgA et cfgB. La condition if s'assure que les deux fenêtres ont bien réussi à s'ouvrir avant de continuer le programme.**

  ## Fermeture individuelle des fenêtres

   * **fermeture individul**
     * `if (ev->Is<NkWindowCloseEvent>()) {
                if (ev->GetWindowId() == winA.GetId()) {
                    winA.Close();
                    std::cout << "\n Vue Gauche fermee.";
                } else if (ev->GetWindowId() == winB.GetId()) {
                    winB.Close();
                    std::cout << "\n Vue Droite fermee.";
                }`
       * **Lorsqu'on clique sur la croix d'une fenêtre, le système identifie l'identifiant (GetWindowId()) de la fenêtre concernée et ne ferme que celle-ci via Close().**


   * **fermeture collective via `ESCAPE`
     * `else if (auto* kp = ev->As<NkKeyPressEvent>()) {
                if (kp->GetKey() == NkKey::NK_ESCAPE) {
                    winA.Close();
                    winB.Close();
                }`
       * **Si l'utilisateur appuie sur la touche ÉCHAP, l'instruction winA.Close() et winB.Close() ferme les deux fenêtres simultanément.**

    ## Identification du clic selon la fenêtre

    * `else if (auto* mp = ev->As<NkMouseButtonPressEvent>()) {
                bool isWinA = (ev->GetWindowId() == winA.GetId());
                std::cout << "\n[Clic] " << (isWinA ? "Vue Gauche" : "Vue Droite")
                          << " -> Position: (" << mp->GetX() << ", " << mp->GetY() << ")";
            }`

      * **Lorsqu'un clic de souris survient, ce bloc compare l'identifiant de la fenêtre ayant reçu l'événement (ev->GetWindowId()) avec celui de la première fenêtre (winA.GetId()). Si l'identifiant correspond, c'est la fenêtre de gauche qui a été cliquée ; sinon, c'est celle de droite. Il affiche ensuite le nom de la fenêtre ainsi que les coordonnées $(X, Y)$ relatives du clic.**
     
    ## ce qui me manquerais pour dessiner dans les deux.

   * **cycle de rafraîchissement (Clear, Draw, Present)**
   * **Une API graphique (comme SDL_Renderer, OpenGL ou Vulkan) rattachée aux fenêtres pour gérer les buffers d'affichage.**

  


