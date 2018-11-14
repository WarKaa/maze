/*
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex
 *
 * This file is owned by ENSICAEN.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */

/**
 * @author Julien LE PECHEUR <jlepecheur@ecole.ensicaen.fr>
 * @version 1.0 27/10/2018
 */

/**
 * @file labyrinthe.h
 * Fichier d'en-tête de labyrinthe.c
 */

#include <stdio.h>
#include "structures.h"
#include "entitees.h"

#ifndef PROJET_MAZE_LABYRINTHE_H
#endif //PROJET_MAZE_LABYRINTHE_H

#define PROJET_MAZE_LABYRINTHE_H

/**
 * Fonction récursive qui remplace toutes les cases du labyrinthe ayant pour valeur a en b
 * @param laby
 * @param x
 * @param y
 * @param ancienne_valeur
 * @param nouvelle_valeur
 */
void replace(Labyrinthe laby, int x, int y, int ancienne_valeur,
			 int nouvelle_valeur);


/**
 * Affiche le labyrinthe brut sans entitées
 * @param laby le plateau de jeu
 */
void afficher_labyrinthe(Labyrinthe laby);

/**
 * Affiche le labyrinthe avec toutes les entitées
 * @param laby le plateau de jeu
 * @param entitee structure possédant toutes les entitées crées
 */
void afficher_labyrinthe_en_jeu(Labyrinthe laby, Entitee entitee);

/**
 * Initialise les bonus et malus dans le labyrinthe
 * @param laby le plateau de jeu
 */
void init_bonus_malus(Labyrinthe laby);

/**
 * Enleve des murs aléatoirement proportionellement à la taille du labyrinthe
 * @param laby plateau de jeu
 */
void enlever_murs_aleatoire(Labyrinthe laby, int max);

/**
 * Initialise le labyrinthe
 * @param lignes nombre de lignes du labyrinthe
 * @param colonnes nombre de colonnes du labyrinthe
 * @param nom du labyrinthe
 * @param difficulte du labyrinthe
 * @return le labyrinthe
 */
Labyrinthe init_labyrinthe(int lignes, int colonnes, char *nom, int difficulte);







