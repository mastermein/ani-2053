
## Introduisez une faute de syntaxe dans un fichier de NKMath et reconstruisez.

**fichier utiliser :** **C:\Users\Mastermein\Desktop\Teuguis\Nkentseu\Kernel\Foundation\NKMath\src\NKMath\NkMath.h**

**Commande de construction :** **jenga build --target NKMath**

**Erreur ajouter :** **ligne 82 : erreur_de_compilation;**

**Temps mis par la construction pour s'arreter :** **34.95s**

**Les projets ayant quand meme etes construits :** 
  * **NKPlatform**
  * **NKCore**
  * **NKMemory**
  * **NKContainers**

**Le mesage d'erreur nous apprend que concernant l'ordre de construction :**
  * **Les projets sont compiles du bas vers le haut du graphe. NKMath n'est lance qu'une fois ses 4 dependances (NKPlatform, NKCore, NKMemory, NKContainers) terminees avec succes.**
