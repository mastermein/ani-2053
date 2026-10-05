#include "NKWindow/NKMain.h"
#include "NKCanvas/App/NkCanvasApp.h"
#include "NKCanvas/UI/

using namespace nkentseu::renderer;
using namespace nkentseu;

class fenetreNue : public NkCanvasApp 
{
    public:
      fenetreNue()
      {
        Config().title = "fenetre nue";
        Config().width = 1280;
        Config().height = 1024;
        Config().clearColor = NkColor2D{200, 200, 254};
      }    
};

int nkmain(const nkentseu::NkEntryState& state)
{
    return NkCanvasApp::Run<fenetreNue>(state);
}
