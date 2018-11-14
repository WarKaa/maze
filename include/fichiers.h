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
 * @file fichiers.h
 * Fichier d'en-tête de fichiers.c
 */

#include "structures.h"

#ifndef PROJET_MAZE_FICHIERS_H
#define PROJET_MAZE_FICHIERS_H

/**
 * Charge le labyrinthe à partir d'un fichier demandé à l'utilisateur au clavier
 * @return le labyrinthe chargé
 */
Labyrinthe charger_labyrinthe();

/**
 * Sauvegarde un labyrinthe dans un fichier au nom du labyrinthe
 * @param laby le labyrinthe à sauvegarder
 */
void sauvegarder_labyrinthe(Labyrinthe laby);

#endif //PROJET_MAZE_FICHIERS_H
