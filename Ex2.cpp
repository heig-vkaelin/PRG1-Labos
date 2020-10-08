/*
-----------------------------------------------------------------------------------
Nom du fichier : Ex2.cpp
Auteur(s)      : Valentin Kaelin, Jonathan Friedli, Lazar Pavicevic
Date creation  : 09.10.2020

Description    : Programme ...

Remarque(s)    : On suppose la saisie utilisateur correcte.

Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include <iostream>

using namespace std;

int ex2() {
	// Exemple pour la case 44
	// (44-1) % 8 = 3 (colonne)
	// (44 - 1 - colonne (ici 3)) / 8 = 5 (ligne)
	// Donc position de la case 44: [5, 3]

	const unsigned int TAILLE_DAMIER = 8;
	const unsigned int BASE_OCTALE = 8;
	unsigned int noCase;
	unsigned int noCaseOctal = 0;

	cout << "Veuillez saisir un numéro de case [1-64] : " << endl;
	cin >> noCase;
	const unsigned int NUMERO_CASE_INITIAL = noCase;

	// Changement de base de l'entier initial vers la base octale
	// Chiant sans boucle...
	if (noCase >= BASE_OCTALE) {
		unsigned int positionDecimale = 1;
		unsigned int reste = noCase % BASE_OCTALE;
		noCase /= BASE_OCTALE;
		noCaseOctal = noCaseOctal + reste * positionDecimale;
		positionDecimale *= 10;
		reste = noCase % BASE_OCTALE;
		noCase /= BASE_OCTALE;
		noCaseOctal = noCaseOctal + reste * positionDecimale;
	} else {
		noCaseOctal = noCase;
	}

	unsigned colCase = (NUMERO_CASE_INITIAL - 1) % 8;
	unsigned ligneCase = (NUMERO_CASE_INITIAL - 1 - colCase) / 8;

	cout << "No case: " << NUMERO_CASE_INITIAL << endl;
	cout << "Colonne: " << colCase << endl;
	cout << "Ligne: " << ligneCase << endl;
	cout << "No case en octal: " << noCaseOctal << endl;

	return EXIT_SUCCESS;
}