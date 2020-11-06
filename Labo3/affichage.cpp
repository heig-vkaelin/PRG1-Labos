/*
-----------------------------------------------------------------------------------
Nom du fichier : <nom du fichier>.<xxx> (xxx = h ou cpp)
Auteur(s) : <prénom> <nom>
Date creation : <jj.mm.aaaa>

Description : <à compléter>

Remarque(s) : <à compléter>

Compilateur : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include <iostream>
#include "logique.h"

using namespace std;

void saisirDate(bool estDateDeDebut, unsigned &mois, unsigned &annee) {
	bool saisieOK;
	do {
		cout << "Entrez la date de" << (estDateDeDebut ? " debut" : " fin")
			  << " [mm aaaa] :";

		if (cin.peek() != '\n') {
			saisieOK = bool(cin >> noskipws >> mois >> skipws);

			if (cin.peek() != '\n') {
				saisieOK = cin >> annee && dateDansIntervalle(mois, annee);
			}
			else {
				saisieOK = false;
			}
		} else {
			saisieOK = false;
		}

		if (!saisieOK) {
			cin.clear();
			cout << "Date non valide. Veuillez SVP recommencer.\n" << endl;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (!saisieOK);
}

void afficherDemandesDeSaisie(unsigned &moisDebut, unsigned &moisFin,
										unsigned &anneeDebut, unsigned &anneeFin) {
	bool saisieOk;
	do {
		saisirDate(true, moisDebut, anneeDebut);
		cout << endl;
		saisirDate(false, moisFin, anneeFin);

		saisieOk = dateDebutAvantFin(moisDebut, moisFin, anneeDebut, anneeFin);

		if (!saisieOk) {
			cout << "Date de fin plus petite que de date de debut. Veuillez SVP"
					  " recommencer.\n" << endl;
		}
	} while (!saisieOk);
}

bool relancerProgramme() {
	char saisie;
	bool saisieOk;
	do {
		cout << endl << "Voulez-vous quitter le programme ? [o/n] : ";
		cin >> saisie;
		saisieOk = saisie == 'o' || saisie == 'n';

		if (!saisieOk) {
			cin.clear();
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (!saisieOk);

	return saisie == 'n';
}