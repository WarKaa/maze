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
 * @file utils.h
 * Fichier d'en-tête de utils.c
 */

#ifndef PROJET_MAZE_UTILS_H
#define PROJET_MAZE_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <dirent.h>
#include <libgen.h>
#include <memory.h>
#include <stdarg.h>

/**
 * Alloue en mémoire un tableau à une dimension et initialise à val
 * @param dimension taille du tableau
 * @param val valeur d'initialisation
 * @return tableau d'entier à une dimension
 */
int *alloue_vecteur(int dimension, int val);

/**
 * Alloue en mémoire un tableau à deux dimension et initialise à val
 * @param lignes nombre de lignes
 * @param colonnes nombre des colonnes
 * @param val valeur d'initialisation
 * @return tableau d'entier à deux dimension
 */
int **alloue_matrice(int lignes, int colonnes, int val);

/**
 * Donne une valeur entière aléatoire entre min inclu et max inclu
 * @param min
 * @param max
 * @return int
 */
int rand_int(int min, int max);

/**
 * Affiche le contenu d'un dossier
 * @param directory nom/chemin du dossier
 */
void afficher_contenu_dossier(char *directory);

/**
 * Retourne l'index de la première occurrence de caractere dans chaine
 * @param chaine c'est la chaine cible
 * @param caractere c'est la chaine que l'on veut trouver
 * @return int index
 */
int index_of(char *chaine, char *caractere);

/**
 * Concatène un nombre variable de chaine de caractère
 * @param count
 * @param ...
 * @return la chaine concaténé et déjà allouée
 */
char *concat_char(int count, ...);

/**
 * Permet de clear la console sous Windows ou Linux
 */
void clear_console();

/**
 * Mélange un tableau
 * @param array tableau
 * @param n nombre d'éléments du tableau
 */
void shuffle(int *array, int n);

/**
 * Met en attente le programme jusqu'à ce qu'on tape quelque chose puis ENTREE
 */
void press_any_key_to_continue();

/**
 * Permet de vider le buffer
 */
void clear_input_buffer();

#endif //PROJET_MAZE_UTILS_H
