cmake_minimum_required(VERSION 3.6.2)
project(projet_maze C)

set(CMAKE_C_STANDARD 99)

add_executable(projet_maze src/main.c src/labyrinthe/labyrinthe.c src/utils/utils.c include/utils.h include/labyrinthe.h include/main.h src/labyrinthe/entitees.c src/labyrinthe/fichiers.c include/fichiers.h src/labyrinthe/jeu.c include/jeu.h include/entitees.h include/constantes.h src/labyrinthe/scores.c include/score.h include/structures.h)