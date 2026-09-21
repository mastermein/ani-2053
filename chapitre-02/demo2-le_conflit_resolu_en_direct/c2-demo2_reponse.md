
## Provoquez un conflit devant la classe, et résolvez-le sans couper : lecture des marqueurs, décision, reconstruction, validation. Ce qu'on évalue est le calme.

## fichier (main.cpp)
 * **chemin**
   * `C:\Users\Mastermein\Desktop\Teuguis\essaie_2`
 * **contenu**
   * `ligne 1
ligne 2
ligne 3
ligne 4
ligne 5
ligne 6`

## provoquer un conflit

 * **1. Se placer sur la branche main**
   * **commande** `git checkout main`
   * **retour du terminal**
     * `PS C:\Users\Mastermein\Desktop\Teuguis\essaie_2> git checkout main
M       main.cpp
Already on 'main'
Your branch is up to date with 'origin/main'.`

 * **2. Modifier une ligne sur main**
   * **ligne modifier**
     * **ligne2** `ligne 2 modifier sur main`
    
   * **commandes**
      * `git add main.cpp`
      * `git commit -m "Modification de la ligne 2 sur main"`
    * **retour du terminal**
      * `PS C:\Users\Mastermein\Desktop\Teuguis\essaie_2> git add main.cpp
PS C:\Users\Mastermein\Desktop\Teuguis\essaie_2> git commit -m "Modification de la ligne 1 sur main"
[main 26740d9] Modification de la ligne 1 sur main
 1 file changed, 1 insertion(+), 1 deletion(-)`
   
 * **3. Créer une nouvelle branche parallèle**

   * **commande**
     * `git checkout -b branche-conflit HEAD~1`
   * **retour du terminal**
     * `PS C:\Users\Mastermein\Desktop\Teuguis\essaie_2> git checkout -b branche-conflit HEAD~1
Switched to a new branch 'branche-conflit'`
      
 * **4. Modifier la MÊME ligne sur la nouvelle branche**
    * **commandes**
      * `git add main.cpp`
      * `git commit -m "Modification de la même ligne sur branche-conflit"`
    * **retour du terminal**
      * `PS C:\Users\Mastermein\Desktop\Teuguis\essaie_2> git add main.cpp
PS C:\Users\Mastermein\Desktop\Teuguis\essaie_2> git commit -m "Modification de la même ligne sur branche-conflit"
[branche-conflit 3879f24] Modification de la même ligne sur branche-conflit
 1 file changed, 1 insertion(+), 1 deletion(-)`

   
 * **5. Déclencher le conflit par la fusion**

   * **commandes**
     * `git checkout main` **Revenir sur la branche principale**
     * `git merge branche-conflit` **Tenter de fusionner la branche secondaire dans main**
    
   * **retour du terminal**
     * `PS C:\Users\Mastermein\Desktop\Teuguis\essaie_2> git checkout main
Switched to branch 'main'
Your branch is ahead of 'origin/main' by 1 commit.
  (use "git push" to publish your local commits)
PS C:\Users\Mastermein\Desktop\Teuguis\essaie_2> git merge branche-conflit
Auto-merging main.cpp
CONFLICT (content): Merge conflict in main.cpp
Automatic merge failed; fix conflicts and then commit the result.`
   
 * **6. Lire les marqueurs et résoudre dans VS Code**

  * **efface manuellement les lignes avec <, =, > pour ne garder que le texte final souhaité. Sauvegarde le fichier.**
  * **vérifier que le fichier est propre après résolution avec `git status`**

 * **7. Valider la résolution du conflit**

   * **commandes**
     * `git add main.cpp`
     * `git commit -m "Fix: resolution du conflit entre main et branche-conflit"`
    
  * **retour du terminal**
    * `PS C:\Users\Mastermein\Desktop\Teuguis\essaie_2> git add main.cpp
PS C:\Users\Mastermein\Desktop\Teuguis\essaie_2> git commit -m "Fix: resolution du conflit entre main et branche-conflit"
[main 9d1512d] Fix: resolution du conflit entre main et branche-conflit`
