
## Prenez NKCanvas. Ouvrez son .jenga, relevez ses dépendances directes, puis celles de ses dépendances. Arrêtez-vous à deux niveaux et dessinez le graphe.

## 1. Dependances directes

 * **NKWindow**
 * **NKFont**
 * **NKImage**
 * **NKStream**
 * **NKTime**
 * **NKGlad**
 * **NKThreading**

## 2. Dependances indirectes

 * **NKWindow** $\rightarrow$ NKCore, NKPlatform, NKEvents, NKInput, NKMath
 * **NKFont** $\rightarrow$ NKCore, NKStream, NKImage, NKMath
 * **NKImage** $\rightarrow$ NKCore, NKStream, NKMemory
 * **NKStream** $\rightarrow$ NKCore, NKContainers
 * **NKTime** $\rightarrow$ NKCore, NKPlatform
 * **NKGlad** $\rightarrow$ *Aucune dépendance NK (module externe/loader autonome)*
 * **NKThreading** $\rightarrow$ NKCore, NKPlatform

## 3. Graphe de dependances


                 │ NKCanvas │
                 └────┬─────┘
┌──────────┬───────────┼───────────┬──────────┬───────────┬────────────┐
│          │           │           │          │           │            │
▼          ▼           ▼           ▼          ▼           ▼            ▼
┌──────────┐ ┌─────────┐ ┌─────────┐ ┌────────┐ ┌─────────┐ ┌──────────┐ ┌─────────────┐
│ NKWindow │ │ NKFont  │ │ NKImage │ │NKStream│ │ NKTime  │ │  NKGlad  │ │ NKThreading │
└────┬─────┘ └────┬────┘ └────┬────┘ └───┬────┘ └────┬────┘ └──────────┘ └──────┬──────┘
│            │           │          │           │                          │
├─► NKCore   ├─► NKCore  ├─► NKCore └─► NKCore  ├─► NKCore                 ├─► NKCore
├─► NKPlatform├─►NKStream ├─► NKStream          └─► NKPlatform             └─► NKPlatform
├─► NKEvents ├─► NKImage └─► NKMemory
├─► NKInput  └─► NKMath
└─► NKMath

## 4. Nombre total de projets a construire avant NKCanvas

Pour construire NKCanvas, il faut d'abord construire l'ensemble des dependances (Niveau 1 + Niveau 2) :

### Liste unique des projets prerequis :

1. **NKGlad**
2. **NKContainers**
3. **NKMemory**
4. **NKCore**
5. **NKPlatform**
6. **NKMath**
7. **NKEvents**
8. **NKInput**
9. **NKStream**
10. **NKImage**
11. **NKFont**
12. **NKTime**
13. **NKThreading**
14. **NKWindow**

Il faut construire **14 projets** avant de pouvoir construire NKCanvas.
