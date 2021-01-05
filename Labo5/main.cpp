/*
-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Auteur(s)      : Jonathan Friedli, Valentin Kaelin, Lazar Pavicevic
Date creation  : 05.01.2021

Description    :

Remarque(s)    :

Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include <iostream>
#include "date.h"

using namespace std;

int main() {
	Date date1(1, 6, 2020);
	Date date2(14, 11, 1956);
	Date date3(14, 10, 1581);

	cout << date1 << endl;
	cout << date2 << endl;
	cout << date1 - date2 << endl;

	cout << date1("jj-mm-aaaa") << endl;

	return EXIT_SUCCESS;
}
