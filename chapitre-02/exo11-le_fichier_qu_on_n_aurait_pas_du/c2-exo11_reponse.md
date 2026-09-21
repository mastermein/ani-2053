
## Committez volontairement un fichier de dix mégaoctets dans votre dépôt d'essai. Retirez-le au commit suivant, puis mesurez la taille de .git. Concluez.

## 1- Taille initiale du .git.

  * **commande :**
    * **(Get-ChildItem -Recurse .git | Measure-Object -Property Length -Sum).Sum / 1MB**
  * **retour du terminal :**
    * **0.080744743347168**

## 2- commiter le fichier de 18.5 mo

  * **commande :**
    * **git add .**
    * **git commit -m "Ajout involontaire du gros fichier"**

  * **retour du terminal **
    * **PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053> git add .
PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053> git commit -m "Ajout involontaire du gros fichier"
[main 976aeae] Ajout involontaire du gros fichier**

## 3- Mesure 2 (après le commit)

 * **commande :**
    * **(Get-ChildItem -Recurse .git | Measure-Object -Property Length -Sum).Sum / 1MB**
  * **retour du terminal :**
    * **18.5204763412476**

## 4- Supprimer le fichier de l'espace de travail

 * **commande :**
   * **Remove-Item chapitre-02\exo11-le_fichier_qu_on_n_aurait_pas_du\Virtua_Cop.exe**

* **retour du terminal :**
  * **PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053> Remove-Item chapitre-02\exo11-le_fichier_qu_on_n_aurait_pas_du\Virtua_Cop.exe
PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053>**

## 5- Commiter la suppression

* **commande :**
   * **git add .**
   * **git commit -m "Suppression du gros fichier"**

* **retour du terminal :**
  * **PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053> git add .
PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053> git commit -m "Suppression du gros fichier"
[main 2209926] Suppression du gros fichier
 1 file changed, 0 insertions(+), 0 deletions(-)
 delete mode 100644 chapitre-02/exo11-le_fichier_qu_on_n_aurait_pas_du/Virtua_Cop.exe**

 ## 6- Mesure 3 (après la suppression)

 * **commande :**
    * **(Get-ChildItem -Recurse .git | Measure-Object -Property Length -Sum).Sum / 1MB**
  * **retour du terminal :**
    * **18.520845413208**


## 7- affichage des mesures 

 * **premiere mesure**
   * **0.080744743347168**

* **deuxieme mesure**
 * **18.5204763412476**

* **troisieme mesure**
  * **18.520845413208**

## 8- conclusion

**Même si un fichier est effacé dans le dossier de travail, Git le conserve définitivement dans son historique masqué (.git) pour pouvoir le restaurer au besoin, ce qui garde la taille du dépôt aussi lourde (~18,52 Mo).**