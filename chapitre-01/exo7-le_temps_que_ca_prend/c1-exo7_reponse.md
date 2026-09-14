
## Chronométrez une construction complète, puis une seconde lancée juste après sans rien modifier

**Commande utilisee** :  **jenga build --target NKMath**

## premier retour de la commande :
   - **PS C:\Users\Mastermein\Desktop\Teuguis\Nkentseu> jenga build --target NKMath

╔══════════════════════════════════════════════════════════════════╗
║                                                                  ║
║                ██╗███████╗███╗   ██╗ ██████╗  █████╗             ║
║                ██║██╔════╝████╗  ██║██╔════╝ ██╔══██╗            ║
║                ██║█████╗  ██╔██╗ ██║██║  ███╗███████║            ║
║           ██   ██║██╔══╝  ██║╚██╗██║██║   ██║██╔══██║            ║
║           ╚█████╔╝███████╗██║ ╚████║╚██████╔╝██║  ██║            ║
║            ╚════╝ ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝            ║
║                                                                  ║
║             Multi-platform C/C++ Build System v2.8.0             ║
║                                                                  ║
╚══════════════════════════════════════════════════════════════════╝

Loading workspace...
[NKCode] ATTENTION : aucun wheel Jenga trouve (dist/*.whl) -> le paquet n'aura PAS de Jenga embarque, et les boutons Construire/Executer seront inoperants. Produisez-le avec ./cri.sh dans le depot Jenga.

Configuration: Debug
Target:        Windows x86_64
Toolchain:     clang-mingw

Build Order (5 projects):
  1. NKPlatform [STATIC_LIB] →
  2. NKCore [STATIC_LIB] (depends: NKPlatform) →
  3. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) →
  4. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) →
  5. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPlatform                                                       Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 7 source file(s)
✓   [1/7] Compiled: NkArchDetect.cpp
✓   [2/7] Compiled: NkCGXDetect.cpp
✓   [3/7] Compiled: NkCompilerDetect.cpp
✓   [4/7] Compiled: NkEndianness.cpp
✓   [5/7] Compiled: NkEnv.cpp
✓   [6/7] Compiled: NkCPUFeatures.cpp
✓   [7/7] Compiled: NkPlatformConfig.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKPlatform.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.66s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCore                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓   [1/5] Compiled: NkLimits.cpp
✓   [2/5] Compiled: NkAssert.cpp
✓   [3/5] Compiled: NkTraits.cpp
✓   [4/5] Compiled: NkBits.cpp
✓   [5/5] Compiled: NkPlatform.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKCore.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.82s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMemory                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓   [1/14] Compiled: NkContainerAllocator.cpp
✓   [2/14] Compiled: NkFunction.cpp
✓   [3/14] Compiled: NkGc.cpp
✓   [4/14] Compiled: NkFunctionSIMD.cpp
✓   [5/14] Compiled: NkGlobalOperators.cpp
✓   [6/14] Compiled: NkHash.cpp
✓   [7/14] Compiled: NkMemory.cpp
✓   [8/14] Compiled: NkMultiLevelAllocator.cpp
✓   [9/14] Compiled: NkPoolAllocator.cpp
✓   [10/14] Compiled: NkProfiler.cpp
✓   [11/14] Compiled: NkTracker.cpp
✓   [12/14] Compiled: NkTag.cpp
✓   [13/14] Compiled: NkUtils.cpp
✓   [14/14] Compiled: NkAllocator.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKMemory.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.78s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKContainers                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 43 source file(s)
✓   [1/43] Compiled: NkBTree.cpp
✓   [2/43] Compiled: NkBinaryTree.cpp
✓   [3/43] Compiled: NkHashMap.cpp
✓   [4/43] Compiled: NkMap.cpp
✓   [5/43] Compiled: NkPriorityQueue.cpp
✓   [6/43] Compiled: NkSet.cpp
✓   [7/43] Compiled: NkUnorderedMap.cpp
✓   [8/43] Compiled: NkTrie.cpp
✓   [9/43] Compiled: NkUnorderedSet.cpp
✓   [10/43] Compiled: NkArray.cpp
✓   [11/43] Compiled: NkPool.cpp
✓   [12/43] Compiled: NkRingBuffer.cpp
✓   [13/43] Compiled: NkFunction.cpp
✓   [14/43] Compiled: NkBind.cpp
✓   [15/43] Compiled: NkTuple.cpp
✓   [16/43] Compiled: NkPair.cpp
✓   [17/43] Compiled: NkFunctional.cpp
✓   [18/43] Compiled: NkIterator.cpp
✓   [19/43] Compiled: NkInitializerList.cpp
✓   [20/43] Compiled: NkContainers.cpp
✓   [21/43] Compiled: NkDeque.cpp
✓   [22/43] Compiled: NkDoubleList.cpp
✓   [23/43] Compiled: NkList.cpp
✓   [24/43] Compiled: NkVector.cpp
✓   [25/43] Compiled: NkGraph.cpp
✓   [26/43] Compiled: NkQuadTree.cpp
✓   [27/43] Compiled: NkASCII.cpp
✓   [28/43] Compiled: NkEncoding.cpp
✓   [29/43] Compiled: NkBase64.cpp
✓   [30/43] Compiled: NkUTF16.cpp
✓   [31/43] Compiled: NkUTF32.cpp
✓   [32/43] Compiled: NkUTF8.cpp
✓   [33/43] Compiled: NkBasicString.cpp
✓   [34/43] Compiled: NkFormat.cpp
✓   [35/43] Compiled: NkString.cpp
✓   [36/43] Compiled: NkStringBuilder.cpp
✓   [37/43] Compiled: NkStringHash.cpp
✓   [38/43] Compiled: NkOptional.cpp
✓   [39/43] Compiled: NkStringUtils.cpp
✓   [40/43] Compiled: NkResult.cpp
✓   [41/43] Compiled: NkStringView.cpp
✓   [42/43] Compiled: NkVariant.cpp
✓   [43/43] Compiled: NkSpan.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKContainers.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 7.49s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMath                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓   [1/12] Compiled: NkAngle.cpp
✓   [2/12] Compiled: NkEulerAngle.cpp
✓   [3/12] Compiled: NkColor.cpp
✓   [4/12] Compiled: NkFunctions.cpp
✓   [5/12] Compiled: NkMat.cpp
✓   [6/12] Compiled: NkQuat.cpp
✓   [7/12] Compiled: NkRandom.cpp
✓   [8/12] Compiled: NkRange.cpp
✓   [9/12] Compiled: NkRectangle.cpp
✓   [10/12] Compiled: NkSIMD.cpp
✓   [11/12] Compiled: NkSegment.cpp
✓   [12/12] Compiled: NkVec.cpp
ℹ Linking...
✓ Built: Build\Lib\Debug-Windows\NKMath.lib

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                            Time: 12.23s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED
════════════════════════════════════════════════════════════════════════════════
Projects Built:  5/5
Time:           27.03s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════**

## deuxieme retour de commande :
   - **PS C:\Users\Mastermein\Desktop\Teuguis\Nkentseu> jenga build --target NKMath

╔══════════════════════════════════════════════════════════════════╗
║                                                                  ║
║                ██╗███████╗███╗   ██╗ ██████╗  █████╗             ║
║                ██║██╔════╝████╗  ██║██╔════╝ ██╔══██╗            ║
║                ██║█████╗  ██╔██╗ ██║██║  ███╗███████║            ║
║           ██   ██║██╔══╝  ██║╚██╗██║██║   ██║██╔══██║            ║
║           ╚█████╔╝███████╗██║ ╚████║╚██████╔╝██║  ██║            ║
║            ╚════╝ ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝            ║
║                                                                  ║
║             Multi-platform C/C++ Build System v2.8.0             ║
║                                                                  ║
╚══════════════════════════════════════════════════════════════════╝

Loading workspace...
[NKCode] ATTENTION : aucun wheel Jenga trouve (dist/*.whl) -> le paquet n'aura PAS de Jenga embarque, et les boutons Construire/Executer seront inoperants. Produisez-le avec ./cri.sh dans le depot Jenga.

Configuration: Debug
Target:        Windows x86_64
Toolchain:     clang-mingw

Build Order (5 projects):
  1. NKPlatform [STATIC_LIB] →
  2. NKCore [STATIC_LIB] (depends: NKPlatform) →
  3. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) →
  4. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) →
  5. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPlatform                                                       Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 7 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.04s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCore                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.04s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMemory                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.17s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKContainers                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 43 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 2.63s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMath                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 1.06s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED
════════════════════════════════════════════════════════════════════════════════
Projects Built:  5/5
Time:           3.99s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════**

## comparaisons

-**premere commande** : 27.03s
-**deuxieme commande** : 3.99s

## Explication de l'ecart :

**Lors du premier build (27.03s) :** Jenga doit compiler l'integralite des fichiers sources, de toutes les dépendances pour générer les fichiers objets et assembler les bibliothèques.

**Lors du second build (3.99s) :** Aucun fichier source n'ayant ete modifie, Jenga affiche **All files up to date** pour chaque projet. Il saute la phase de compilation du code C++ et effectue uniquement les verifications de dependances et de mise a jour, ce qui reduit considerablement le temps d'execution.
