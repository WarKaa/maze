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
 * @file utils.c
 * Fonctions utilitaires
 */

#include "../../include/utils.h"

int *alloue_vecteur(int dimension, int val)
{
	int *tab;
	tab = malloc(dimension * sizeof(int));
	assert(tab != NULL);

	int i;
	for (i = 0; i < dimension; i++)
	{
		tab[i] = val;
	}
	return tab;
}


int **alloue_matrice(int lignes, int colonnes, int val)
{
	int **matrice;
	matrice = malloc(lignes * sizeof(int *));
	assert(matrice != NULL);

	int i;
	for (i = 0; i < lignes; i++)
	{
		matrice[i] = alloue_vecteur(colonnes, val);
	}

	return matrice;
}

int rand_int(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void afficher_contenu_dossier(char *directory)
{
	DIR *d;
	struct dirent *dir;
	d = opendir(directory);
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			printf("%s\n", dir->d_name);
		}
		closedir(d);
	}
}

int index_of(char *chaine, char *caractere)
{
	char *temp;
	temp = strstr(chaine, caractere);
	if (temp != NULL)
	{
		return temp - chaine;
	}
	return 0;
}

char *concat_char(int count, ...)
{
	char *final_string;
	va_list list;
	int size;
	int i;
	size = 0;
	va_start(list, count);
	for (i = 0; i < count; i++)
	{
		size += sizeof(va_arg(list, char *));
	}
	final_string = malloc(size + 1 /* +1 for the null-terminator */);
	assert(final_string != NULL);
	strcpy(final_string, va_arg(list, char *));
	for (i = 1; i < count; i++)
	{
		strcat(final_string, va_arg(list, char *));
	}
	return final_string;
}

void clear_console()
{
#if defined __WIN32__
	system ("cls");
#else
	system("clear");
#endif
}

void shuffle(int *array, int n)
{
	if (n > 1)
	{
		size_t i;
		for (i = 0; i < n - 1; i++)
		{
			size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
			int t = array[j];
			array[j] = array[i];
			array[i] = t;
		}
	}
}

void press_any_key_to_continue()
{
	printf("Tape n'importe quoi puis la touche ENTREE pour continuer...\n");
	char ch;
	scanf(" %c", &ch);
	clear_input_buffer();
}

void clear_input_buffer()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF)
	{
	}
}