
## Sur votre dépôt d'essai, faites deux fois la même intégration : une fois par fusion, une fois en rejouant. Comparez les deux graphes, et dites lequel vous préférez lire, avec un argument.

## 1-utilisateur 

  * **clone A** `C:\Users\Mastermein\Desktop\clone A\depot-d-essaie`
  * **clone B** `C:\Users\Mastermein\Desktop\clone B\depot-d-essaie`

## 2-fichier `main.cpp`

 * **contenu :**
    * `#include <iostream>

// ==========================================
// DEBUT DU FICHIER : ZONE DE MODIFICATION A
// ==========================================
void afficherEntete() {
    std::cout << "=== Application C++ Demonstration Git ===,  clone A " << std::endl;
}

void traiterDonnees() {
    std::cout << "Traitement des donnees en cours..." << std::endl;
}

void afficherStatistiques() {
    std::cout << "Statistiques : 100% OK" << std::endl;
}

// ==========================================
// FIN DU FICHIER : ZONE DE MODIFICATION B
// ==========================================
void afficherPiedDePage() {
    std::cout << "=== Fin du programme === , clone B" << std::endl;
}

int main() {
    afficherEntete();
    traiterDonnees();
    afficherStatistiques();
    afficherPiedDePage();
    return 0;
}` 
## 3- realiser les integrations

  ### A- Intégration par Fusion (git merge) : sur le clone A

  * **creation de la branche `branche-merge`**
     * **commande**
        * `git checkout -b branche-merge`
     * **retour du terminal**
        * `PS C:\Users\Mastermein\Desktop\clone A\depot-d-essaie> git checkout -b branche-merge
Switched to a new branch 'branche-merge'`
  * **modification di main.cpp**
     * **ligne 7** **`std::cout << "=== Application C++ Demonstration Git ===,  clone A , branche merge" << std::endl;`**

  * **enregistrer le commit**
     * **commandes**
        * `git add .`
        * `git commit -m "Ajout de modifications sur la branche de fusion"`
        
     * **retour du terminal**
        * `PS C:\Users\Mastermein\Desktop\clone A\depot-d-essaie> git add .
PS C:\Users\Mastermein\Desktop\clone A\depot-d-essaie> git commit -m "Ajout de modifications sur la branche de fusion"`
      
  * **Revenir sur main et effectuer la fusion**
     * **commandes**
        * `git checkout main`
        * `git merge branche-merge -m "Merge de la branche-merge"`
      * **retour du terminal**
         * `PS C:\Users\Mastermein\Desktop\clone A\depot-d-essaie> git checkout main
Switched to branch 'main'
Your branch is up to date with 'origin/main'.
PS C:\Users\Mastermein\Desktop\clone A\depot-d-essaie> git merge branche-merge -m "Merge de la branche-merge"
Updating 5561224..b3a88a7
Fast-forward (no commit created; -m option ignored)
 fichiers d'essai/main.cpp | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)`

* **Envoyer les modifications vers GitHub**
  * **commande**
    * `git push origin main`
  * **retour du terminal**
    * `PS C:\Users\Mastermein\Desktop\clone A\depot-d-essaie> git push origin main
Enumerating objects: 7, done.
Counting objects: 100% (7/7), done.
Delta compression using up to 4 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (4/4), 370 bytes | 370.00 KiB/s, done.
Total 4 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/mastermein/depot-d-essaie.git
   5561224..b3a88a7  main -> main`
        
  
  ### B- Intégration en rejouant (git rebase) : sur le clone B

   * **synchroniser le clone avec le serveur**
      * **commande**
         * `git pull origin main`
       * **retour du terminal**
          * `PS C:\Users\Mastermein\Desktop\clone B\depot-d-essaie> git pull origin main
remote: Enumerating objects: 7, done.
remote: Counting objects: 100% (7/7), done.
remote: Compressing objects: 100% (1/1), done.
remote: Total 4 (delta 1), reused 4 (delta 1), pack-reused 0 (from 0)
Unpacking objects: 100% (4/4), 350 bytes | 10.00 KiB/s, done.
From https://github.com/mastermein/depot-d-essaie
 * branch            main       -> FETCH_HEAD
   5561224..b3a88a7  main       -> origin/main
Updating 5561224..b3a88a7
Fast-forward
 fichiers d'essai/main.cpp | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)`
   * **Créer la branche "branche-rebase" et basculer dessus**
      * **commande**
        * `git checkout -b branche-rebase`
      * **retour du terminal**
        * `PS C:\Users\Mastermein\Desktop\clone B\depot-d-essaie> git checkout -b branche-rebase
Switched to a new branch 'branche-rebase'`

 * **Modifier le fichier main.cpp, puis enregistrer le commit**
    * **modifiction**
       * **ligne 22** `    std::cout << "=== Fin du programme === , clone B , branche de rebase" << std::endl;`
     
    * **commandes git**
       * `git add .`
       * `git commit -m "Ajout de modifications sur la branche de rebase"`
    * **retour du terminal**
     * `PS C:\Users\Mastermein\Desktop\clone B\depot-d-essaie> git add .
PS C:\Users\Mastermein\Desktop\clone B\depot-d-essaie> git commit -m "Ajout de modifications sur la branche de rebase 2"
[branche-rebase 7b0f5f6] Ajout de modifications sur la branche de rebase 2
 1 file changed, 1 insertion(+), 1 deletion(-)`

* **Rejouer les commits de la branche par-dessus main**
   * **commande**
      * `git rebase main`
    * **retour du terminal**
     * `PS C:\Users\Mastermein\Desktop\clone B\depot-d-essaie> git rebase main
Current branch branche-rebase is up to date.`
    
* **Revenir sur main et valider l'alignement**
  * **commades**
     * `git checkout main`
     * `git merge branche-rebase`
  * **retour du terminal**
     * `PS C:\Users\Mastermein\Desktop\clone B\depot-d-essaie> git checkout main
Switched to branch 'main'
Your branch is up to date with 'origin/main'.
PS C:\Users\Mastermein\Desktop\clone B\depot-d-essaie> git merge branche-rebase
Updating b3a88a7..7b0f5f6
Fast-forward
 fichiers d'essai/main.cpp | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)`

* **Envoyer les modifications finales vers GitHub**
  * **commande**
     * **git push origin main**
  * **retour du terminal**
     * `PS C:\Users\Mastermein\Desktop\clone B\depot-d-essaie> git push origin main
Enumerating objects: 7, done.
Counting objects: 100% (7/7), done.
Delta compression using up to 4 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (4/4), 375 bytes | 375.00 KiB/s, done.
Total 4 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/mastermein/depot-d-essaie.git
   b3a88a7..7b0f5f6  main -> main`

## 4- Le graphe que je prefere

**suite a l'analyse des graphes produits par les deux types d'integration , je peux en conclure que le graphe que je prefere est celui de l'integration par fusion car il est constitues de bifurcations permettant de savoir de quelle branche provient une modification.**


