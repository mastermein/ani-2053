#include "NKWindow/NKWindow.h"
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
}
