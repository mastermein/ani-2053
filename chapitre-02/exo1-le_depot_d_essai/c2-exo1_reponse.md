

## Créez un dépôt vide, ajoutez trois fichiers en trois commits, et affichez l'historique en une ligne par commit. Puis affichez le graphe.


## 1 : Creation de depot vide
 
* **Commande :** **PS C:\Users\Mastermein> cd "C:\Users\Mastermein\Desktop\Teuguis\ani-2053"
PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053> mkdir chapitre-02/exo1-le_depot_d_essai**

* **Retour du terminal :** **  Répertoire : C:\Users\Mastermein\Desktop\Teuguis\ani-2053\chapitre-02


Mode                 LastWriteTime         Length Name
----                 -------------         ------ ----
d-----         9/16/2026   9:10 AM                exo1-le_depot_d_essai**

* **Transformer le dossier en projet Git :** 
  * **Commande :** **Git init**
  * **Retour du terminal :** **PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053> git init
Initialized empty Git repository in C:/Users/Mastermein/Desktop/Teuguis/ani-2053/.git/**

## 2 : creation des 3 fichiers 

* **Fichier 1 :**
  * **Commande :** 
    * **touch f1.txt**
    * **git add f1.txt**
    * **git commit -m "Ajout du premier fichier"**

  * **retour du terminal :**
    * **PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\chapitre-02\exo1-le_depot_d_essai> touch f1.txt
   PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\chapitre-02\exo1-le_depot_d_essai> git add f1.txt
   PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\chapitre-02\exo1-le_depot_d_essai> git commit -m "Ajout du premier fichier"
[master (root-commit) 6cf0a92] Ajout du premier fichier
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 chapitre-02/exo1-le_depot_d_essai/f1.txt
PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\chapitre-02\exo1-le_depot_d_essai>**

* **Fichier 2 :**
  * **Commande :** 
    * **touch f2.txt**
    * **git add f2.txt**
    * **git commit -m "Ajout du deuxieme fichier"**

  * **retour du terminal :** **PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\chapitre-02\exo1-le_depot_d_essai> touch f2.txt
PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\chapitre-02\exo1-le_depot_d_essai> git add f2.txt
PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\chapitre-02\exo1-le_depot_d_essai> git commit -m "Ajout du deuxieme fichier"
[master 84c5d67] Ajout du deuxieme fichier
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 chapitre-02/exo1-le_depot_d_essai/f2.txt**


* **Fichier 3 :**

  * **Commande :** 
    * **touch f3.txt**
    * **git add f3.txt**
    * **git commit -m "Ajout du troisieme fichier"**

  * **retour du terminal :** **PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\chapitre-02\exo1-le_depot_d_essai> touch f2.txt
PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\chapitre-02\exo1-le_depot_d_essai> git add f3.txt
PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\chapitre-02\exo1-le_depot_d_essai> git commit -m "Ajout du deuxieme fichier"
[master 84c5d67] Ajout du deuxieme fichier
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 chapitre-02/exo1-le_depot_d_essai/f2.txt**



## 3 : Affichage de l'historique 

   * **Commande :** 
     * **git log --oneline**

* **Retour du terminal :**
       * **PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\chapitre-02\exo1-le_depot_d_essai> git log --oneline
39b5a22 (HEAD -> master) Ajout du troisieme fichier
84c5d67 Ajout du deuxieme fichier
6cf0a92 Ajout du premier fichier**

## 3 : Affichage du graphe visuel

  * **Commande :**
    * **git log --oneline --graph**

  * **Retour du terminal :**
    * **PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053\chapitre-02\exo1-le_depot_d_essai> git log --oneline --graph
* 39b5a22 (HEAD -> master) Ajout du troisieme fichier
* 84c5d67 Ajout du deuxieme fichier
* 6cf0a92 Ajout du premier fichier**