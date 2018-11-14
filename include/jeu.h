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
 * @file jeu.h
 * Fichier d'en-tête de jeu.c
 */

#ifndef PROJET_MAZE_JEU_H
#define PROJET_MAZE_JEU_H

#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include "labyrinthe.h"
#include "constantes.h"
#include "structures.h"
#include "entitees.h"
#include "utils.h"
#include "score.h"

#endif

/**
 * Commence la partie du labyrinthe
 * @param laby le labyrinthe auquel on veut jouer
 */
void jouer(Labyrinthe *laby);
