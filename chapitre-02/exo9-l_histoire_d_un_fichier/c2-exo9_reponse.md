## Choisissez un fichier du moteur et lisez son histoire complète. Reconstituez : sa création, les trois moments où il a le plus changé, et ce que les messages disent des raisons. Une page.

## 1 -fichier selectionne et arborescence 
  * **fichier :**
    * `NKMath.jenga`
  * **chemin :**
    * `C:\Users\Mastermein\Desktop\Teuguis\Nkentseu\Kernel\Foundation\NKMath`

## 2- historique du fichier

  * **commande**
    * `git log --oneline --follow -- NKMath.jenga`
 
* **retour du terminal**
  * `PS C:\Users\Mastermein\Desktop\Teuguis\Nkentseu\Kernel\Foundation\NKMath> git log --oneline --follow -- NKMath.jenga
f19260db chore: snapshot etat complet — reorg sources NKSL + Nkoung (plateforme de jeux 2D: toolkit responsive + Laser Puzzle + Labyrinthe) + Kernel/AI & Kernel/Bare (scaffolds docs) + wiki Foundation + scripts git/.gitattributes
1f26ef96 ﻿Session 2026-05-29 — D-NkImage, Android APK restauré, Harmony compile
d557314e update
52dbc593 update renderer system and pong game
1d4f072b refactor 002
9c49f79f bug fix vulkan opengl dx11 current bug software and dx12
f909152c Align Wayland jenga links/tests (renderer/camera/sandbox)
fe9b17f5 bug fix
a7e5448b add readme
088e403e bug fix
6760d538 update architecture
a41122c3 Restructure workspace: per-project jenga files + NKMath/NKTime/NKStream/NKMemory/NKRenderer`

## 3- voir le contenu exact des modifications apportées lors des différents commits

 * **commande**
   * `git log -p --follow -- NKMath.jenga`

* **retour du terminal**
  * `PS C:\Users\Mastermein\Desktop\Teuguis\Nkentseu\Kernel\Foundation\NKMath> git log -p --follow -- NKMath.jenga
commit f19260db440e184500d0187f517efc445e11f367
Author: LeTeguis <teuguiasederis@gmail.com>
Date:   Sun Jun 14 08:47:01 2026 +0100

    chore: snapshot etat complet — reorg sources NKSL + Nkoung (plateforme de jeux 2D: toolkit responsive + Laser Puzzle + Labyrinthe) + Kernel/AI & Kernel/Bare (scaffolds docs) + wiki Foundation + scripts git/.gitattributes

diff --git a/Kernel/Foundation/NKMath/NKMath.jenga b/Kernel/Foundation/NKMath/NKMath.jenga
index ec6aca9f..feb31fb9 100644
--- a/Kernel/Foundation/NKMath/NKMath.jenga
+++ b/Kernel/Foundation/NKMath/NKMath.jenga
@@ -11,30 +11,22 @@ Dépend de NKCore pour les primitives brutes (nk_uint8, etc.)
 """

 from Jenga import *
-from config import useglobalkind
-
-_TC_WINDOWS = "nk-windows-clang-mingw"
+from jengaconfig import *

 with project("NKMath"):
-    useglobalkind("math")
     language("C++")
     cppdialect("C++17")
     location(".")

-    includedirs([
-        "src",
-        "pch",
-        "%{NKCore.location}/src",
-        "%{NKPlatform.location}/src",
-        "%{NKContainers.location}/src",
-        "%{NKMemory.location}/src",
-    ])
+    nkentseudependson(
+        ["NKCore", "NKPlatform", "NKContainers", "NKMemory"],
+        selfexport="NKMath",
+        extra_includes=["src", "pch"],
+    )

     pchheader("pch/pch.h")
     pchsource("pch/pch.cpp")

-    dependson(["NKCore", "NKPlatform", "NKContainers", "NKMemory"])
-
     files([
         "src/NKMath/**.cpp",
         "src/NKMath/**.h",
@@ -48,7 +40,7 @@ with project("NKMath"):
:`

## 4-Création du fichier

 * **Commit :** `a41122c`
 * **Message du commit :** `Restructure workspace: per-project jenga files + NKMath/NKTime/NKStream/NKMemory/NKRenderer`

## 5-Les trois moments où le fichier a le plus changé

 * Moment 1 : Restructuration du workspace (Création)
   * **Commit :** `a41122c3`
   * **Message :** `Restructure workspace: per-project jenga files + NKMath/NKTime/NKStream/NKMemory/NKRenderer`
   * **Ce qui a changé & Raison :** Création initiale du fichier de build pour `NKMath` afin d'isoler la compilation du module mathématique.

 * Moment 2 : Alignement du système de build

   * **Commit :** `f909152c`
   * **Message :** `Align Wayland jenga links/tests (renderer/camera/sandbox)`
   * **Ce qui a changé & Raison :** Modification de la façon de lier les dépendances et tests pour s'aligner sur l'environnement Wayland.

 * Moment 3 : Réorganisation globale et refonte de la configuration 

   * **Commit :** `f19260db`
   * **Message :** `chore: snapshot etat complet -- reorg sources NKSL + Nkoung (plateforme de jeux 2D: toolkit responsive + Laser Puzzle + Labyrinthe) + Kernel/AI & Kernel/Bare (scaffolds docs) + wiki Foundation + scripts git/.gitattributes`
   * **Ce qui a changé & Raison :** Passage de la syntaxe `includedirs` à `nkentseudependson`, suppression des drapeaux spécifiques Windows/Clang-MinGW, et simplification de l'import de configuration pour utiliser la nouvelle fonction DSL `nkentseudependson`.