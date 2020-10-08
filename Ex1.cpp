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
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int ex1() {
	unsigned int entierDecimal;
	const unsigned int BASE = 8;

	cout << "Veuillez saisir un entier positif 'n': " << endl;
	cin >> entierDecimal;

	unsigned int reste;
	unsigned int entierOctale = 0;
	unsigned int entierDec = entierDecimal;
	unsigned int positionDecimale = 1;

	if (entierDecimal < BASE){
		cout 	<< entierDecimal << " en base 8 vaut " << entierDecimal << endl
				 << entierDecimal << " est un palindrome" << endl;
	} else {
		while (entierDec != 0) {
			reste = entierDec % BASE;
			entierDec /= BASE;
			entierOctale += reste * positionDecimale;
			positionDecimale *= 10;
		}
		cout  << entierDecimal << " vaut " << entierOctale;
	}
	return EXIT_SUCCESS;
}

