
## Redigez, pour un groupe de quatre etudiants, les regles git du projet : nommage des branches, contenu d'un commit, qui relit quoi, ce qui est interdit, et ce qu'on fait quand quelqu'un casse la branche principale. Une page, applicable des demain.

## 1. Nommage des branches
* Il est strictement **interdit de travailler directement sur `main`**.
* Chaque fonctionnalité ou correction doit se faire sur une branche dédiée.
* **Format des noms de branches :** `<type>/<prenom>-<description_courte>`
  * *Exemples :* 
    * `feature/brayan-menu-pause`
    * `fix/alex-bug-collisions`
    * `docs/julie-readme`



## 2. Contenu et format d'un commit
* **Un commit** = un seul sujet / une seule modification cohérente.
* **Format du message :** Verbe à l'impératif + description claire du "pourquoi".
  * *Exemple :* `Ajouter le calcul du score de fin de partie` (pas de messages flous comme *"Update"* ou *"Fix"*).
* Ne commiter aucun fichier lourd temporaire, exécutable compilé ou configuration personnelle.



## 3. Relecture du code 
* Aucun code ne rejoint la branche `main` sans au moins **une relecture obligatoire par un autre membre de l'équipe** via une Pull Request (PR).
* Le relecteur vérifie :
  1. Que le code fonctionne et ne casse rien.
  2. Que le message du commit suit les règles du projet.



## 4. Ce qui est STRICTEMENT INTERDIT 
1. **Push avec l'option `--force`** sur `main`.
2. **Commiter directement sur `main`** sans passer par une branche et une Pull Request.
3. **Commiter des secrets** (mots de passe, clés d'API).
4. **Commiter des fichiers binaires lourds** (vidéos, assets non optimisés, exécutables).



## 5. Procédure d'urgence : Si la branche principale `main` est cassée 
Si un bug critique survient sur `main` après une fusion :

1. **Alerter immédiatement l'équipe** sur le canal de discussion (Discord/Teams).
2. **Geler les ajouts :** Interdiction de fusionner toute autre branche vers `main` tant que le problème n'est pas résolu.
3. **Annuler le commit problématique :**
   * Utiliser `git revert <hash_du_commit>` pour annuler proprement les modifications sans effacer l'historique.
4. **Analyser et corriger sur une branche `hotfix` :**
   * Créer une branche `hotfix/description-bug`, corriger le problème localement, faire relire rapidement par un coéquipier, puis refusionner sur `main`.
