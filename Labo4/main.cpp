/*
-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Auteur(s)      : Jonathan Friedli, Valentin Kaelin, Lazar Pavicevic
Date creation  : 01.12.2020

Description    :

Remarque(s)    :

Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include "outils_jeu_vie.h"

int main() {
	const unsigned NB_GENERATIONS = 11;
	const unsigned NB_LIGNES = 10;
	const unsigned NB_COLONNES = 11;
	const char VIVANTE = 'X';
	const char MORTE = '.';
	const unsigned ESPACEMENT_HORIZONTAL = 1;

	// Coordonnées d'un Tétramino centré pour une grille 10x11
	Configuration configuration = {
		{4, 4},
		{4, 5},
		{4, 6},
		{5, 5}
	};

	jeuDeLaVie(configuration, NB_GENERATIONS, NB_LIGNES, NB_COLONNES, VIVANTE,
				  MORTE, ESPACEMENT_HORIZONTAL);

	return EXIT_SUCCESS;
}
