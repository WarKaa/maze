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
 * @file fichiers.c
 */

#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include <sys/stat.h>
#include "../../include/labyrinthe.h"
#include "../../include/utils.h"
#include "../../include/constantes.h"

void sauvegarder_labyrinthe(Labyrinthe laby)
{
	mkdir(CHEMIN_DATA, 0777);

	char *nom_fichier = concat_char(2, laby.nom, ".cfg");

	char *path = concat_char(2, CHEMIN_DATA, nom_fichier);
	FILE *file;
	file = fopen(path, "w");

	fprintf(file, "%d\n%d\n%d\n", laby.difficulte, laby.lignes, laby.colonnes);
	int i, j;
	for (i = 0; i < laby.lignes; i++)
	{

		for (j = 0; j < laby.colonnes; j++)
		{
			fprintf(file, "%d ", laby.labyrinthe[i][j]);
		}
		fprintf(file, "%c", '\n');
	}
	fclose(file);
	printf("Le fichier %s a été créé!\n", nom_fichier);

	free(nom_fichier);
}

Labyrinthe charger_labyrinthe()
{
	mkdir(CHEMIN_DATA, 0777);

	afficher_contenu_dossier(CHEMIN_DATA);

	char *nom_fichier;
	fflush(stdin);
	printf("Nom du fichier :");
	scanf("%ms", &nom_fichier);

	char *chemin;
	chemin = concat_char(2, CHEMIN_DATA, nom_fichier);

	FILE *fichier;
	fichier = fopen(chemin, "r");

	if (fichier == NULL)
	{
		// Rend moins sensible à la casse si l'utilisateur ne renseigne pas l'extension .cfg
		chemin = concat_char(2, chemin, ".cfg");
		nom_fichier = concat_char(2, nom_fichier, ".cfg");
		fichier = fopen(chemin, "r");
	}
	if (fichier == NULL)
	{
		return (Labyrinthe) {NULL, 0, 0, "", 0};
	}

	int lignes;
	int colonnes;
	int difficulte;

	fscanf(fichier, "%d", &difficulte);
	fscanf(fichier, "%d", &lignes);
	fscanf(fichier, "%d", &colonnes);

	int **plateau;
	plateau = alloue_matrice(lignes, colonnes, 0);

	int i, j;
	i = 0;
	j = 0;
	while (i < lignes && j < colonnes)
	{
		fscanf(fichier, "%d", &plateau[i][j]);
		j++;
		if (j == colonnes)
		{
			j = 0;
			i++;
		}
	}

	fclose(fichier);

	char *name;
	name = calloc(index_of(nom_fichier, ".") + 1, sizeof(char));
	strncpy(name, nom_fichier, index_of(nom_fichier, "."));
	return (Labyrinthe) {plateau, lignes, colonnes, name, difficulte};
}

