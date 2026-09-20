
## Dessinez, au tableau, le graphe des commits d'un dépôt réel : les branches, un point de divergence, une fusion. Puis montrez le même graphe avec git log --graph et faites correspondre les deux.

## chemin de depot
 * `C:\Users\Mastermein\Desktop\Teuguis\Nkentseu`

## 1- graphe des commits du dépôt

  * **commande**
    * ``


   * **retour du terminal**
     * ``

## 2- graphe avec `git log --graph`

  * `PS C:\Users\Mastermein\Desktop\Teuguis\Nkentseu> git log --graph
* commit 6fb634fcd23141392b32df4a79c741aa7bfcacb3 (HEAD -> papa, origin/main, origin/HEAD, main)
| Author: LeTeguis <teuguiasederis@gmail.com>
| Date:   Thu Sep 10 18:29:53 2026 +0100
|
|     NKCode : le web sort du polissage et devient la phase 14, avec une echeance reelle
|
|     Le web tenait jusqu'ici en une case de la phase 9 : « Portage tactile/web (le
|     moteur le permet) ». Il a maintenant une DATE et un USAGE.
|
|     Rodolf, le 10 septembre 2026 : la SESSION NORMALE de RIHEN Academy se compose sur
|     la plateforme, en salle surveillee, sur des epreuves de trois heures minimum, a
|     la mi-janvier. « Si NKCode fonctionne sur le web, alors ca va ouvrir une page
|     pour NKCode ou coder. » Cinquante machines dont on ne maitrise aucune, ou une
|     page.
|
|     CE N'EST PAS UN PORTAGE, C'EST UNE SEPARATION. Compiler du C++ natif dans un
|     onglet est impossible -- bac a sable du navigateur, pas limite de Nkentseu -- or
|     c'est la raison d'etre de NKCode. La phase decolle donc ce qui EDITE de ce qui
|     CONSTRUIT, et cette separation vaut aussi en natif : construction distante, ferme
|     de compilation, integration continue. On ne travaille pas « pour le web », on
|     separe deux choses qui n'auraient jamais du etre soudees.
|
|     LA MOITIE MANQUANTE EXISTE DEJA. L'executeur de RIHEN Academy -- conteneur
|     jetable, sans reseau, en lecture seule, non root, plafonne -- porte clang++,
|     g++, make, cmake, Jenga et le kit Nkentseu. Mesure le 10 septembre : 2,7 secondes
|     de mediane sur les 200 dernieres corrections.
|
|     ET LE TERRAIN EST PLUS PREPARE QU'ON NE CROIT. NKWindow a un backend Emscripten
|     REEL (2424 lignes contre 3384 pour Win32, retouche le 1er septembre) ; NKCanvas a
|     un backend logiciel qui n'exige aucun GPU ; et la lecon de la boucle est deja
|     apprise sur GemCrush -- « LA BOUCLE CEDE LA MAIN, sans quoi l'onglet Web gele ».
|
|     L'ETAPE 0 EST DE MESURER LE POIDS, avant toute architecture. Un IDE en
|     WebAssembly peut peser des dizaines de megaoctets, et les etudiants sont au
|     Cameroun, souvent en donnees mobiles. C'est la seule etape dont le resultat peut
|     annuler les suivantes : il vaut infiniment mieux l'apprendre en septembre qu'en
|     janvier.
|
* commit 860e9d7f1f9ad11f7a238084eb7a86207af67368
| Author: LeTeguis <69282466+LeTeguis@users.noreply.github.com>
| Date:   Thu Sep 10 17:48:29 2026 +0100
|
|     Refonte NK3DModeler : a jour avec main, et NKCode signe sur certificat (#85)
|
:`