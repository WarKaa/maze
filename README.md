# Compte rendu de projet

> Ce projet est un projet en C réalisé sous Clion par **Julien LE PECHEUR** - *2018-10-26* - [jlepecheur@ecole.ensicaen.fr](jlepecheur@ecole.ensicaen.fr)

## Manuel joueur

### 1. Bien commencer
Pour lancer le programme sous Linux:
* L'éxécutable se situe dans le dossier `cmake-build-debug`
```
./projet_maze
```

### 2. Le jeu

#### 2.1 Le menu principal
Une fois le jeu lancé, un menu apparait.\
Des chiffres sont indiqués pour accéder aux différentes fonctionnalités

```
# LABYRINTHE
###########################
[1] Créer un labyrinthe
[2] Charger un labyrinthe
[3] Jouer
[4] Scores
[5] Quitter
###########################
```

Il vous suffit de taper le chiffre voulu puis la touche <kbd>ENTREE</kbd>

<span style="color:red">**Important !**\
Les fonctionnalités `Jouer` et `Scores` ont besoins d'avoir un labyrinthe de chargé au préalable.
</span>

#### 2.2 Le labyrinthe

##### a) La difficulté
Il existe deux niveaux de difficulté dans ce jeux:

* Niveau 1: un labyrinthe parfait (un seul chemin possible) avec des bonus/malus
* Niveau 2: un labyrinthe avec plusieurs chemins possible, pleins de monstres pour vous gêner, et des bonus/malus

Les fantômes peuvent traverser les murs d'un d'épaisseur.\
Les ogres possèdent les mêmes déplacement que le joueurs mais ils sont avides de richesse et restent près des bonus dès qu'ils en croisent un.


Le choix de la difficulté est disponible à la création du labyrinthe ( [1] dans le menu principal).

##### b) Déplacement du joueur

Il y a quatre déplacements possibles dans le jeu:

* **z** : pour aller en **haut**
* **q** : pour aller à **gauche**
* **s** : pour aller en **bas**
* **d** : pour aller à **droite**

Il faut valider son déplacement avec la touche <kbd>**ENTREE**</kbd>

##### c) Le score

Il existe un système de score dans le labyrinthe.\
L'objectif est d'avoir le moins de points possible à la sortie du labyrinthe qui se situe en bas à droite du labyrinthe.

* Un déplacement (valide ou non) donne 1 point
* Marcher sur un malus donne 5 points
* Marcher sur un bonus **enlève** 10 points

A la fin de la partie, si vous avez un bon score (dans les 10 meilleurs), le programme vous invitera à saisir votre nom. Vous serez ainsi classé dans le tableau des scores pour ce labyrinthe.

## Manuel développeur

### 1. Les étapes
Les 4 étapes ont été réalisées, c'est à dire:

* générer un labyrinthe parfait
* créer un labyrinthe avec des paramètres (lignes, colonnes et nom) définis par l'utilisateur
* charger un labyrinthe préalablement crée
* joueur un labyrinthe préalablement chargé
* ajouter des bonus/malus et un système de score
* ajouter un niveau de difficulté (proposer plusieurs chemins possible et ajouts des monstres)

### 2. L'architecture du projet

```
projet_maze
│
└───cmake-build-debug       -> dossier où sont stockés les éxécutables générés par CLion
│
└───doc -> documentation
|   | Doxyfile
|
└───include                 -> fichiers d'en-tête
|   | constantes.h
|   | entitees.h
|   | fichiers.h
|   | jeu.h
|   | labyrinthe.h
|   | main.h
|   | score.h
|   | structures.h
|   | utils.h
|
└───src
|   └───labyrinthe
|   |   | entitess.c -> gère le joueur et les monstres
|   |   | fichiers.c -> gère la sauvegarde et chargement du labyrinthe
|   |   | jeu.c     -> gère le jeu du labyrinthe
|   |   | labyrinthe.c -> gère la génération/affichage du labyrinthe
|   |   | scores.c -> gère la sauvegarde/chargement/affichage des scores
|   |  
|   └───utils
|   |   | utils.c -> fonctions utilitaires
|   |
|   | main.c    -> menu principal
|
| CMakeLists.txt -> NE PAS SUPPRIMER nécéssaire à CLion pour compiler
| compte_rendu.md
```

### 3. Limitations

Les fichiers labyrinthe générés et stockés dans /data/ sont écris en clair. Par conséquent, une personne mal intentionnée pourrait modifier le fichier du labyrinthe par exemple.