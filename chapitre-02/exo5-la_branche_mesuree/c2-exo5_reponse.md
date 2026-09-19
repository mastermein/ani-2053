
## Créez une branche, faites trois commits dessus, et mesurez la place que le dépôt a gagnée sur le disque. Expliquez le résultat.


## 1- mesurons la taille initiale du depot en kb

  * **commande :**
    * **(Get-ChildItem -Recurse .git | Measure-Object -Property Length -Sum).Sum / 1KB**
  * **retour du terminal**
    * **PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053> (Get-ChildItem -Recurse .git | Measure-Object -Property Length -Sum).Sum / 1KB
55.76171875**


## 2- creation d'une branche

 * **commande :** 
   * **git checkout -b exo5-branche**
 * **retour du terminal** 
   * **PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053> git checkout -b exo5-branche
Switched to a new branch 'exo5-branche'**

## 3- creation des 3 commits


  * **commit 1**
    * **commandes :**
      * **Set-Content chapitre-02\exo5-la_branche_mesuree\test.txt "Ligne 1"**
      * **git add .**
      * **git commit -m "Premier commit sur la branche : ajout ligne 1"**

    * **retour du terminal :**
      * **PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053> Set-Content chapitre-02\exo5-la_branche_mesuree\test.txt "Ligne 1"
PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053> git add .
PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053> git commit -m "Premier commit sur la branche : ajout ligne 1"
[exo5-branche 7a201ef] Premier commit sur la branche : ajout ligne 1
 2 files changed, 1 insertion(+)
 create mode 100644 chapitre-02/exo5-la_branche_mesuree/c2-exo5_reponse.md
 create mode 100644 chapitre-02/exo5-la_branche_mesuree/test.txt**

  * **commit 2**
     * **commandes :**
       * **Add-Content chapitre-02\exo5-la_branche_mesuree\test.txt "`nLigne 2"**
       * **git add .**
       * **git commit -m "Deuxieme commit sur la branche : ajout ligne 2"**
     * **retour du terminal :**
      * **PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053> Add-Content chapitre-02\exo5-la_branche_mesuree\test.txt "`nLigne 2"
PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053> git add .
warning: in the working copy of 'chapitre-02/exo5-la_branche_mesuree/test.txt', LF will be replaced by CRLF the next time Git touches it
PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053> git commit -m "Deuxieme commit sur la branche : ajout ligne 2"
[exo5-branche d65f4a2] Deuxieme commit sur la branche : ajout ligne 2
 1 file changed, 2 insertions(+)**

  * **commit 3**
     * **commandes :**
       * **Add-Content chapitre-02\exo5-la_branche_mesuree\test.txt "`nLigne 3"**
       * **git add .**
       * **git commit -m "Troisieme commit sur la branche : ajout ligne 3"**
    * **retour du terminal :**
      * **PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053> Add-Content chapitre-02\exo5-la_branche_mesuree\test.txt "`nLigne 3"
PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053> git add .
warning: in the working copy of 'chapitre-02/exo5-la_branche_mesuree/test.txt', LF will be replaced by CRLF the next time Git touches it
PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053> git commit -m "Troisieme commit sur la branche : ajout ligne 3"
[exo5-branche 12a0419] Troisieme commit sur la branche : ajout ligne 3
 1 file changed, 2 insertions(+)**


 ## 4- remesure de la taille du depot 

   * **commande :**
     * **(Get-ChildItem -Recurse .git | Measure-Object -Property Length -Sum).Sum / 1KB**

* **retour du terminal :**
      * **PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053> (Get-ChildItem -Recurse .git | Measure-Object -Property Length -Sum).Sum / 1KB
59.4794921875**

## 5- difference de tailles 

**La différence entre les deux tailles correspond uniquement au poids des métadonnées des commits et du texte ajouté, prouvant que la création d'une branche ne duplique pas le projet.**
