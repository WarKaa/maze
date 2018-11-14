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
 * @file entitees.h
 * Fichier d'en-tête de entitees.c
 */

#ifndef PROJET_MAZE_ENTITEES_H
#define PROJET_MAZE_ENTITEES_H

#include "labyrinthe.h"
#include "constantes.h"
#include "stdbool.h"
#include <stdlib.h>
#include "structures.h"
#include "utils.h"

/**
 * Initialise toutes les entitées du labyrinthe en fonction de sa difficulté et proportionnelement à sa taille
 * @param laby plateau de jeu
 * @return les entitées initialisées
 */
Entitee init_entitees(Labyrinthe laby);

/**
 * Determine si une cellule est valide pour une entitée
 * @param laby plateau de jeu
 * @param entitee structure possédant toutes les entitées crées
 * @param coor position actuelle de l'entitée que l'on vérifier
 * @param deltaX décalage de la position actuelle en X
 * @param deltaY décalage de la position actuelle en Y
 * @return true si la position est valide sinon false
 */
bool cellule_valide(Labyrinthe laby, Entitee entitee, Coordonnee coor,
					int deltaX, int deltaY);

/**
 * Bouge tous les monstres de la partie
 * @param laby plateau de jeu
 * @param entitee structure possédant toutes les entitées crées
 */
void bouger_monstre(Labyrinthe laby, Entitee *entitee);

/**
 * Bouge un fantome
 * @param laby plateau de jeu
 * @param entitee structure possédant toutes les entitées crées
 * @param fantome coordonnée actuelle de l'entitée fantome
 */
void bouger_fantome(Labyrinthe laby, Entitee entitee, Coordonnee *fantome);

/**
 * Bouge un ogre
 * @param laby plateau de jeu
 * @param entitee structure possédant toutes les entitées crées
 * @param ogre coordonnée actuelle de l'entitée ogre
 */
void bouger_ogre(Labyrinthe laby, Entitee entitee, Coordonnee *ogre);

/**
 * Bouge le joueur en fonction de son choix
 * @param laby plateau de jeu
 * @param entitee structure possédant toutes les entitées crées
 * @param deltaX décalage en X du joueur
 * @param deltaY décalage en Y du joueur
 * @return true si le joueur a bougé sinon false
 */
bool bouger(Labyrinthe laby, Entitee *entitee, int deltaX, int deltaY);

/**
 * Regarde s'il y a une entitée
 * @param entitee structure possédant toutes les entitées crées
 * @param coor coordonnée où l'on veut vérifier l'existance ou non d'une entitée
 * @return true s'il y a une entitée sinon false
 */
bool il_y_a_entitee(Entitee entitee, Coordonnee coor);

#endif //PROJET_MAZE_ENTITEES_H
