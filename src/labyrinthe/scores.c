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
 * @file scores.c
 *
 */

#include "../../include/score.h"

char *get_chemin_score(Labyrinthe laby)
{
	mkdir(CHEMIN_SCORE, 0777);

	return concat_char(3, CHEMIN_SCORE, laby.nom, ".score");
}

void affiche_score(Score *scores, int nb_scores)
{
	printf("###########################\n");
	int i;
	for (i = 0; i < nb_scores; i++)
	{
		printf("%s : %d\n", scores[i].nom_utilisateur, scores[i].score);
	}
	printf("###########################\n");
	press_any_key_to_continue();
}

Score *charger_score(Labyrinthe laby, int *nb_score)
{
	FILE *fichier;
	char *chemin;
	Score *scores;

	chemin = get_chemin_score(laby);
	scores = malloc(sizeof(Score) * 10);
	fichier = fopen(chemin, "r");

	if (fichier == NULL)
	{
		*nb_score = 0;

		return scores;
	}

	fread(nb_score, sizeof(int), 1, fichier);

	fread(scores, sizeof(Score), (size_t) *nb_score, fichier);

	fclose(fichier);
	return scores;
}

void sauvegarder_scores(Labyrinthe laby, Score *scores, int nb_scores)
{
	FILE *fichier;
	char *chemin;

	chemin = get_chemin_score(laby);
	fichier = fopen(chemin, "w");

	if (fichier == NULL)
	{
		perror("Erreur de l'ouverture du fichier.\n");
		exit(EXIT_FAILURE);
	}

	fwrite(&nb_scores, sizeof(int), 1, fichier);
	fwrite(scores, sizeof(Score), (size_t) nb_scores, fichier);
	fclose(fichier);
}

int compare_score(const void *sc1, const void *sc2)
{
	return (((Score *) sc1)->score > ((Score *) sc2)->score ? 1 : -1);
}

void sauvegarder_nouveau_score(Labyrinthe laby, int score)
{
	int nb_scores;
	Score *scores;
	scores = charger_score(laby, &nb_scores);

	if (scores[nb_scores - 1].score > score || nb_scores < 10)
	{
		int index;
		index = (nb_scores == 0 ? 0 : (nb_scores < 10 ? nb_scores : nb_scores
																	- 1));
		scores[index] = (Score) {score, ""};
		printf("Nom d'utilisateur: ");
		scanf("%20s", &scores[index].nom_utilisateur);

		if (nb_scores < 10 && nb_scores >= 0)
		{
			nb_scores++;
		}

		qsort(scores, nb_scores, sizeof(Score), compare_score);
		sauvegarder_scores(laby, scores, nb_scores);
		affiche_score(scores, nb_scores);
	}
}