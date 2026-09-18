## Modifiez un fichier, et affichez git status après chaque étape : modification, add, commit. Rendez les trois sorties et dites ce qui change entre elles.

## fichier qui sera modifier : main.cpp (vide des le depart)

## Modification apportees a main.cpp :
* **# include<iostream>

int main()
{
    std::cout<<"Bonjour";

    return 0;
}**

* **Retour de Git status :** 
 * **PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053> git status
On branch main
Your branch is up to date with 'origin/main'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   chapitre-02/exo2-les_trois_endroits/c2-exo2_reponse.md
        modified:   chapitre-02/exo2-les_trois_endroits/main.cpp

no changes added to commit (use "git add" and/or "git commit -a")**

## commande git add .

 * **Retour du git status :** 
  * **PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053> git add .
PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053> git status
On branch main
Your branch is up to date with 'origin/main'.

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   chapitre-02/exo2-les_trois_endroits/c2-exo2_reponse.md
        modified:   chapitre-02/exo2-les_trois_endroits/main.cpp**

## commande Git commit -m "modification du main.cpp"
 * **Retour du git status :**
  * **PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053> git commit -m "modification du main.cpp"
[main a771536] modification du main.cpp
 2 files changed, 22 insertions(+)
PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053> git status
On branch main
Your branch is ahead of 'origin/main' by 1 commit.
  (use "git push" to publish your local commits)

nothing to commit, working tree clean
PS C:\Users\Mastermein\Desktop\Teuguis\ani-2053>**