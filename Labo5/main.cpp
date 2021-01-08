/*
-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Auteur(s)      : Jonathan Friedli, Valentin Kaelin, Lazar Pavicevic
Date creation  : 05.01.2021

Description    : Fichier principal du programme permettant de tester le bon
                 fonctionnement de la classe Date.

Remarque(s)    : Utilisation de la compilation séparée pour améliorer la
                 lisibilité du code.
                 Format de l'affichage des tests:
                 valeur obtenue  <-> valeur attendue

Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include <iostream>
#include "Date.h"

using namespace std;

int main() {
	// 1) Initialisation d'une date
	Date d1(10, 11, 2020),
		d2(1, 1, 2021),
		d3(10, 11, 2020);

	// 2) Opérateur << pour afficher une date au format "jj.mm.aaaa"
	cout << d1 << " <-> 10.11.2020 (resultat attendu)" << endl << endl;

	// 3) Accesseurs des données membres
	cout << d1.getJour() << "." << d1.getMois() << "." << d1.getAnnee()
		  << " <-> 10.11.2020 (resultat attendu)" << endl << endl;

	// 4) Opérateurs de comparaison (<, <=, >, >=, == et !=)
	cout << boolalpha
		  << d1 << " < " << d2 << " = " << (d1 < d2)
		  << " <-> true (resultat attendu)" << endl
		  << d1 << " > " << d2 << " = " << (d1 > d2)
		  << " <-> false (resultat attendu)" << endl
		  << d1 << " <= " << d3 << " = " << (d1 <= d3)
		  << " <-> true (resultat attendu)" << endl
		  << d1 << " >= " << d3 << " = " << (d1 >= d3)
		  << " <-> true (resultat attendu)" << endl
		  << d1 << " == " << d2 << " = " << (d1 == d2)
		  << " <-> false (resultat attendu)" << endl
		  << d1 << " != " << d2 << " = " << (d1 != d2)
		  << " <-> true (resultat attendu)" << endl << endl;

	// 5) Opérateurs ++ et -- (pré-incrémentation et post-incrémentation)
	cout << d1++ << " <-> 10.11.2020 (resultat attendu)" << endl
		  << d1 << " <-> 11.11.2020 (resultat attendu)" << endl
		  << ++d1 << " <-> 12.11.2020 (resultat attendu)" << endl << endl;

	cout << d2-- << " <-> 01.01.2021 (resultat attendu)" << endl
		  << d2 << " <-> 31.12.2020 (resultat attendu)" << endl
		  << --d2 << " <-> 30.12.2020 (resultat attendu)" << endl << endl;

	d1 = Date(10, 11, 2020); // reset à la valeur initiale
	d2 = Date(1, 1, 2021);

	// 6) Opérateurs + et += (avec un unsigned)
	cout << (d1 + 10) << " <-> 20.11.2020 (resultat attendu)" << endl
		  << (d1 += 30) << " <-> 10.12.2020 (resultat attendu)" << endl << endl;

	d1 = Date(10, 11, 2020);

	// 7)  Opérateurs - et -= (avec un unsigned)
	cout << (d1 - 10) << " <-> 31.10.2020 (resultat attendu)" << endl
		  << (d1 -= 30) << " <-> 11.10.2020 (resultat attendu)" << endl << endl;

	d1 = Date(10, 11, 2020);

	// 8) Opérateur - (entre deux dates)
	Date d4(15, 11, 2020);
	cout << d2 << " - " << d1 << " = " << (d2 - d1)
		  << " <-> 52 (resultat attendu)" << endl
		  << d3 << " - " << d4 << " = " << (d3 - d4)
		  << " <-> -5 (resultat attendu)" << endl << endl;

	// 9) Opérateur << pour afficher aux formats "jj-mm-aaaa", "aaaa.mm.jj" ou
	// "aaaa-mm-jj"
	cout << d1("jj-mm-aaaa") << " <-> 10-11-2020 (resultat attendu)" << endl
		  << d1("aaaa.mm.jj") << " <-> 2020.11.10 (resultat attendu)" << endl
		  << d1("aaaa-mm-jj") << " <-> 2020-11-10 (resultat attendu)" << endl
		  << d1 << " <-> 10.11.2020 (resultat attendu)" << endl;

	return EXIT_SUCCESS;
}
