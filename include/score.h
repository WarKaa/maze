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
 * @file scores.h
 * Fichier d'en-tête de score.c
 */



#include "labyrinthe.h"
#include "utils.h"
#include "constantes.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#ifndef PROJET_MAZE_SCORE_H
#define PROJET_MAZE_SCORE_H

#endif //PROJET_MAZE_SCORE_H

/**
 * Retourne le chemin/path vers le fichier de score du labyrinthe
 * @param laby le labyrinthe
 * @return le chemin
 */
char *get_chemin_score(Labyrinthe laby);

/**
 * Affiche le score des joueurs du labyrinthe
 * @param scores tableau de scores
 * @param nb_scores nombre de scores
 */
void affiche_score(Score *scores, int nb_scores);

/**
 * Charge les scores depuis un fichier binaire
 * @param laby le labyrinthe
 * @param nb_score nombre de scores
 * @return tableau de scores
 */
Score *charger_score(Labyrinthe laby, int *nb_score);

/**
 * Sauvegarde les scores dans un fichier binaire
 * @param laby le plateau de jeu
 * @param scores tableau de scores
 * @param nb_scores nombre de scores
 */
void sauvegarder_scores(Labyrinthe laby, Score *scores, int nb_scores);

/**
 * Compare deux scores
 * @param sc1
 * @param sc2
 * @return si sc1 > sc2, on retourne 1 sinon -1
 */
int compare_score(const void *sc1, const void *sc2);

/**
 * Sauvegarde un nouveau score
 * @param laby le plateau de jeu
 * @param score du joueur
 */
void sauvegarder_nouveau_score(Labyrinthe laby, int score);