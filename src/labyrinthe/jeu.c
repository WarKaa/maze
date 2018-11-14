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
 * @file jeu.c
 */

#include "../../include/jeu.h"

void jouer(Labyrinthe *laby)
{
	clear_console();
	Entitee entitee;
	entitee = init_entitees(*laby);
	afficher_labyrinthe_en_jeu(*laby, entitee);

	int score;
	score = 0;

	while (entitee.joueur.x != laby->colonnes - 1
		   || entitee.joueur.y != laby->lignes - 2)
	{
		char clavier;
		printf("(z/q/s/d):");
		scanf("\n%c", &clavier);
		clear_input_buffer();
		switch (tolower(clavier))
		{
			case 'z':
			{
				bouger(*laby, &entitee, 0, -1);
				break;
			}
			case 'q':
			{
				bouger(*laby, &entitee, -1, 0);
				break;
			}
			case 's':
			{
				bouger(*laby, &entitee, 0, 1);
				break;
			}
			case 'd':
			{
				bouger(*laby, &entitee, 1, 0);
				break;
			}
		}

		score++;
		bouger_monstre(*laby, &entitee);

		if (laby->labyrinthe[entitee.joueur.y][entitee.joueur.x] == MALUS)
		{
			score += NB_POINTS_MALUS;
			laby->labyrinthe[entitee.joueur.y][entitee.joueur.x] = CASE_LIBRE;
		}

		if (laby->labyrinthe[entitee.joueur.y][entitee.joueur.x] == BONUS)
		{
			score += NB_POINTS_BONUS;
			laby->labyrinthe[entitee.joueur.y][entitee.joueur.x] = CASE_LIBRE;
		}

		clear_console();
		printf("Score: %d\n", score);
		afficher_labyrinthe_en_jeu(*laby, entitee);
	}

	printf("Bravo vous avez trouvé la sortie !\n");
	sauvegarder_nouveau_score(*laby, score);

	laby->nom = NULL;
	if (laby->difficulte == 2)
	{
		free(entitee.ogres);
		free(entitee.fantome);
	}
}

