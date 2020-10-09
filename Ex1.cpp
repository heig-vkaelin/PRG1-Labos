/*
-----------------------------------------------------------------------------------
Nom du fichier : Ex1.cpp
Auteur(s)      : Jonathan Friedli, Valentin Kaelin, Lazar Pavicevic
Date creation  : 09.10.2020

Description    : Programme demandant la saisie à l'utilisateur d'un entier "n".
                 Le programme détermine en suite la valeur de "n" en octal et
                 vérifie si "n" est un palindrome ou non. Pour finir, le programme
                 affiche les résultats des opérations à l'écran.

Remarque(s)    : On suppose la saisie utilisateur correcte.

                 La boucle while est autorisée mais les concepts de tableau ainsi
                 que de chaîne de caractères ne le sont pas.

                 Palindrome: nombre que l'on peut lire indifféremment de gauche à
                 droite ou de droite à gauche (ex: 12021).

                 Nous nous sommes inspirés de différents algorithmes trouvés sur
                 le net pour la résolution de cet exercice:
                 Changement de base:
                 https://www.geeksforgeeks.org/program-decimal-octal-conversion/
                 Inverser un nombre:
                 https://www.programiz.com/cpp-programming/examples/reverse-number

Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
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
	// on garde sa valeur initiale pour pouvoir l'utiliser à tout moment.
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

		// Changement de base de l'entier initial vers la base octale
		while (entierDecimal != 0) {
			reste = entierDecimal % BASE_OCTALE;
			entierDecimal /= BASE_OCTALE;
			entierOctal = entierOctal + reste * positionDecimale;
			positionDecimale *= 10;
		}
		// Remise de l'entier décimal à sa valeur initiale afin de pouvoir l'utiliser
		// dans les futurs opérations pour déterminer s'il s'agit d'un palindrome
		entierDecimal = ENTIER_INITIAL;
	} else {
		entierOctal = ENTIER_INITIAL;
	}

	estPalindrome = ENTIER_INITIAL < BASE_DECIMALE;

	if (ENTIER_INITIAL >= BASE_DECIMALE) {
		unsigned int reste;
		// Utilisation d'un unsigned long long car un débordement est possible lorsque
		// de grosses valeurs sont insérées (ex: 2'000'000'009 -> 9'000'000'002)
		unsigned long long entierInverse = 0;

		// Inversion de l'entier initial
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
	} else {
		cout << ENTIER_INITIAL << " n'est pas un palindrome" << endl;
	}

	return EXIT_SUCCESS;
}
