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
 * @file main.c
 */

#include "../include/main.h"

void creer_labyrinthe()
{
	int hauteur, largeur;
	char *nom;
	printf("Hauteur [nombre impair] :");

	scanf("%d", &hauteur);
	clear_input_buffer();
	while (hauteur % 2 != 1 && hauteur >= 3)
	{
		printf("La hauteur doit être un nombre impair et >=3!\n");
		printf("Hauteur [nombre impair] :");
		scanf("%d", &hauteur);
		clear_input_buffer();
	}

	printf("Largeur [nombre impair]:");
	scanf("%d", &largeur);
	clear_input_buffer();
	while (largeur % 2 != 1 && largeur >= 3)
	{
		printf("La largeur doit être un nombre impair et >= 3!\n");
		printf("Largeur [nombre impair] :");
		scanf("%d", &largeur);
		clear_input_buffer();
	}
	printf("Nom :");

	fflush(stdin);
	scanf("%ms", &nom);

	printf("Difficulté (1 ou 2):");
	int difficulte;
	scanf("%d", &difficulte);
	clear_input_buffer();
	while(difficulte != 1 && difficulte != 2)
	{
		printf("Difficulté (1 ou 2):");
		scanf("%d", &difficulte);
		clear_input_buffer();
	}
	sauvegarder_labyrinthe(init_labyrinthe(hauteur, largeur, nom, difficulte));
	press_any_key_to_continue();
}


void afficher_menu(char *nom)
{
	clear_console();
	printf("# LABYRINTHE\n");
	printf("###########################\n");
	printf("[1] Créer un labyrinthe\n");
	printf("[2] Charger un labyrinthe\n");

	if (nom != NULL)
	{
		printf("[3] Jouer au labyrinthe %s\n", nom);
		printf("[4] Score du labyrinthe %s\n", nom);
	}
	else
	{
		printf("[3] Jouer\n");
		printf("[4] Scores\n");
	}

	printf("[5] Quitter\n");
	printf("###########################\n");
}

void demarrer()
{
	Labyrinthe laby_charge;
	int choix;

	laby_charge.nom = NULL;
	choix = 0;

	afficher_menu(laby_charge.nom);

	while (choix != 5)
	{
		choix = 0;
		scanf("%d", &choix);
		clear_input_buffer();

		switch (choix)
		{
			case 1:
			{

				creer_labyrinthe();
				break;
			}
			case 2:
			{
				laby_charge = charger_labyrinthe();
				if (laby_charge.labyrinthe == NULL)
				{
					printf("> Le labyrinthe n'existe pas!\n");
					press_any_key_to_continue();
				}
				break;
			}
			case 3:
			{

				if (laby_charge.nom != NULL)
				{
					jouer(&laby_charge);
				}
				else
				{
					printf("> Auncun labyrinthe n'a été chargé!\n");
					press_any_key_to_continue();
				}
				break;
			}
			case 4:
			{
				if (laby_charge.nom != NULL)
				{
					int nb_scores;
					Score *scores = charger_score(laby_charge, &nb_scores);
					affiche_score(scores, nb_scores);
				}
				else
				{
					printf("> Auncun labyrinthe n'a été chargé!\n");
					press_any_key_to_continue();
				}
				break;
			}
			case 5:
			{
				exit(0);
			}
			default:
			{

				break;
			}
		}

		afficher_menu(laby_charge.nom);
	}
}


int main(int argc, char const *argv[])
{
	srand(time(NULL));
	demarrer();
	return 0;
}
