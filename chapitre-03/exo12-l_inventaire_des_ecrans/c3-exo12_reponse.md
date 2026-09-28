
## Écrivez un programme qui affiche, pour chaque écran branché : sa taille, sa position, son facteur d'échelle, et lequel porte votre fenêtre. Déplacez la fenêtre d'un écran à l'autre et vérifiez que les valeurs suivent.


## Fonction d'affichage de l'inventaire (DisplayMonitors)

 * `void DisplayMonitors(const NkWindow& win) {
    auto monitors = win.EnumerateMonitors();
    auto currentMon = win.GetCurrentMonitor();
    std::cout << "\n--- LISTE DES ECRANS (" << win.GetMonitorCount() << " detecte(s)) ---" << std::endl;
    for (usize i = 0; i < monitors.Size(); ++i) {
        const auto& m = monitors[i];
        bool isCurrent = (m.index == currentMon.index);
        std::cout << "Ecran [" << (i + 1) << "] : " << m.name << std::endl;
        std::cout << "  * Position : (" << m.posX << ", " << m.posY << ")" << std::endl;
        std::cout << "  * Taille   : " << m.width << "x" << m.height << " px" << std::endl;
        std::cout << "  * Echelle  : " << m.dpiScale << "x (" << static_cast<int>(m.dpiScale * 100) << "%)" << std::endl;
        std::cout << "  * Fenetre ici : " << (isCurrent ? "OUI" : "Non") << std::endl;
    }`

   * **Cette fonction parcourt la liste de tous les moniteurs connectés au système (EnumerateMonitors()). Pour chaque écran, elle affiche :La position absolue sur le bureau virtuel (posX, posY).La résolution en pixels (width, height).Le facteur d'échelle (dpiScale) sous forme décimale et en pourcentage (ex: $1.25\text{x}$ / $125\%$).L'indicateur du porteur : elle compare l'index de chaque écran avec celui renvoyé par GetCurrentMonitor() pour déterminer et afficher OUI sur l'écran qui contient actuellement la fenêtre.**
  
   ## Configuration et création de la fenêtre

   * `NkWindowConfig cfg;
cfg.title  = "Exo12 - Moniteurs";
cfg.width  = 640;
cfg.height = 480;
NkWindow window(cfg);
if (!window.IsOpen()) return -1;
DisplayMonitors(window);
usize activeMonitorIndex = window.GetCurrentMonitor().index;`
   * **Ce bloc initialise la fenêtre principale avec ses dimensions de base ($640\times480\text{ px}$). Dès son ouverture, il effectue un premier inventaire des écrans et enregistre l'identifiant de l'écran de départ dans activeMonitorIndex.**
  
  ## Gestion des événements clavier et de fermeture

  * `if (ev->Is<NkWindowCloseEvent>()) {
    window.Close();
}
else if (auto* kp = ev->As<NkKeyPressEvent>()) {
    if (kp->GetKey() == NkKey::NK_ESCAPE) {
        window.Close();
    } else if (kp->GetKey() == NkKey::NK_SPACE || kp->GetKey() == NkKey::NK_I) {
        DisplayMonitors(window);
    }
}`

* **Ce bloc traite les interactions utilisateur :
Fermeture : Ferme l'application via le bouton de fermeture ou la touche ÉCHAP.
Actualisation manuelle : Permet de ré-afficher à tout moment l'état des écrans dans la console en appuyant sur ESPACE ou I.**

## Détection du déplacement de la fenêtre entre les écrans

* `else if (ev->Is<NkWindowMoveEvent>()) {
    auto currentMon = window.GetCurrentMonitor();
    if (currentMon.index != activeMonitorIndex) {
        activeMonitorIndex = currentMon.index;
        std::cout << "\n>> Fenetre deplacee sur un autre ecran !";
        DisplayMonitors(window);
    }`

  * **À chaque fois que la fenêtre bouge (NkWindowMoveEvent), le code récupère l'écran courant. Si l'identifiant de cet écran diffère de activeMonitorIndex, cela signifie que la fenêtre a franchi la frontière vers un nouvel écran. Le programme met alors à jour l'index sauvegardé et déclenche automatiquement l'affichage du nouvel inventaire.**
 
  ## retour du terminal

  * `PS C:\Users\Mastermein\Desktop\Teuguis\fenetre> jenga build

╔══════════════════════════════════════════════════════════════════╗
║                                                                  ║
║                ██╗███████╗███╗   ██╗ ██████╗  █████╗             ║
║                ██║██╔════╝████╗  ██║██╔════╝ ██╔══██╗            ║
║                ██║█████╗  ██╔██╗ ██║██║  ███╗███████║            ║
║           ██   ██║██╔══╝  ██║╚██╗██║██║   ██║██╔══██║            ║
║           ╚█████╔╝███████╗██║ ╚████║╚██████╔╝██║  ██║            ║
║            ╚════╝ ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝            ║
║                                                                  ║
║             Multi-platform C/C++ Build System v2.8.0             ║
║                                                                  ║
╚══════════════════════════════════════════════════════════════════╝

Loading workspace...

Configuration: Debug
Target:        Windows x86_64
Toolchain:     clang-mingw

Build Order (1 projects):
  1. fenetre [CONSOLE_APP]


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: fenetre                                                         Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date
┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.04s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  1/1
Time:           0.05s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════

PS C:\Users\Mastermein\Desktop\Teuguis\fenetre> jenga run  

╔══════════════════════════════════════════════════════════════════╗
║                                                                  ║
║                ██╗███████╗███╗   ██╗ ██████╗  █████╗             ║
║                ██║██╔════╝████╗  ██║██╔════╝ ██╔══██╗            ║
║                ██║█████╗  ██╔██╗ ██║██║  ███╗███████║            ║
║           ██   ██║██╔══╝  ██║╚██╗██║██║   ██║██╔══██║            ║
║           ╚█████╔╝███████╗██║ ╚████║╚██████╔╝██║  ██║            ║
║            ╚════╝ ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝            ║
║                                                                  ║
║             Multi-platform C/C++ Build System v2.8.0             ║
║                                                                  ║
╚══════════════════════════════════════════════════════════════════╝


━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ▶  EXECUTION  —  fenetre.exe
     C:\Users\Mastermein\Desktop\Teuguis\fenetre\Build\Bin\Debug-Windows\fenetre\fenetre.exe
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━


--- LISTE DES ECRANS (1 detecte(s)) ---
Ecran [1] : \\.\DISPLAY1
  * Position : (0, 0)
  * Taille   : 1920x1080 px
  * Echelle  : 1.25x (125%)
  * Fenetre ici : OUI

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  ◀  FIN D'EXECUTION  —  termine normalement  (610.05s)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
PS C:\Users\Mastermein\Desktop\Teuguis\fenetre> `
