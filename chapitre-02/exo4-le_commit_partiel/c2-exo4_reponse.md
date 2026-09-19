## Modifiez deux choses sans rapport dans le même fichier, puis faites-en deux commits séparés avec git add -p. Vérifiez dans l'historique que chacun ne contient que son sujet.


## 1- preparation du fichier a modifier main.cpp

  * **contenu du fichier :**
    * **#include <iostream>

int main() {
    // Configuration de la vitesse
    float vitesseJoueur = 100.0f;
    
    // Affichage des informations
    std::cout << "Vitesse actuelle du joueur : " << vitesseJoueur << std::endl;
    std::cout << "Bienvenue dans le jeu !" << std::endl;

    return 0;
}
**

## 2- apport de deux modifications :
  * **ligne 5 :** 
    * **float vitesseJoueur = 250.0f;**
  * **ligne 9 :** 
    * **std::cout << "Bienvenue dans la galaxie !" << std::endl**

## 3- creations des deux commits

  * **reponse de git add -p main.cpp**
    *  **PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\chapitre-02\exo4-le_commit_partiel> git add -p main.cpp
diff --git a/chapitre-02/exo4-le_commit_partiel/main.cpp b/chapitre-02/exo4-le_commit_partiel/main.cpp
index b8c6037..78f372e 100644
--- a/chapitre-02/exo4-le_commit_partiel/main.cpp
+++ b/chapitre-02/exo4-le_commit_partiel/main.cpp
@@ -2,11 +2,11 @@

 int main() {
     // Configuration de la vitesse
-    float vitesseJoueur = 100.0f;
+    float vitesseJoueur = 250.0f;

     // Affichage des informations
     std::cout << "Vitesse actuelle du joueur : " << vitesseJoueur << std::endl;
-    std::cout << "Bienvenue dans le jeu !" << std::endl;
+    std::cout << "Bienvenue dans la galaxie !" << std::endl;

     return 0;
 }
\ No newline at end of file
(1/1) Stage this hunk [y,n,q,a,d,s,e,p,P,?]? s
Split into 2 hunks.
@@ -2,7 +2,7 @@

 int main() {
     // Configuration de la vitesse
-    float vitesseJoueur = 100.0f;
+    float vitesseJoueur = 250.0f;

     // Affichage des informations
     std::cout << "Vitesse actuelle du joueur : " << vitesseJoueur << std::endl;
(1/2) Stage this hunk [y,n,q,a,d,k,K,j,J,g,/,e,p,P,?]?
 **

 ## 4- Verification de l'historique de commits :
   * **commande :** git log --oneline

   * **retour du terminal :**
     * **PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\chapitre-02\exo4-le_commit_partiel> git log --oneline
dfa3308 (HEAD -> main) Mettre a jour le message d'accueil de l'interface
16e3ebc Ajuster la vitesse de deplacement du joueur
f9b55c5 (origin/main) initialisation de main.cpp
f52c225 fichier source
a2dc2e1 fichier de reponses
622c600 remise a zero
f61bc42 creation du fichier a modifier
c562c01 envoi du fichier de reponse
ef17bbd depot des fichier de reponse et a modifier
a771536 modification du main.cpp
9c8812d creation du fichier qui sera moidifier
6501b2b Create c2-exo2_reponse.md
ff2c5bb Creation des fichiers qui seont modfiers
011cf41 Ajout du fichier de reponse
39b5a22 Ajout du troisieme fichier
84c5d67 Ajout du deuxieme fichier
6cf0a92 Ajout du premier fichier
PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\chapitre-02\exo4-le_commit_partiel>**

## 5- constat :

 **on constate que bien que separes , chacun des deux commits ne contient que son sujet**
 * **commi 1:**
   * **16e3ebc Ajuster la vitesse de deplacement du joueur**
  * **commit 2:**
   * **dfa3308 (HEAD -> main) Mettre a jour le message d'accueil de l'interface**
