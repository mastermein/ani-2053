#include "NKWindow/NKMain.h"
#include "NKLogger/NkLog.h"
#include "NKImage/NKImage.h"

using namespace nkentseu;

int nkmain (const NkEntryState &state)
{
   NkImage icone;
   NkImage capture;
   NkImage dessin;
   NkImage photo1;
   NkImage photo2;

   if(icone.Load("Snake/src/icone.png"))
   {
    logger.Info("icone.png - Largeur {0} - Hauteur {1} - BytesPP {2} - poids {3}", icone.Width(), icone.Height(), icone.BytesPP(), icone.Width() * icone.Height() * icone.BytesPP() );
   }

   if(capture.Load("Snake/src/Capture.png"))
   {
    logger.Info("capture.png - Largeur {0} - Hauteur {1} - BytesPP {2} - poids {3}", capture.Width(), capture.Height(), capture.BytesPP(), capture.Width() * capture.Height() * capture.BytesPP() );
   }

   if(dessin.Load("Snake/src/dessin.png"))
   {
    logger.Info("dessin.png - Largeur {0} - Hauteur {1} - BytesPP {2} - poids {3}", dessin.Width(), dessin.Height(), dessin.BytesPP(), dessin.Width() * dessin.Height() * dessin.BytesPP() );
   }

   if(photo1.Load("Snake/src/photo1.jpg"))
   {
    logger.Info("photo1.jpg - Largeur {0} - Hauteur {1} - BytesPP {2} - poids {3}", photo1.Width(), photo1.Height(), photo1.BytesPP(), photo1.Width() * photo1.Height() * photo1.BytesPP() );
   }

   if(photo2.Load("Snake/src/photo2.jpg"))
   {
    logger.Info("photo2.jpg - Largeur {0} - Hauteur {1} - BytesPP {2} - poids {3}", photo2.Width(), photo2.Height(), photo2.BytesPP(), photo2.Width() * photo2.Height() * photo2.BytesPP() );
   }
   return 0;
}
