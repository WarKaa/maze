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
 * @file main.h
 * Fichier d'en-tête de main.c
 */

#ifndef PROJET_MAZE_MAIN_H
#define PROJET_MAZE_MAIN_H

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "utils.h"
#include "fichiers.h"
#include "jeu.h"
#include "score.h"
#include <ctype.h>

/**
 * Affiche le menu principal du jeu
 * @param nom du labyrinthe chargé, NULL si aucun labyrinthe chargé
 */
void afficher_menu(char *nom);

/**
 * Permet la navigation dans le menu
 */
void gerer_clavier_menu();

/**
 * Démarre le jeu
 */
void demarrer();

#endif //PROJET_MAZE_MAIN_H

