/*
-----------------------------------------------------------------------------------
Nom du fichier : Ex2.cpp
Auteur(s)      : Jonathan Friedli, Valentin Kaelin, Lazar Pavicevic
Date creation  : 09.10.2020

Description    : Programme demandant la saisie à l'utilisateur d'un numéro de case.
                 Ce numéro de case doit se trouver entre 1 et 64 compris pour se
                 trouver sur une grille de 8x8.
                 Le programme détermine et affiche ensuite le numéro de case de
                 plusieurs symétries par rapport à la case entrée par l'utilisateur:
                 - La symétrie par rapport à l'axe horitontal
                 - La symétrie par rapport à l'axe vertical
                 - La symétrie par rapport à la diagonale gauche
                 - La symétrie par rapport à la diagonale droite

Remarque(s)    : On suppose la saisie utilisateur correcte.
                 La diagonale gauche est la diagonale partant d'en haut à gauche
                 du damier pour arriver en bas à droite.
                 La diagonale droite est la diagonale partant d'en haut à droite
                 du damier pour arriver en bas à gauche.
                 Nous avons considéré les coordonnées des cases du damier comme
                 des valeurs octales.
                 Exemple: la case 34 se trouve à la ligne 4 et colonne 1 (la
                 numérotation des lignes et colonnes commence à 0).

Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include <iostream>

using namespace std;

int ex2() {
	const int TAILLE_DAMIER = 8;
	int caseChoisie;

	cout << "Veuillez saisir un numéro de case [1-64] : " << endl;
	cin >> caseChoisie;
	const int NUMERO_CASE_CHOISI = caseChoisie;

	// Décrémentation de la case car la numérotation de la grille commence à 1
	// Exemple: la case à la ligne 0 et à la colonne 0 a la valeur 1
	caseChoisie--;

	int colonneCase = caseChoisie % TAILLE_DAMIER;
	int ligneCase = (caseChoisie - colonneCase) / TAILLE_DAMIER;

	// Axe horizontal:
	// Ligne: complément à 8 de la ligne, colonne: ne change pas
	int ligneSymetrieHorizontale = TAILLE_DAMIER - ligneCase - 1;
	int symetrieHorizontale = ligneSymetrieHorizontale * TAILLE_DAMIER +
									  colonneCase + 1;

	// Axe vertical:
	// Ligne: ne change pas, colonne: complément à 8 de la colonne
	int colSymetrieVerticale = TAILLE_DAMIER - colonneCase - 1;
	int symetrieVerticale = ligneCase * TAILLE_DAMIER + colSymetrieVerticale + 1;

	// Diagonale gauche:
	// Inversion entre la ligne et la colonne
	int symetrieDiagonaleGauche = colonneCase * TAILLE_DAMIER + ligneCase + 1;

	// Diagonale droite:
	// Ligne: complément à 8 de la colonne, colonne: complément à 8 de la ligne
	int ligneSymetrieDiagonaleDroite = TAILLE_DAMIER - colonneCase - 1;
	int colSymetrieDiagonaleDroite = TAILLE_DAMIER - ligneCase - 1;
	int symetrieDiagonaleDroite = ligneSymetrieDiagonaleDroite * TAILLE_DAMIER +
											colSymetrieDiagonaleDroite + 1;

	cout << "Numéro de case choisi: " << NUMERO_CASE_CHOISI << endl
		  << "Case symétrique par rapport à l'axe horizontal: " << symetrieHorizontale
		  << endl
		  << "Case symétrique par rapport à l'axe vertical: " << symetrieVerticale
		  << endl
		  << "Case symétrique par rapport à la diagonale gauche: " <<
		  symetrieDiagonaleGauche << endl
		  << "Case symétrique par rapport à la diagonale droite: " <<
		  symetrieDiagonaleDroite << endl;

	return EXIT_SUCCESS;
}
