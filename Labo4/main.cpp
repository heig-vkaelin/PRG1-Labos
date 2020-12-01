/*
-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Auteur(s)      : Jonathan Friedli, Valentin Kaelin, Lazar Pavicevic
Date creation  : 01.12.2020

Description    : Fichier principal du programme. Implémentation du jeu de la vie
                 de J. H. Conway. Le programme calcule et affiche un nombre de
                 générations donné du jeu de la vie en partant d'une configuration
                 initiale donnée également.

Remarque(s)    : Utilisation de la compilation séparée pour améliorer la
                 lisibilité du code.
                 Les cas où les lignes et/ou colonnes de la grille de jeu valent 0
                 ne sont pas gérés par le programme.
                 Si la configuration initiale n'est pas cohérente avec la taille
                 de la grille, le programme lance une erreur et s'arrête.

Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include "outils_jeu_vie.h"

int main() {
	const unsigned NB_GENERATIONS = 11;
	const unsigned NB_LIGNES = 10;
	const unsigned NB_COLONNES = 11;
	const char CELLULE_VIVANTE = 'X';
	const char CELLULE_MORTE = '.';
	const unsigned ESPACEMENT_HORIZONTAL = 1;

	// Coordonnées d'un polyomino représentant la configuration initiale
	Configuration configuration = {
		{4, 4},
		{4, 5},
		{4, 6},
		{5, 5}
	};

	jeuDeLaVie(configuration, NB_GENERATIONS, NB_LIGNES, NB_COLONNES, CELLULE_VIVANTE,
				  CELLULE_MORTE, ESPACEMENT_HORIZONTAL);

	return EXIT_SUCCESS;
}
/**
 * Question complémentaire: Que peut-on observer dans les résultats obtenus ?
 *
 * On remarque qu'à partir de 9 générations après la configuration initiale, deux
 * générations s'alternent à l'infini.
 * Ces deux générations sont un rond et une croix et la première des deux est le
 * rond.
 */
