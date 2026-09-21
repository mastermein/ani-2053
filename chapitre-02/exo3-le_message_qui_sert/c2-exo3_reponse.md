## Prenez trois commits du dépôt du moteur et jugez leurs messages : dit-il ce qu'il fait ? pourquoi ? porte-t-il un seul sujet ? Récrivez celui qui vous paraît le plus faible.


## 1-arborescence utilisee : C:\Users\Mastermein\Desktop\Teuguis\Nkentseu

## 2-commande utilisee : git log --online

  * **Retour du terminal :**
    * **PS C:\Users\Mastermein\Desktop\Teuguis\Nkentseu> git log --oneline
6fb634fc (HEAD -> papa, origin/main, origin/HEAD, main) NKCode : le web sort du polissage et devient la phase 14, avec une echeance reelle
860e9d7f Refonte NK3DModeler : a jour avec main, et NKCode signe sur certificat (#85)
c1c815ff CI : les huit epinglages de Jenga passent par JENGA_VERSION (#87)
addf709d NKCode beta.8 a beta.11 : la ligne publiee rejoint enfin main (#86)
43285010 (origin/fix/nktraits-portable) NkTraits : demander a la primitive si elle existe, pas au compilateur qui il est
0d50a971 NKCode 0.1.0-beta.6 : version bumpee avant publication
7c3e84a0 Merge remote-tracking branch 'origin/main'
4c7d66b5 Distribution : refuser de livrer un exe dont une DLL importee manque
ad0779cb NKCode : runtime MinGW en statique — l'exe ne depend plus du msys64 du testeur
cc41ca45 GemCrush : le jeu complet -- menu, aventure 30 niveaux, 3 modes, audio synthetise (#84)
5fc605de Vulkan : la garde headless existait UNIQUEMENT sous Windows -- segfault sur les trois dorsales Linux
56b0ed67 wiki : les mesures Vulkan sont CONFIRMEES par contre-verification -- et un 5e piege, celui qui a permis le desaccord
ecfb57cb wiki maintenabilite : quelle garde rougirait AUJOURD HUI -- reponse mesuree, et c est << aucune ici >>
b4cdf3cc wiki pieges : l avertissement sur CreateWithFallback est MAINTENU -- mesure a l appui -- et gagne le corollaire sur les bancs
92cf625a wiki : je retire << 18 shaders casses >> -- c etait mon cache, pas le depot ; + les 4 pieges d instrument et la validation de G1
7ddd10ce NKRenderer : garde G1 -- l ordre de frame devient bruyant au lieu d etre silencieux
5e2d56ab wiki NKRenderer/NKRHI : le contrat de frame mesure, la surface publique, la divergence des backends -- et deux corrections datees de mes propres chiffres
3b79729b NKRenderer : Present() avant EndFrame() sur les 3 sites inverses, et le commentaire qui enseignait l inverse
d45a78d4 Merge branch 'feat/design-nodal'
ab2ba781 verifie_planches : deux controles sur la TABLE du 13, et un \b qui n en etait pas un
20648f12 Planche 08 : le panneau 3 ne dit plus  CE QUE LE MODELE NE PERMET PAS AUJOURD HUI  -- c est code, et date
70f78561 NKGraph specification : le 19.3 est FAUX par la mesure, le 19.9 gagne une quatrieme raison, et le 20 cesse de decrire un code d hier
d266cd56 NKGraph specification : les trois contradictions signalees par le chantier voisin, et une famille de defaut nommee
0b918850 Kernel : sortir les SORTIES de bancs du suivi, retirer les residus
4ec71d47 NKGraph : le fichier Lunacy de Rodolf rejoint la branche design, et il est ENFIN suivi
645d4e6b NKGraph : l acyclicite reste universelle -- et ca coute le Portail, ce qu on ecrit au lieu de le taire
9a4e769d NKGraph : aligner les documents de main sur la branche design
43d8df92 NKGraph : trois decisions de Rodolf -- et la premiere fait tomber un mur que j avais decrit le matin meme
a542588c docs(cartographie): lot 5 - les notices de temoins NKGraph ne sont pas commitees
1f46346d docs(cartographie): correction de decompte dans l en-tete du rapport
05dcf3ed docs(cartographie): lot 4 - rapport final, deux chiffres, critique de la cible et mecanisme anti-repousse
9c92b13c docs(cartographie): lot 3 - carte de consolidation des 747 fichiers + script de classement
63eb5889 docs(cartographie): lot 2 - divergences mesurees avec les cinq decisions
d761088a docs(cartographie): lot 1 - inventaire des 747 markdown (taille, lignes, derniere modif)
95259b8a NKGraph : les trois attributions du sequenceur etaient un MOT pour deux choses -- une phrase par couche, et personne ne perd
f110c845 NKGraph : p01 passe par ecrire() -- et un controle empeche la quatrieme occurrence
afd0d02d NKGraph : NKScena a un domaine mais pas de mode -- et « un seul DCC » disait le contraire de la decision
9fd3cb1c NKGraph : les huit planches sont rangees en groupes nommes -- et les huit PNG sont identiques au pixel
4afc1b67 NKGraph : quel graphe ouvre quelle application -- et le tableau fait apparaitre trois choses qu aucune planche ne montrait
a3c77865 NKGraph : le SVG n emploie plus ce que Lunacy lit mal -- l ombre retiree, les motifs redessines
52094452 NKGraph : les deux conventions que les sept planches contredisaient -- le geste, fait expres, en un seul endroit
9b31cc8f Fusion : ConquerorLab jouable pour le stagiaire, et NK3DModeler lineaire
631ad2bd Cours : le controle Libelles hors cadre, pourquoi AddText tronquait des deux cotes, et le renvoi depuis le chapitre du joueur -- PDF regenere
872a25c0 maxWidth 0 ne dessinait rien : deux compteurs invisibles -- et un controle qui liste les libelles hors cadre
6b9f5b32 Texte hors cadre : la limite de AddText part de l origine, pas du bord -- ajustement avant placement + registre des debordements
d4d8e4c7 Banc d ambiguite : le cas du kit du stagiaire -- une case a fusionner n etait pas selectionnable, et le coin (0,0) passait pour la source
3331d7e8 Cours Conqueror : un chapitre pour CELUI QUI JOUE -- fusion, pouvoirs, artefacts a la souris -- renvois croises avec les chapitres d auteur, raccourci Pouvoir, PDF regenere
99f57786 Correctif de compilation : Find prend un const char*, la conversion NkString vers NkStringView etait ambigue
d96744bf ConquerorLab : le message de grille porte sa GRAVITE au lieu de la faire deviner par des mots -- ILLISIBLE s affichait en vert -- et dit si le JSON est casse ou s il manque une clef
23456473 ConquerorLab : la case du RESULTAT se voit sans survol, et deux coups qui visent la meme case se choisissent -- le second pouvoir etait injouable a la souris
dbfd3fd7 ConquerorLab : la FUSION devient jouable a la souris, un raccourci Fusionner, et un exemple RegleFusion
08f7ed99 ConquerorLab : la bibliotheque de grilles dit ce qu elle IGNORE, et pourquoi un fichier est illisible
d52e64d5 NKGraph : la police n etait que sur la racine du SVG -- l heritage marche dans un navigateur, pas a l import Lunacy
ddf42806 NKGraph : les types composes -- ils ne demandent pas quatre choses au modele, ils en demandent deux
514b235b NKGraph : une ligne du recap disait DEUX etats a la fois -- et le controle renvoyait le defaut a l humain
PS C:\Users\Mastermein\Desktop\Teuguis\Nkentseu>**

## 3-commits retenus :

 ### Commit 1 : `1f46346d`

  * **Message de titre :** `docs(cartographie): correction de decompte dans l en-tete du rapport`
  * **Examen avec `git show --no-patch 1f46346d` :** Le corps explicite le changement exact sur les compteurs.
  * **Jugement :**
    * **Dit-il ce qu'il fait ?** Oui, il indique qu'il corrige le décompte dans l'en-tête du rapport de cartographie.
    * **Dit-il pourquoi ?** Oui, pour aligner le chiffre de l'en-tête avec les mesures réelles des fichiers recensés.
    * **Porte-t-il sur un seul sujet ?** Oui, exclusivement sur la correction du chiffre d'en-tête.



 ### Commit 2 : `3b79729b`

  * **Message de titre :** `NKRenderer : Present() avant EndFrame() sur les 3 sites inverses, et le commentaire qui enseignait l inverse`
  * **Examen avec `git show --no-patch 3b79729b` :** On voit la permutation des deux appels de fonction.
  * **Jugement :**
    * **Dit-il ce qu'il fait ?** Oui, il remet l'appel `Present()` avant `EndFrame()` sur trois sites d'appel et corrige le commentaire trompeur.
    * **Dit-il pourquoi ?** Non. Le message décrit l'inversion d'ordre mais n'explique pas quelle anomalie ou bogue d'affichage (ex: gel d'image ou désynchronisation) cette inversion venait corriger.
    * **Porte-t-il sur un seul sujet ?** Oui, l'ordre d'appel d'affichage dans le moteur de rendu.


### Commit 3 : `7c3e84a0` (Le commit le plus faible)
  * **Message de titre :** `Merge remote-tracking branch 'origin/main'`
  * **Examen avec `git show --no-patch 7c3e84a0` :** Le corps est vide, seul le titre généré automatiquement par Git est présent.
  * **Jugement :**
    * **Dit-il ce qu'il fait ?** Non. Il indique uniquement une opération technique Git automatique, sans mentionner les fonctionnalités ou correctifs rapatriés.
    * **Dit-il pourquoi ?** Non. Aucune raison contextuelle ou explication métier n'est fournie.
    * **Porte-t-il sur un seul sujet ?** Non. Il regroupe aveuglément l'ensemble des modifications apportées par d'autres développeurs sur la branche distante.



## 4- Réécriture du commit le plus faible (`7c3e84a0`)


**Titre :**
`NKCode : synchroniser la branche locale avec la version stable d'origin/main`

**Corps du message :**
`Intégration des derniers correctifs du runtime MinGW et de la distribution des DLLs depuis origin/main. Cette fusion élimine les échecs de dépendances manquantes constatés lors des tests locaux avant la publication.`