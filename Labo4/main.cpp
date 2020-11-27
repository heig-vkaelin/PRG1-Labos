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
#include "polyominos.h"
#include "outils_jeu_vie.h"

int main() {
	ConfigInitiales config = ConfigInitiales::TETRAMINO_T;
	const unsigned NB_GENERATIONS = 11;
	const unsigned NB_LIGNES = 10;
	const unsigned NB_COLONNES = 11;

	jeuDeLaVie(config, NB_GENERATIONS, NB_LIGNES, NB_COLONNES);

	return EXIT_SUCCESS;
}
