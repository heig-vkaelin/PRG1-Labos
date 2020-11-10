/*
-----------------------------------------------------------------------------------
Nom du fichier	: main.cpp
Auteur(s)		: Jonathan Friedli, Valentin Kaelin, Lazar Pavicevic
Date creation	: 05.11.2020

Description		: <à compléter>

Remarque(s)		: <à compléter>

Compilateur		: Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include "affichage.h"

using namespace std;

int main() {
	do {
		unsigned moisDebut, moisFin, anneeDebut, anneeFin;
		afficherDemandesDeSaisie(moisDebut, moisFin, anneeDebut, anneeFin);

		afficherCalendrier(moisDebut, moisFin, anneeDebut, anneeFin);
	} while (!quitterProgramme());

	return EXIT_SUCCESS;
}
