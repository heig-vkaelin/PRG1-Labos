/*
-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Auteur(s)      : Jonathan Friedli, Valentin Kaelin, Lazar Pavicevic
Date creation  : 26.11.2020

Description    :

Remarque(s)    :

Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include "logique.h"

using namespace std;

int main() {
	CONFIG_INITIALES config = CONFIG_INITIALES::TETRAMINO_T;
	const int NB_GENERATIONS = 11; // -1: boucle du jeu infinie
	jeuDeLaVie(config, NB_GENERATIONS);

	return EXIT_SUCCESS;
}
