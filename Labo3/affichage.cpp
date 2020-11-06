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
#include <iomanip>
#include "logique.h"

using namespace std;

void saisirDate(bool estDateDeDebut, unsigned &mois, unsigned &annee) {
	bool saisieOK;
	do {
		cout << "Entrez la date de" << (estDateDeDebut ? " debut" : " fin")
			  << " [mm aaaa] :";

		cin >> noskipws >> mois >> skipws;
		if (cin.peek() != '\n') {
			saisieOK = cin >> annee && dateDansIntervalle(mois, annee);
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
		cout << "Voulez-vous quitter le programme ? [o/n] :";
		cin >> saisie;
		saisieOk = saisie == 'o' || saisie == 'n';

		if (!saisieOk) {
			cin.clear();
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (!saisieOk);

	return saisie == 'n';
}

void afficheJoursSemaine() {
	cout << " L  M  M  J  V  S  D" << endl;
}

string nomDuMois(unsigned noMois) {
	switch (noMois) {
		case 1:
			return "Janvier";
		case 2:
			return "Fevrier";
		case 3:
			return "Mars";
		case 4:
			return "Avril";
		case 5:
			return "Mai";
		case 6:
			return "Juin";
		case 7:
			return "Juillet";
		case 8:
			return "Aout";
		case 9:
			return "Septembre";
		case 10:
			return "Octobre";
		case 11:
			return "Novembre";
		case 12:
			return "Decembre";
		default:
			return "";
	}
}

void afficheMois(unsigned mois, unsigned annee, unsigned joursMois,
					  unsigned &jourDeLaSemaine) {

	cout << nomDuMois(mois) << " " << annee << endl << endl;
	afficheJoursSemaine();
	for (unsigned jour = 0; jour < joursMois; ++jour) {
		unsigned decalage = espacementJourDuMois(jour, jourDeLaSemaine);

		cout << setw((int) decalage) << jour + 1;

		if ((jourDeLaSemaine + 1) % JOURS_PAR_SEMAINE == 0) {
			cout << endl;
			jourDeLaSemaine = 0;
		} else {
			++jourDeLaSemaine;
		}
	}
	cout << endl << endl;
}
