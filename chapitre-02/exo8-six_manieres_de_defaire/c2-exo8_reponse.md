
## Provoquez, puis défaites, ces six situations : une modification non voulue, un add de trop, un commit de trop, un commit poussé qu'il faut annuler, un travail en cours qu'il faut mettre de côté, et un commit « perdu » à retrouver par le reflog.


## fichier utiliser :
  * `main.cpp`
  * **chemin :** `C:\Users\Mastermein\Desktop\Teuguis\ani-2053\dossier d'essaie\depot-d-essaie\fichiers d'essai`
  * **contenu :** `#include <iostream>

int main() {
    // Configuration de la vitesse
    float vitesseJoueur = 100.0f;
    
    // Affichage des informations
    std::cout << "Vitesse actuelle du joueur : " << vitesseJoueur << std::endl;
    std::cout << "Bienvenue dans le jeu !" << std::endl;

    return 0;
}
`

## Provoquer, puis défaire les six situations

### 1. Modification non voulue

 * **modification**
    * **ligne 7** `    float vitesseJoueur = 150.0f;`
 * **verification de l'etat**
   * **commande**
     * `git status`
   * **retour du terminal**
      * `PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053> git status
On branch main
Your branch is up to date with 'origin/main'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
  (commit or discard the untracked or modified content in submodules)
        modified:   dossier d'essaie/depot-d-essaie (modified content)

no changes added to commit (use "git add" and/or "git commit -a")`

 * **resolution du probleme**
   * **commande**
      * `git restore main.cpp`
    * **retour du terminal**
      * `PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053> cd "C:\Users\Mastermein\Desktop\Teuguis\ani-2053\dossier d'essaie\depot-d-essaie\fichiers d'essai"
PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\dossier d'essaie\depot-d-essaie\fichiers d'essai> git restore main.cpp`


# 2. Add de trop

* **probleme**
  * **commande**
     * `git add main.cpp`
* **solution**
   * **commande**
     * `git restore --staged main.cpp` **Retire le fichier de l'index sans supprimer ta modification locale**
     * `git restore main.cpp` **(Optionnel) Annule la modification si tu n'en veux pas du tout**
   * **retour du terminal**
     * `PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\dossier d'essaie\depot-d-essaie\fichiers d'essai> git restore --staged main.cpp
PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\dossier d'essaie\depot-d-essaie\fichiers d'essai> git restore main.cpp
PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\dossier d'essaie\depot-d-essaie\fichiers d'essai>`

# 3. Commit de trop

* **probleme**
  * **commandes**
    * `git add main.cpp`
    * `git commit -m "commit à annuler"`
  * **retour du terminal**
    * `PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\dossier d'essaie\depot-d-essaie\fichiers d'essai> git add main.cpp
PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\dossier d'essaie\depot-d-essaie\fichiers d'essai> git commit -m "commit inutile à annuler"
[main 7db7078] commit inutile à annuler
 1 file changed, 1 insertion(+), 1 deletion(-)`

* **Solution**
  * **commandes**
    * `git reset HEAD~1` **Annule le dernier commit tout en conservant tes modifications dans les fichiers**
    * `git restore main.cpp` **(Optionnel) Nettoie le fichier si besoin**
   * **retour du terminal**
     * `PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\dossier d'essaie\depot-d-essaie\fichiers d'essai> git reset HEAD~1
Unstaged changes after reset:
M       fichiers d'essai/main.cpp
PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\dossier d'essaie\depot-d-essaie\fichiers d'essai> git restore main.cpp
PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\dossier d'essaie\depot-d-essaie\fichiers d'essai>`

# 4. Commit poussé

* **probleme**
  * **commandes**
    * `git add .`
    * `git commit -m "mauvaise fonctionnalité"`
    * `git push origin main`
  * **retour du terminal**
    * `PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\dossier d'essaie> git add .
PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\dossier d'essaie> git commit -m "mauvaise fonctionnalité"
[main 2c2893e] mauvaise fonctionnalité
 1 file changed, 1 insertion(+), 1 deletion(-)
PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\dossier d'essaie> git push origin main
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 4 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (3/3), 309 bytes | 309.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/mastermein/ani-2053.git
   fcacae8..2c2893e  main -> main`
* **solution**
   * **commandes**
    * `git revert HEAD --no-edit` **Crée un commit inverse qui annule les modifications proprement**
    * `git push origin main` **Pousse l'annulation sur GitHub**
  * **retour du terminal**
    * `PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\dossier d'essaie> git revert HEAD --no-edit
[main c4eec38] Revert "mauvaise fonctionnalité"
 Date: Mon Sep 21 16:17:00 2026 +0200
 1 file changed, 1 insertion(+), 1 deletion(-)
PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\dossier d'essaie> git push origin main
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 4 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (3/3), 337 bytes | 337.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/mastermein/ani-2053.git
   2c2893e..c4eec38  main -> main`

# 5. Stash

* **probleme**
  * **commandes**
    * `git status`
    * ``
  * **retour du terminal**
    * ``
* **solution**
   * **commandes**
    * ``
    * ``
  * **retour du terminal**
    * ``

# 6. Reflog

* **probleme**
  * **commandes**
    * `git add main.cpp`
    * `git commit -m "fonctionnalité importante"`
    * `git reset --hard HEAD~1` **on efface brutalement le dernier commit**
  * **retour du terminal**
    * `PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\dossier d'essaie> git add .
PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\dossier d'essaie> git commit -m "fonctionnalité importante"
[main dd0b1b7] fonctionnalité importante
 1 file changed, 1 insertion(+), 1 deletion(-)
PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\dossier d'essaie> git reset --hard HEAD~1
HEAD is now at c4eec38 Revert "mauvaise fonctionnalité"`
* **solution**
   * **commandes**
    * `git reflog` **Affiche le journal de toutes les actions pour retrouver l'empreinte (HASH) du commit supprimé**
    * `git reset --hard <HASH_DU_COMMIT>` **Restaure l'état à ce commit précis**
  * **retour du terminal**
    * `PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\dossier d'essaie> git add .
PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\dossier d'essaie> git commit -m "fonctionnalité importante"
[main dd0b1b7] fonctionnalité importante
 1 file changed, 1 insertion(+), 1 deletion(-)
PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\dossier d'essaie> git reset --hard HEAD~1
HEAD is now at c4eec38 Revert "mauvaise fonctionnalité"
PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\dossier d'essaie> git reflog
c4eec38 (HEAD -> main, origin/main) HEAD@{0}: reset: moving to HEAD~1
dd0b1b7 HEAD@{1}: commit: fonctionnalité importante
c4eec38 (HEAD -> main, origin/main) HEAD@{2}: checkout: moving from exo5-branche to main
b112d79 (exo5-branche) HEAD@{3}: checkout: moving from main to exo5-branche
c4eec38 (HEAD -> main, origin/main) HEAD@{4}: checkout: moving from exo5-branche to main
b112d79 (exo5-branche) HEAD@{5}: checkout: moving from main to exo5-branche
c4eec38 (HEAD -> main, origin/main) HEAD@{6}: checkout: moving from exo5-branche to main
b112d79 (exo5-branche) HEAD@{7}: checkout: moving from main to exo5-branche
c4eec38 (HEAD -> main, origin/main) HEAD@{8}: revert: Revert "mauvaise fonctionnalité"
2c2893e HEAD@{9}: commit: mauvaise fonctionnalité
fcacae8 HEAD@{10}: pull origin main: Fast-forward
c92178c HEAD@{11}: commit (merge): Finalisation du merge et ajout de c2-exo10_reponse.md
fea414b HEAD@{12}: pull origin main: Merge made by the 'ort' strategy.
727bcdd HEAD@{13}: commit: correction de l'exo3
bfb98d8 HEAD@{14}: commit: envoi du fichier de reponse de l'exo6
c8bcf6c HEAD@{15}: commit: fichier de reponse demo1
93ec3fa HEAD@{16}: pull origin main: Fast-forward
fa85ee1 HEAD@{17}: commit: envoi du fichier de reponse de 'exo 9
d264abf HEAD@{18}: pull origin main: Fast-forward
53f7d67 HEAD@{19}: pull origin main: Fast-forward
f3db606 HEAD@{20}: commit: Reponse a l'exercice 11
2209926 HEAD@{21}: commit: Suppression du gros fichier
976aeae HEAD@{22}: commit (merge): Ajout involontaire du gros fichier
dfa3308 HEAD@{23}: checkout: moving from exo5-branche to main
b112d79 (exo5-branche) HEAD@{24}: commit: reponses exo 5
12a0419 HEAD@{25}: commit: Troisieme commit sur la branche : ajout ligne 3
d65f4a2 HEAD@{26}: commit: Deuxieme commit sur la branche : ajout ligne 2
7a201ef HEAD@{27}: commit: Premier commit sur la branche : ajout ligne 1
dfa3308 HEAD@{28}: checkout: moving from main to exo5-branche
dfa3308 HEAD@{29}: checkout: moving from ma-branche-test to main
dfa3308 HEAD@{30}: checkout: moving from main to ma-branche-test
dfa3308 HEAD@{31}: commit: Mettre a jour le message d'accueil de l'interface
16e3ebc HEAD@{32}: commit: Ajuster la vitesse de deplacement du joueur
f9b55c5 HEAD@{33}: commit: initialisation de main.cpp
f52c225 HEAD@{34}: commit: fichier source
a2dc2e1 HEAD@{35}: commit: fichier de reponses
622c600 HEAD@{36}: commit: remise a zero
f61bc42 HEAD@{37}: commit: creation du fichier a modifier
c562c01 HEAD@{38}: commit: envoi du fichier de reponse
ef17bbd HEAD@{39}: commit: depot des fichier de reponse et a modifier
a771536 HEAD@{40}: commit: modification du main.cpp
9c8812d HEAD@{41}: commit (merge): creation du fichier qui sera moidifier
ff2c5bb HEAD@{42}: commit: Creation des fichiers qui seont modfiers
011cf41 HEAD@{43}: Branch: renamed refs/heads/master to refs/heads/main
011cf41 HEAD@{45}: commit: Ajout du fichier de reponse
39b5a22 HEAD@{46}: commit: Ajout du troisieme fichier
84c5d67 HEAD@{47}: commit: Ajout du deuxieme fichier
6cf0a92 HEAD@{48}: commit (initial): Ajout du premier fichier
PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\dossier d'essaie> git reset --hard b112d79
HEAD is now at b112d79 reponses exo 5`
