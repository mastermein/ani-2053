
## Depuis deux répertoires de travail, ou deux clones, modifiez la même ligne d'un même fichier et poussez l'un des deux. Provoquez le refus, puis le conflit, puis résolvez-le. Rendez chaque message affiché.

## 1- creation des deux utilisateur

  * **PC1 :**
    * `C:\Users\Mastermein\Desktop\clone A`

  * **PC2 :**
    * `C:\Users\Mastermein\Desktop\clone B`

## 2- commande de clonnage du depot 

  * `git clone https://github.com/mastermein/depot-d-essaie.git`


## 3- fichier a utiliser `main.cpp`

 * **chemin :**
   * `depot-d-essaie\fichiers d'essai`

 * **contenu :**
   * `
 # include<iostream>

`int main()
{
    std::cout<<"Bonjour";

    return 0;
}`

## 4- modificatons apportees 

  * **clone A:**
    * **ligne 6:** `std::cout<<"Bonjour, clone A";`

  * **clone B:** 
    * **ligne 6:** `std::cout<<"Bonjour, clone B`

## 5- Provoquer le refus

* ### a- push depuis clone A

  * **commandes**
    * `git add .`
    * `git commit -m "modification de la ligne 6 depuis clone A"`
    * `git push origin main`

  * **retour du terminal**
    * `PS C:\Users\Mastermein\Desktop\clone A> cd "depot-d-essaie"
PS C:\Users\Mastermein\Desktop\clone A\depot-d-essaie> git add .
PS C:\Users\Mastermein\Desktop\clone A\depot-d-essaie> git commit -m "modification de la ligne 6 depuis clone A"
[main 215d9e3] modification de la ligne 6 depuis clone A
 1 file changed, 1 insertion(+), 1 deletion(-)
PS C:\Users\Mastermein\Desktop\clone A\depot-d-essaie> git push origin main
Enumerating objects: 7, done.
Counting objects: 100% (7/7), done.
Delta compression using up to 4 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (4/4), 396 bytes | 396.00 KiB/s, done.
Total 4 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
To https://github.com/mastermein/depot-d-essaie.git
   4e025d6..215d9e3  main -> main`

* ### 6- push depuis clone B

  * **commandes**
    * `git add .`
    * `git commit -m "modification de la ligne 6 depuis clone B"`
    * `git push origin main`

  * **retour du terminal**
    * `PS C:\Users\Mastermein\Desktop\clone A\depot-d-essaie> cd "C:\Users\Mastermein\Desktop\clone B\depot-d-essaie"
PS C:\Users\Mastermein\Desktop\clone B\depot-d-essaie> git add .
PS C:\Users\Mastermein\Desktop\clone B\depot-d-essaie> git commit -m "modification de la ligne 6 depuis clone B"
[main 748d1f9] modification de la ligne 6 depuis clone B
 1 file changed, 1 insertion(+), 1 deletion(-)
PS C:\Users\Mastermein\Desktop\clone B\depot-d-essaie> git push origin main
To https://github.com/mastermein/depot-d-essaie.git
 ! [rejected]        main -> main (fetch first)
error: failed to push some refs to 'https://github.com/mastermein/depot-d-essaie.git'
hint: Updates were rejected because the remote contains work that you do not
hint: have locally. This is usually caused by another repository pushing to
hint: the same ref. If you want to integrate the remote changes, use
hint: 'git pull' before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.`


## 6- Provoquer le CONFLIT de fusion (dans clone B)

 * **commande :**
   * `git pull origin main`
 
 * **retour du terminal**
   * `PS C:\Users\Mastermein\Desktop\clone B\depot-d-essaie> git pull origin main
remote: Enumerating objects: 7, done.
remote: Counting objects: 100% (7/7), done.
remote: Compressing objects: 100% (2/2), done.
remote: Total 4 (delta 0), reused 4 (delta 0), pack-reused 0 (from 0)
Unpacking objects: 100% (4/4), 376 bytes | 15.00 KiB/s, done.
From https://github.com/mastermein/depot-d-essaie
 * branch            main       -> FETCH_HEAD
   4e025d6..215d9e3  main       -> origin/main
Auto-merging fichiers d'essai/main.cpp
CONFLICT (content): Merge conflict in fichiers d'essai/main.cpp
Automatic merge failed; fix conflicts and then commit the result.`

## 7- Régler le conflit et finaliser

  * **etat actuel de main.cpp dans clone B**
    * `
# include<iostream>

int main()
{
<<<<<<< HEAD
    std::cout<<"Bonjour, clone B";
=======
    std::cout<<"Bonjour , clone A";
>>>>>>> 215d9e3bbf767cee0350b95cafa76b5d6fd69bee

    return 0;
}
`


  * **suppression des lignes non desirees**

  * **Validez la résolution dans cloneB :**

     * **commandes**
        * `git add .`
        * `git commit -m "Resolution du conflit de fusion"`
        * `git push origin main`

     * **retour du terminal**

       * `PS C:\Users\Mastermein\Desktop\clone B\depot-d-essaie> git add .
PS C:\Users\Mastermein\Desktop\clone B\depot-d-essaie> git commit -m "Resolution du conflit de fusion"
[main 534530f] Resolution du conflit de fusion
PS C:\Users\Mastermein\Desktop\clone B\depot-d-essaie> git push origin main
Enumerating objects: 11, done.
Counting objects: 100% (11/11), done.
Delta compression using up to 4 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (5/5), 600 bytes | 300.00 KiB/s, done.
Total 5 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
To https://github.com/mastermein/depot-d-essaie.git
   215d9e3..534530f  main -> main`

   

    