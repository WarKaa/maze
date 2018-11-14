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
 * @file structures.h
 * Contiens toutes les structures nécessaires au projet
 */


#ifndef PROJET_MAZE_STRUCTURES_H
#define PROJET_MAZE_STRUCTURES_H

#include "constantes.h"

typedef struct
{
	int **labyrinthe;
	int lignes;
	int colonnes;
	char *nom;
	int difficulte;
} Labyrinthe;


typedef struct
{
	int x;
	int y;
} Coordonnee;

typedef struct
{
	int nb_ogres;
	int nb_fantomes;
	Coordonnee joueur;
	Coordonnee *ogres;
	Coordonnee *fantome;
} Entitee;

typedef struct
{
	int score;
	char nom_utilisateur[NOM_UTILISATEUR];
} Score;

enum direction
{
	HAUT, DROIT, BAS, GAUCHE
};
#endif //PROJET_MAZE_STRUCTURES_H
