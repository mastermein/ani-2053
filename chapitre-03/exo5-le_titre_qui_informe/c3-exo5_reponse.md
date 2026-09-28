## Affichez dans le titre l'état de votre programme : le nom du document, un astérisque s'il est modifié, et la taille courante de la fenêtre. Mettez-le à jour au bon moment, pas à chaque image.

## code 

`#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkKeyboardEvent.h"
#include "NKEvent/NkWindowEvent.h"
#include <iostream>
#include <string>

using namespace nkentseu;

// Fonction de mise à jour du titre
void UpdateTitle(NkWindow& win, const std::string& name, bool modified) {
    auto size = win.GetSize(); // Récupère la taille (largeur, hauteur)
    std::string title = name + (modified ? " *" : "") + " - (" + std::to_string(size.x) + "x" + std::to_string(size.y) + ")";
    win.SetTitle(title.c_str()); // Applique le titre
}

int nkmain(const NkEntryState& state) {
    NkWindowConfig cfg;
    cfg.width = 800;
    cfg.height = 600;

    NkWindow window(cfg);
    if (!window.IsOpen()) return -1; // Quitte si la fenêtre ne s'ouvre pas

    std::string docName = "exo_5.docx";
    bool isModified = false;

    // Titre initial au démarrage
    UpdateTitle(window, docName, isModified);

    // Boucle d'événements
    while (window.IsOpen()) {
        while (NkEvent* ev = NkEvents().PollEvent()) {
            
            // 1. Fermeture de la fenêtre
            if (ev->Is<NkWindowCloseEvent>()) {
                window.Close();
            }
            // 2. Touches du clavier (M, S, ECHAP)
            else if (auto* kp = ev->As<NkKeyPressEvent>()) {
                if (kp->GetKey() == NkKey::NK_ESCAPE) {
                    window.Close();
                } 
                else if (kp->GetKey() == NkKey::NK_M && !isModified) {
                    isModified = true; // Marquer comme modifié
                    UpdateTitle(window, docName, isModified);
                } 
                else if (kp->GetKey() == NkKey::NK_S && isModified) {
                    isModified = false; // Marquer comme sauvegardé
                    UpdateTitle(window, docName, isModified);
                }
            }
            // 3. Redimensionnement
            else if (ev->Is<NkWindowResizeEvent>()) {
                UpdateTitle(window, docName, isModified);
            }
        }
    }

    return 0;
}`

## fonctionnalites

1. Récupération des dimensions et formatage du titre (UpdateTitle):   

* **code**
  * `auto size = win.GetSize();
std::string title = name + (modified ? " *" : "") + " - (" + std::to_string(size.x) + "x" + std::to_string(size.y) + ")";
win.SetTitle(title.c_str());`

2. Détection de l'événement de redimensionnement (NkWindowResizeEvent) :

* **code**
  * `else if (ev->Is<NkWindowResizeEvent>()) {
    UpdateTitle(window, docName, isModified);
}`
* **GetSize() extrait la largeur (size.x) et la hauteur (size.y) de la fenêtre. Ces valeurs sont converties en texte avec std::to_string() puis assemblées avec le nom du document pour former la chaîne finale (ex: exo_5.docx - (800x600)), qui est ensuite appliquée via SetTitle().**
    
3. indicateur de modification (*) 
* **code**
  * `else if (kp->GetKey() == NkKey::NK_M && !isModified) {
    isModified = true;
    UpdateTitle(window, docName, isModified);
}`
* **Lorsque l'utilisateur appuie sur la touche M et que le document n'est pas encore marqué comme modifié (!isModified), la variable passe à true. L'appel à UpdateTitle intègre l'astérisque  * juste après le nom du fichier.**

4. Simulation de l'enregistrement avec la touche 'S' :
 * **code**
   * `else if (kp->GetKey() == NkKey::NK_S && isModified) {
    isModified = false;
    UpdateTitle(window, docName, isModified);
}` 
* **Lorsque l'utilisateur appuie sur la touche S (Sauvegarder) et que le document était modifié (isModified), la variable bascule à false. Le titre est mis à jour pour retirer l'astérisque et indiquer que le document est enregistré.**
