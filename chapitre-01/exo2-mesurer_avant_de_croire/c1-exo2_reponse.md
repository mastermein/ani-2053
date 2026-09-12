
## Compter les fichiers sources et les lignes du depot

j'ai utiliser les commandes suivantes sur powershell
- **(Get-ChildItem -Recurse -Include *.cpp,*.hpp,*.h,*.c).Count**: pour identifier le nombre total de fichers sources (.cpp, .hpp, .h, .c)
- **(Get-ChildItem -Recurse -Include *.cpp,*.hpp,*.h,*.c | Get-Content | Measure-Object -Line).Lines**: pour determiner le nombre total de lignes de code sans ces fichiers
de cela il en ressort:
   - **4706 fichiers sources**
   - **2502807 lignes de code**

Il est dit dans le chapitre que :**Le programme s'appelle Nkentseu. C'est un écosystème C++ pour créer des jeux et des logiciels : 2 641 fichiers source, 1 193 385 lignes, 221 fichiers de projet, 17 Go sur le disque.**   


les valeurs que j'a obtenues sont presque le double de celles de chapitre en raison de l'inclusion des fichiers headers et du dossier de build
