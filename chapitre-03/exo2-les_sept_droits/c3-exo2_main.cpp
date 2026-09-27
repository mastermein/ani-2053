#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkEventSystem.h"
#include "NKEvent/NkWindowEvent.h"
#include <iostream>

using namespace nkentseu;

NKENTSEU_DEFINE_APP_DATA(([]() {
    NkAppData d{};
    d.appName = "Les Sept Droits";
    d.appVersion = "1.0.0";
    return d;
})());

// Fonction simple pour exécuter une boucle de fenêtre
void RunTestWindow(const NkWindowConfig& cfg, const char* testName) {
    NkWindow window;
    if (!window.Create(cfg)) {
        std::cout << "Erreur de creation : " << testName << std::endl;
        return;
    }

    std::cout << "--- Test en cours : " << testName << " ---" << std::endl;
    std::cout << "Fermez la fenetre pour passer au test suivant..." << std::endl;

    while (window.IsOpen()) {
        while (NkEvent* ev = NkEvents().PollEvent()) {
            if (ev->Is<NkWindowCloseEvent>()) {
                window.Close();
            }
        }
    }
}

int nkmain(const NkEntryState& state) {
    // Configuration de base
    NkWindowConfig baseCfg;
    baseCfg.width = 600;
    baseCfg.height = 400;

    // 1. Test sans bordure
    {
        NkWindowConfig cfg = baseCfg;
        cfg.title = "Test 1: frame = false";
        cfg.frame = false;
        RunTestWindow(cfg, "frame = false");
    }

    // 2. Test non redimensionnable
    {
        NkWindowConfig cfg = baseCfg;
        cfg.title = "Test 2: resizable = false";
        cfg.resizable = false;
        RunTestWindow(cfg, "resizable = false");
    }

    // 3. Test non minimisable
    {
        NkWindowConfig cfg = baseCfg;
        cfg.title = "Test 3: minimizable = false";
        cfg.minimizable = false;
        RunTestWindow(cfg, "minimizable = false");
    }

    // 4. Test non déplaçable
    {
        NkWindowConfig cfg = baseCfg;
        cfg.title = "Test 4: movable = false";
        cfg.movable = false;
        RunTestWindow(cfg, "movable = false");
    }

    // 5. Test non fermable
    {
        NkWindowConfig cfg = baseCfg;
        cfg.title = "Test 5: closable = false";
        cfg.closable = false;
        RunTestWindow(cfg, "closable = false");
    }

    // 6. Test non maximisable
    {
        NkWindowConfig cfg = baseCfg;
        cfg.title = "Test 6: maximizable = false";
        cfg.maximizable = false;
        RunTestWindow(cfg, "maximizable = false");
    }

    // 7. Test plein écran désactivé
    {
        NkWindowConfig cfg = baseCfg;
        cfg.title = "Test 7: canFullscreen = false";
        cfg.canFullscreen = false;
        RunTestWindow(cfg, "canFullscreen = false");
    }

    return 0;
}
