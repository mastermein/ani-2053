
## Détruisez un travail par un reset --hard volontaire, faites constater la perte, puis retrouvez-le par le reflog.

## fichier utiliser (main.cpp)

   * **contenu**
     * `ligne 1
ligne 2
ligne 3
ligne 4
ligne 5
ligne 6`
   * **chemin**
     * `C:\Users\Mastermein\Desktop\Teuguis\essaie_2`

## 1-Créer du travail et le commiter

 * **Se positionner sur la branche principale :**
   * **commande**
      * `git checkout main`
    * **retour du terminal**
      * `PS C:\Users\Mastermein\Desktop\Teuguis\essaie_2> git checkout main
Already on 'main'
Your branch is up to date with 'origin/main'.`
 * **Modifier un fichier dans VS Code :**

  * **ligne 2**
    * `ligne 2 (unee mofif importante)
`
   
 * **Commiter la modification :**
   * **commandes**
     * `git add main.cpp`
     * `git commit -m "Ajout de la fonctionnalite importante"`
    * **retour du terminal**
       * `PS C:\Users\Mastermein\Desktop\Teuguis\essaie_2> git add main.cpp
PS C:\Users\Mastermein\Desktop\Teuguis\essaie_2> git commit -m "Ajout de la fonctionnalite importante"
[main d55c895] Ajout de la fonctionnalite importante
 1 file changed, 1 insertion(+), 1 deletion(-)`

## 2-Détruire le travail avec un reset hard

 * **Effacer le dernier commit :**
   * **commande**
     * `git reset --hard HEAD~1`
   * **retour du terinal**
     * `PS C:\Users\Mastermein\Desktop\Teuguis\essaie_2> git reset --hard HEAD~1
HEAD is now at 44e9924 Update main.cpp`
 * **Constater la perte dans VS Code et le terminal :**
   * **etat actuel de main.cpp**
     * `ligne 1
ligne 2
ligne 3
ligne 4
ligne 5
ligne 6
`
 * **dans le terminal**
   * **commande**
     * `git log --oneline`
   * **retour du terminal**
     * `PS C:\Users\Mastermein\Desktop\Teuguis\essaie_2> git log --oneline
44e9924 (HEAD -> main, origin/main, origin/HEAD) Update main.cpp
22aae34 mise en etat du fichier main.cpp
9d1512d Fix: resolution du conflit entre main et branche-conflit
3879f24 (branche-conflit) Modification de la même ligne sur branche-conflit
59ed2cd Create main.cpp
26740d9 Modification de la ligne 1 sur main`

   * **description**
     **le commit que l'on vient de placer n'apparait pas dans l'historique**

## 3-Retrouver et restaurer le commit

 * **Afficher l'historique des actions Git :**
   * **commande**
     * `git reflog`
   * **retour du terinal**
     * `44e9924 (HEAD -> main, origin/main, origin/HEAD) HEAD@{0}: reset: moving to HEAD~1
d55c895 HEAD@{1}: commit: Ajout de la fonctionnalite importante
44e9924 (HEAD -> main, origin/main, origin/HEAD) HEAD@{2}: checkout: moving from main to main
44e9924 (HEAD -> main, origin/main, origin/HEAD) HEAD@{3}: pull origin main: Fast-forward
22aae34 HEAD@{4}: commit: mise en etat du fichier main.cpp
9d1512d HEAD@{5}: commit (merge): Fix: resolution du conflit entre main et branche-conflit
26740d9 HEAD@{6}: checkout: moving from branche-conflit to main
3879f24 (branche-conflit) HEAD@{7}: commit: Modification de la même ligne sur branche-conflit
59ed2cd HEAD@{8}: checkout: moving from main to branche-conflit
26740d9 HEAD@{9}: commit: Modification de la ligne 1 sur main
59ed2cd HEAD@{10}: checkout: moving from main to main
59ed2cd HEAD@{11}: clone: from https://github.com/mastermein/essaie_2.git`
 * **Restaurer le commit détruit :**
   * **hash du commit supprimer**
     * `d55c895`
   * **commande**
     * `git reset --hard d55c895`
   * **retour du terinal**
     * `PS C:\Users\Mastermein\Desktop\Teuguis\essaie_2> git reset --hard d55c895
HEAD is now at d55c895 Ajout de la fonctionnalite importante`

* **etat actuel de main.cpp**
  * `ligne 1
ligne 2 (unee mofif importante)
ligne 3
ligne 4
ligne 5
ligne 6
`
* **etat de l'historique**
  * **commande**
    * `git log --oneline`
  * **retour du terminal**
    * `PS C:\Users\Mastermein\Desktop\Teuguis\essaie_2> git log --oneline
d55c895 (HEAD -> main) Ajout de la fonctionnalite importante
44e9924 (origin/main, origin/HEAD) Update main.cpp
22aae34 mise en etat du fichier main.cpp
9d1512d Fix: resolution du conflit entre main et branche-conflit
3879f24 (branche-conflit) Modification de la même ligne sur branche-conflit
59ed2cd Create main.cpp
26740d9 Modification de la ligne 1 sur main`

