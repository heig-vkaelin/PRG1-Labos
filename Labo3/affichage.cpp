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


bool dateDebutAvantFin(unsigned moisDebut, unsigned moisFin, unsigned anneeDebut,
							  unsigned anneeFin) {
	if (anneeDebut * 12 + moisDebut <= anneeFin * 12 + moisFin) {
		return true;
	}
	cout
		<< "Date de fin plus grande que de date de debut. Veuillez SVP recommencer."
		<< endl;
	return false;
}

void saisirDate(bool estDateDeDebut, unsigned &mois, unsigned &annee) {
	bool saisieOK;
	do {
		cout << "Entrez la date de" << (estDateDeDebut ? " debut" : " fin")
			  << " [mm aaaa] :";

		if (cin.peek() != '\n') {
			saisieOK = cin >> noskipws >> mois >> skipws >> annee &&
				dateDansIntervalle(mois, annee);
		} else {
			saisieOK = false;
		}

		if (!saisieOK) {
			cin.clear();
			cout << "Date non valide. Veuillez SVP recommencer." << endl;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (!saisieOK);
}

void afficherDemandesDeSaisie(unsigned &moisDebut, unsigned &moisFin,
										unsigned &anneeDebut, unsigned &anneeFin) {
	do {
		saisirDate(true, moisDebut, anneeDebut);
		saisirDate(false, moisFin, anneeFin);
	} while (!dateDebutAvantFin(moisDebut, moisFin, anneeDebut, anneeFin));
}