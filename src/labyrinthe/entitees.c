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
 * @file entitees.c
 */


#include "../../include/entitees.h"

Entitee init_entitees(Labyrinthe laby)
{
	if (laby.difficulte == 2)
	{
		int nb_monstres;
		int nb_ogres;
		int nb_fantomes;
		Coordonnee *ogres;
		Coordonnee *fantomes;

		nb_monstres =
				(((laby.colonnes - 1) * (laby.lignes - 1)) / 2 - 1) * 5 / 100;
		nb_ogres = nb_monstres / 2;
		nb_fantomes = nb_ogres;
		ogres = malloc(sizeof(Coordonnee) * nb_ogres);
		fantomes = malloc(sizeof(Coordonnee) * nb_fantomes);

		int i, random_i, random_j;
		i = 0;
		while (i < nb_ogres)
		{
			random_i = rand_int(1, laby.lignes - 2);
			random_j = rand_int(1, laby.colonnes - 2);
			if (laby.labyrinthe[random_i][random_j] == CASE_LIBRE
				&& random_i != 1 && random_j != 1)
			{
				ogres[i].x = random_j;
				ogres[i].y = random_i;
				i++;
			}
		}

		i = 0;
		while (i < nb_fantomes)
		{
			random_i = rand_int(1, laby.lignes - 2);
			random_j = rand_int(1, laby.colonnes - 2);
			if (laby.labyrinthe[random_i][random_j] == CASE_LIBRE
				&& random_i != 1 && random_j != 1)
			{
				fantomes[i].x = random_j;
				fantomes[i].y = random_i;
				i++;
			}
		}
		return (Entitee) {nb_ogres, nb_fantomes, {0, 1}, ogres, fantomes};
	}
	return (Entitee) {0, 0, {0, 1}, NULL, NULL};
}

void bouger_monstre(Labyrinthe laby, Entitee *entitee)
{
	int i;
	for (i = 0; i < entitee->nb_ogres; i++)
	{
		bouger_ogre(laby, *entitee, &entitee->ogres[i]);
	}

	for (i = 0; i < entitee->nb_fantomes; i++)
	{
		bouger_fantome(laby, *entitee, &entitee->fantome[i]);
	}
}

bool ogre_proche_bonus(Labyrinthe laby, Coordonnee ogre)
{
	int i;
	int j;
	int start_i;
	int start_j;
	int end_i;
	int end_j;

	start_i = ogre.y - 2;
	start_j = ogre.x - 2;
	end_i = ogre.y + 2;
	end_j = ogre.y + 2;
	if (start_i < 1)
	{
		start_i = 1;
	}
	if (start_j < 1)
	{
		start_j = 1;
	}
	if (end_i > laby.lignes - 1)
	{
		end_i = laby.lignes - 1;
	}
	if (end_j > laby.colonnes - 1)
	{
		end_j = laby.colonnes - 1;
	}

	for (i = start_i; i < end_i; i++)
	{
		for (j = start_j; j < end_j; j++)
		{
			if (laby.labyrinthe[i][j] == BONUS)
			{
				return true;
			}
		}
	}
	return false;
}

void bouger_ogre(Labyrinthe laby, Entitee entitee, Coordonnee *ogre)
{
	int tab[4] = {0, 1, 2, 3};
	shuffle(tab, 4);

	int x, y, i;

	x = 0;
	y = 0;
	for (i = 0; i < 4; i++)
	{
		switch (tab[i])
		{
			case HAUT:
				x = 0;
				y = -1;
				break;
			case DROIT:
				x = 1;
				y = 0;
				break;
			case BAS:
				x = 0;
				y = 1;
				break;
			case GAUCHE:
				x = -1;
				y = 0;
				break;
			default:
				break;
		}

		if (ogre_proche_bonus(laby, (Coordonnee) {ogre->x, ogre->y}))
		{
			if (ogre_proche_bonus(laby, (Coordonnee) {ogre->x + x, ogre->y + y})
				&& cellule_valide(laby, entitee, *ogre, x, y))
			{

				ogre->x += x;
				ogre->y += y;
				break;
			}
		}
		else if (cellule_valide(laby, entitee, *ogre, x, y))
		{
			ogre->x += x;
			ogre->y += y;
			break;
		}
	}

	// Dans le cas où l'ogre est proche d'un bonus mais ne peut pas faire de mouvement pour se rapprocher du bonus
	// on effectue une action aléatoire
	if (ogre_proche_bonus(laby, (Coordonnee) {ogre->x, ogre->y}))
	{
		for (i = 0; i < 4; i++)
		{
			switch (tab[i])
			{
				case HAUT:
					x = 0;
					y = -1;
					break;
				case DROIT:
					x = 1;
					y = 0;
					break;
				case BAS:
					x = 0;
					y = 1;
					break;
				case GAUCHE:
					x = -1;
					y = 0;
					break;
				default:
					break;
			}

			if (cellule_valide(laby, entitee, *ogre, x, y))
			{
				ogre->x += x;
				ogre->y += y;
				break;
			}
		}
	}
}

bool cellule_valide(Labyrinthe laby, Entitee entitee, Coordonnee coor,
					int deltaX, int deltaY)
{
	if (coor.x == entitee.joueur.x && coor.y == entitee.joueur.y
		&& laby.labyrinthe[coor.y + deltaY][coor.x + deltaX]
		   == SORTIE) // Dans le cas de la sortie pour le joueur
	{
		return true;
	}

	if (deltaX == -1 && laby.labyrinthe[coor.y][coor.x] == ENTREE)
	{
		return false;
	}

	int case_suivante;
	case_suivante = laby.labyrinthe[coor.y + deltaY][coor.x + deltaX];
	if ((case_suivante == CASE_LIBRE || case_suivante == BONUS
		 || case_suivante == MALUS) && !il_y_a_entitee(entitee, (Coordonnee) {
			coor.x + deltaX, coor.y + deltaY}))
	{

		return true;
	}

	return false;
}


void bouger_fantome(Labyrinthe laby, Entitee entitee, Coordonnee *fantome)
{
	int tab[4] = {0, 1, 2, 3};
	shuffle(tab, 4);

	int x, y, i;
	x = 0;
	y = 0;

	for (i = 0; i < 4; i++)
	{
		switch (tab[i])
		{
			case HAUT:
				x = 0;
				y = -1;
				break;
			case DROIT:
				x = 1;
				y = 0;
				break;
			case BAS:
				x = 0;
				y = 1;
				break;
			case GAUCHE:
				x = -1;
				y = 0;
				break;
			default:
				break;
		}

		if (cellule_valide(laby, entitee, *fantome, x, y))
		{
			fantome->x += x;
			fantome->y += y;
			break;
		}
		else
		{
			if (fantome->x + x != 0 && fantome->x + x != laby.colonnes - 1
				&& fantome->y + y != 0 && fantome->y + y != laby.lignes - 1
				&& laby.labyrinthe[fantome->y + y][fantome->x + x]
				   == MUR) // Pour éviter que les fantomes essaient de traverser le mur des bordures
			{
				switch (tab[i])
				{
					case HAUT:
						y += -1;
						break;
					case DROIT:
						x += 1;
						break;
					case BAS:
						y += 1;
						break;
					case GAUCHE:
						x += -1;
						break;
					default:
						break;
				}

				if (cellule_valide(laby, entitee, *fantome, x, y))
				{
					fantome->x += x;
					fantome->y += y;
					break;
				}
			}
		}
	}
}


bool bouger(Labyrinthe laby, Entitee *entitee, int deltaX, int deltaY)
{
	if (cellule_valide(laby, *entitee, entitee->joueur, deltaX, deltaY))
	{
		entitee->joueur.y = entitee->joueur.y + deltaY;
		entitee->joueur.x = entitee->joueur.x + deltaX;
		return true;
	}
	return false;
}

bool il_y_a_entitee(Entitee entitee, Coordonnee coor)
{
	int i;
	for (i = 0; i < entitee.nb_ogres; i++)
	{
		if (entitee.ogres[i].x == coor.x && entitee.ogres[i].y == coor.y)
		{
			return true;
		}
	}

	for (i = 0; i < entitee.nb_fantomes; i++)
	{
		if (entitee.fantome[i].x == coor.x && entitee.fantome[i].y == coor.y)
		{
			return true;
		}
	}

	if (entitee.joueur.x == coor.x && entitee.joueur.y == coor.y)
	{
		return true;
	}
	return false;
}