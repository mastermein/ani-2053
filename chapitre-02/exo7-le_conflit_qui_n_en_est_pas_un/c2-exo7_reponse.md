
## Deux personnes modifient le même fichier, mais à deux endroits éloignés. Montrez que git assemble les deux sans rien demander.

## utilisateur 

  * **clone A** `C:\Users\Mastermein\Desktop\clone A\depot-d-essaie`
  * **clone B** `C:\Users\Mastermein\Desktop\clone B\depot-d-essaie`

## fichier `main.cpp`

 * **contenu :**
    * `#include <iostream>

// ==========================================
// DEBUT DU FICHIER : ZONE DE MODIFICATION A
// ==========================================
void afficherEntete() {
    std::cout << "=== Application C++ Demonstration Git ===" << std::endl;
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
    std::cout << "=== Fin du programme ===" << std::endl;
}

int main() {
    afficherEntete();
    traiterDonnees();
    afficherStatistiques();
    afficherPiedDePage();
    return 0;
}`


## modifications

 * **clone A**
    **ligne 7**
     * `    std::cout << "=== Application C++ Demonstration Git ===,  clone A" << std::endl;`

 * **clone B**
    * **ligne 22**
      * `    std::cout << "=== Fin du programme === ,  clone B" << std::endl;`



## push vers github

 * **clone B**
    * **commandes**
       * `git add .`
       * `git commit -m "modifcatons de l'utilisateur 1"`
       * `git push origin main`
    * **retour du terminal**
       * `PS C:\Users\Mastermein\Desktop\clone B\depot-d-essaie> git add .
PS C:\Users\Mastermein\Desktop\clone B\depot-d-essaie> git commit -m "modifcatons de l'utilisateur 1"
[main 54e9205] modifcatons de l'utilisateur 1
 1 file changed, 1 insertion(+), 1 deletion(-)
PS C:\Users\Mastermein\Desktop\clone B\depot-d-essaie> git push origin main
Enumerating objects: 7, done.
Counting objects: 100% (7/7), done.
Delta compression using up to 4 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (4/4), 360 bytes | 360.00 KiB/s, done.
Total 4 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/mastermein/depot-d-essaie.git
   9c2a97c..54e9205  main -> main`

 * **clone A**
    * **commandes**
       * `git add .`
       * `git commit -m "modifcatons de l'utilisateur 2"`
       * `git pull origin main`
       * `git push origin main` 
    * **retour du terminal**
       * `PS C:\Users\Mastermein\Desktop\clone A\depot-d-essaie> git add .
PS C:\Users\Mastermein\Desktop\clone A\depot-d-essaie> git commit -m "modifcatons de l'utilisateur 2"
[main 1277e20] modifcatons de l'utilisateur 2
 1 file changed, 1 insertion(+), 1 deletion(-)
PS C:\Users\Mastermein\Desktop\clone A\depot-d-essaie> git push origin main
To https://github.com/mastermein/depot-d-essaie.git
PS C:\Users\Mastermein\Desktop\clone A\depot-d-essaie> git pull origin main
remote: Enumerating objects: 7, done.
remote: Counting objects: 100% (7/7), done.
remote: Compressing objects: 100% (1/1), done.
remote: Total 4 (delta 1), reused 4 (delta 1), pack-reused 0 (from 0)
Unpacking objects: 100% (4/4), 340 bytes | 8.00 KiB/s, done.
From https://github.com/mastermein/depot-d-essaie
 * branch            main       -> FETCH_HEAD
   9c2a97c..54e9205  main       -> origin/main
Auto-merging fichiers d'essai/main.cpp
Merge made by the 'ort' strategy.
 fichiers d'essai/main.cpp | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)
PS C:\Users\Mastermein\Desktop\clone A\depot-d-essaie> git push origin main
fatal: unable to access 'https://github.com/mastermein/depot-d-essaie.git/': Could not resolve host: github.com`
