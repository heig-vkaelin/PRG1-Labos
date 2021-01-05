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
	cout << "Hello from Labo5" << endl;

	Date date1(15, 10, 1582);

	Date date2(14, 11, 2020);

	Date date3(14, 10, 1581);

	cout << nombreJoursDepuisDebutCalendrierGregorien(date3) << endl;
//	cout << nombreJoursEntreDeuxDates(date2, date1) << endl;

	return EXIT_SUCCESS;
}
