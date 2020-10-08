/*
-----------------------------------------------------------------------------------
Nom du fichier : Ex1.cpp
Auteur(s) : Valentin Kaelin, Jonathan Friedli, Lazar Pavicevic
Date creation : 08.10.2020

Description : <à compléter>

Remarque(s) : <à compléter>

Compilateur : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

/*
 * Note au groupe
 *
 * Lien à citer dans les commentaires pour l'algo de changement de base:
 * https://www.geeksforgeeks.org/program-decimal-octal-conversion/
 *
 * Reverse number:
 * https://www.programiz.com/cpp-programming/examples/reverse-number
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int ex1() {
	const unsigned int BASE_OCTALE = 8;
	const unsigned int BASE_DECIMALE = 10;
	unsigned int entierDecimal;

	cout << "Veuillez saisir un entier positif \"n\" : " << endl;
	cin >> entierDecimal;

	// La valeur de l'entier saisi pouvant changer durant l'exécution du programme,
	// on initialise une constante gardant sa valeur initiale.
	const unsigned int ENTIER_INITIAL = entierDecimal;

	// Utilisation d'un unsigned long long car la valeur maximale d'un entier signé
	// affiché sous sa forme octale ne peut pas être stockée avec 32 bits.
	unsigned long long entierOctal;
	bool estPalindrome;

	if (ENTIER_INITIAL >= BASE_OCTALE) {
		unsigned int reste;
		// Utilisation d'un unsigned long long car un débordement est possible lorsque
		// de grosses valeurs sont insérées.
		unsigned long long positionDecimale = 1;

		entierOctal = 0;

		while (entierDecimal != 0) {
			reste = entierDecimal % BASE_OCTALE;
			entierDecimal /= BASE_OCTALE;
			entierOctal = entierOctal + reste * positionDecimale;
			positionDecimale *= 10;
		}
		entierDecimal = ENTIER_INITIAL;
	} else {
		entierOctal = ENTIER_INITIAL;
	}

	estPalindrome = ENTIER_INITIAL < BASE_DECIMALE;

	if (!estPalindrome) {
		unsigned int reste;
		// Utilisation d'un unsigned long long car un débordement est possible lorsque
		// de grosses valeurs sont insérées.
		unsigned long long entierInverse = 0;

		while (entierDecimal != 0) {
			reste = entierDecimal % BASE_DECIMALE;
			entierDecimal /= BASE_DECIMALE;
			entierInverse = entierInverse * BASE_DECIMALE + reste;
		}
		estPalindrome = entierInverse == ENTIER_INITIAL;
	}

	cout << ENTIER_INITIAL << " en base 8 vaut " << entierOctal << endl;
	if (estPalindrome) {
		cout << ENTIER_INITIAL << " est un palindrome" << endl;
	}
	return EXIT_SUCCESS;
}

