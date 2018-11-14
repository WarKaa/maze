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
 * @file labyrinthe.c
 */

#include "../../include/labyrinthe.h"

void replace(Labyrinthe laby, int x, int y, int ancienne_valeur,
			 int nouvelle_valeur)
{
	laby.labyrinthe[x][y] = nouvelle_valeur;

	if (laby.labyrinthe[x + 1][y] == ancienne_valeur)
	{
		replace(laby, x + 1, y, ancienne_valeur, nouvelle_valeur);
	}
	if (laby.labyrinthe[x - 1][y] == ancienne_valeur)
	{
		replace(laby, x - 1, y, ancienne_valeur, nouvelle_valeur);
	}
	if (laby.labyrinthe[x][y + 1] == ancienne_valeur)
	{
		replace(laby, x, y + 1, ancienne_valeur, nouvelle_valeur);
	}
	if (laby.labyrinthe[x][y - 1] == ancienne_valeur)
	{
		replace(laby, x, y - 1, ancienne_valeur, nouvelle_valeur);
	}
}

void afficher_labyrinthe(Labyrinthe laby)
{
	int i;
	for (i = 0; i < laby.lignes; i++)
	{
		int j;
		for (j = 0; j < laby.colonnes; j++)
		{
			switch (laby.labyrinthe[i][j])
			{
				case MUR:
					printf("█");
					break;
				case BONUS:
					printf("+");
					break;
				case MALUS:
					printf("-");
					break;
				default:
				{
					printf(" ");
				}
			}
		}
		printf("\n");
	}
}

void afficher_labyrinthe_en_jeu(Labyrinthe laby, Entitee entitee)
{
	int i;
	for (i = 0; i < laby.lignes; i++)
	{
		int j;
		for (j = 0; j < laby.colonnes; j++)
		{

			if (il_y_a_entitee(entitee,
							   (Coordonnee) {j, i}) // Affichage entitees
				|| (entitee.joueur.x == j && entitee.joueur.y == i))
			{
				if (entitee.joueur.x == j && entitee.joueur.y == i)
				{
					printf("o");
				}
				else
				{

					int k;
					bool ogre_trouve;
					ogre_trouve = false;

					for (k = 0; k < entitee.nb_ogres; k++)
					{
						if (entitee.ogres[k].x == j && entitee.ogres[k].y == i)
						{
							printf("O");
							ogre_trouve = true;
							break;
						}
					}

					if (!ogre_trouve)
					{
						for (k = 0; k < entitee.nb_fantomes; k++)
						{
							if (entitee.fantome[k].x == j
								&& entitee.fantome[k].y == i)
							{
								printf("F");
								break;
							}
						}
					}
				}
			}
			else // Affichage mur et bonus malus
			{
				switch (laby.labyrinthe[i][j])
				{
					case MUR:
						printf("█");
						break;
					case BONUS:
						printf("+");
						break;
					case MALUS:
						printf("-");
						break;
					default:
					{
						printf(" ");
					}
				}
			}
		}
		printf("\n");
	}
}


void init_bonus_malus(Labyrinthe laby)
{
	int nbcases;
	int nb_bonus_malus;
	int nb_bonus;
	int nb_malus;
	int i;
	int random_i;
	int random_j;

	nbcases = ((laby.colonnes - 1) * (laby.lignes - 1)) / 2 - 1;
	nb_bonus_malus = nbcases / 8;
	nb_bonus = nb_bonus_malus / 4;
	nb_malus = (nb_bonus_malus * 3) / 4;
	i = 0;
	while (i < nb_bonus)
	{
		random_i = rand_int(1, laby.lignes - 2);
		random_j = rand_int(1, laby.colonnes - 2);
		if (laby.labyrinthe[random_i][random_j] == CASE_LIBRE)
		{
			laby.labyrinthe[random_i][random_j] = BONUS;
			i++;
		}
	}
	i = 0;
	while (i < nb_malus)
	{
		random_i = rand_int(1, laby.lignes - 2);
		random_j = rand_int(1, laby.colonnes - 2);
		if (laby.labyrinthe[random_i][random_j] == CASE_LIBRE)
		{
			laby.labyrinthe[random_i][random_j] = MALUS;
			i++;
		}
	}
}

void enlever_murs_aleatoire(Labyrinthe laby, int max)
{
	int nb_cases_a_supprimer, i, rand_i, rand_j;

	i = 0;
	while (i < max)
	{
		int alea_i = rand_int(1, laby.lignes - 2);
		int alea_j = rand_int(1, laby.colonnes - 2);

		if (laby.labyrinthe[alea_i][alea_j] == -1)
		{
			int value;
			if (laby.labyrinthe[alea_i - 1][alea_j] != -1
				&& laby.labyrinthe[alea_i + 1][alea_j]
				   != -1) // Si la case au dessus et en dessous n'est pas un mur
			{
				value = laby.labyrinthe[alea_i - 1][alea_j];
				if (laby.labyrinthe[alea_i + 1][alea_j]
					!= value) //Si la case en dessous n'est pas le meme chemin
				{
					laby.labyrinthe[alea_i][alea_j] = value;
					replace(laby, alea_i, alea_j,
							laby.labyrinthe[alea_i + 1][alea_j], value);
					i++;
				}
			}
			else if (laby.labyrinthe[alea_i][alea_j - 1] != -1
					 && laby.labyrinthe[alea_i][alea_j + 1]
						!= -1) // Si la case a gauche et droite n'est pas un mur
			{
				value = laby.labyrinthe[alea_i][alea_j - 1];
				if (laby.labyrinthe[alea_i][alea_j + 1]
					!= value)   // Si la case a droite n'est pas le meme chemin
				{
					laby.labyrinthe[alea_i][alea_j] = value;

					replace(laby, alea_i, alea_j,
							laby.labyrinthe[alea_i][alea_j + 1], value);
					i++;
				}
			}
		}
	}

	if (laby.difficulte == 2)
	{
		nb_cases_a_supprimer = (laby.lignes + laby.colonnes) / 5;
		i = 0;
		while (i < nb_cases_a_supprimer)
		{
			rand_i = rand_int(1, laby.lignes - 2);
			rand_j = rand_int(1, laby.colonnes - 2);

			if (laby.labyrinthe[rand_i][rand_j] == MUR
				&& ((laby.labyrinthe[rand_i + 1][rand_j] == MUR
					 && laby.labyrinthe[rand_i - 1][rand_j] == MUR
					 && laby.labyrinthe[rand_i][rand_j - 1] != MUR
					 && laby.labyrinthe[rand_i][rand_j + 1] != MUR)
					|| (laby.labyrinthe[rand_i][rand_j + 1] == MUR
						&& laby.labyrinthe[rand_i][rand_j - 1] == MUR
						&& laby.labyrinthe[rand_i + 1][rand_j] != MUR
						&& laby.labyrinthe[rand_i - 1][rand_j]
						   != MUR))) // On enleve seulement les murs qui ont deux murs adjacents opposés
			{
				laby.labyrinthe[rand_i][rand_j] = CASE_LIBRE;
				i++;
			}
		}
	}
}

Labyrinthe init_labyrinthe(int lignes, int colonnes, char *nom, int difficulte)
{
	Labyrinthe laby;
	int i, compteur;

	laby = (Labyrinthe) {alloue_matrice(lignes, colonnes, MUR), lignes,
						 colonnes, nom, difficulte};
	compteur = 1;
	for (i = 0; i < lignes; i++)
	{
		int j;
		for (j = 0; j < colonnes; j++)
		{
			if (i % 2 == 1 && j % 2 == 1)
			{
				laby.labyrinthe[i][j] = compteur++;
			}
		}
	}
	enlever_murs_aleatoire(laby, compteur - 2);
	replace(laby, 1, 1, laby.labyrinthe[1][1], CASE_LIBRE);

	laby.labyrinthe[1][0] = ENTREE;
	laby.labyrinthe[lignes - 2][colonnes - 1] = SORTIE;

	init_bonus_malus(laby);

	afficher_labyrinthe(laby);
	return laby;
}







