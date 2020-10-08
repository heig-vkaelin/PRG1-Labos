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
 * std:oct si autorisé > http://www.cplusplus.com/reference/ios/oct/
 * logique si non-autorisé >
 * https://www.programiz.com/cpp-programming/examples/octal-decimal-convert
 * Reverse number: https://www.programiz.com/cpp-programming/examples/reverse-number
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int ex1() {
	unsigned int entierDecimal;
	const unsigned int BASE_OCTALE = 8;
	const unsigned int BASE_DECIMALE = 10;

	cout << "Veuillez saisir un entier positif 'n': " << endl;
	cin >> entierDecimal;

	const unsigned int ENTIER_INITIAL = entierDecimal;

	unsigned int entierOctale = 0;
	bool estPalindrome;

	estPalindrome = ENTIER_INITIAL < 10;

	if (ENTIER_INITIAL > BASE_OCTALE) {
		unsigned int retenue;
		unsigned int positionDecimale = 1;

		while (entierDecimal != 0) {
			retenue = entierDecimal % BASE_OCTALE;
			entierDecimal /= BASE_OCTALE;
			entierOctale += retenue * positionDecimale;
			positionDecimale *= 10;
		}
	}
	entierDecimal = ENTIER_INITIAL;

	if (!estPalindrome) {
		unsigned int retenue;
		unsigned int entierInverse= 0;

		while (entierDecimal != 0) {
			retenue = entierDecimal % BASE_DECIMALE;
			entierInverse = entierInverse * BASE_DECIMALE + retenue;
			entierDecimal /= BASE_DECIMALE;
		}
		estPalindrome = entierInverse == ENTIER_INITIAL;
	}

	cout 	<< ENTIER_INITIAL << " en base 8 vaut " << entierOctale << endl;
	if (estPalindrome) {
		cout << ENTIER_INITIAL << " est un palindrome" << endl;
	}
	return EXIT_SUCCESS;
}

