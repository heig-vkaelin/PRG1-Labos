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

#include <iostream>
#include <iomanip>
#include "affichage.h"
#include "date.h"

using namespace std;

void saisirDate(bool estDateDeDebut, unsigned &mois, unsigned &annee) {
	bool saisieOK;
	do {
		cout << "Entrez la date de" << (estDateDeDebut ? " debut" : " fin")
			  << " [mm aaaa] :";

		cin >> noskipws >> mois;

		int separateur = cin.get();

		if (separateur == ' ') {
			cin >> annee;
			saisieOK = cin.peek() == '\n' && dateDansIntervalle(mois, annee);
		} else {
			saisieOK = false;
		}
		if (!saisieOK) {
			cout << "Date non valide. Veuillez SVP recommencer.\n" << endl;

			if (separateur != '\n') {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
	} while (!saisieOK);
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

void afficherJourDuMois(unsigned jour, unsigned jourSemaine) {
	const unsigned LARGEUR_COLONNE = 3;
	const unsigned LARGEUR_PREMIERE_COLONNE = 2;
	unsigned largeurJour;

	if (jour == 1) {
		largeurJour = jourSemaine * LARGEUR_COLONNE + LARGEUR_PREMIERE_COLONNE;
	} else {
		largeurJour = jourSemaine == 0 ? LARGEUR_PREMIERE_COLONNE : LARGEUR_COLONNE;
	}

	cout << setw((int) largeurJour) << jour;
}

void afficherMois(unsigned mois, unsigned annee, unsigned &jourSemaine) {
	unsigned nbJours = nbJoursParMois(mois, annee);

	cout << endl << nomDuMois(mois) << " " << annee << endl << endl;
	cout << " L  M  M  J  V  S  D" << endl;

	for (unsigned jour = 1; jour <= nbJours; ++jour, ++jourSemaine) {
		if (jourSemaine == JOURS_PAR_SEMAINE) {
			cout << endl;
			jourSemaine = 0;
		}

		afficherJourDuMois(jour, jourSemaine);
	}
	cout << endl;
	jourSemaine %= JOURS_PAR_SEMAINE;
}

void afficherCalendrier(unsigned moisDebut, unsigned annee, unsigned nbMois) {
	unsigned jourSemaine = jourDeLaSemaine(1, moisDebut, annee);
	unsigned moisActuel = moisDebut;
	for (unsigned i = 1; i <= nbMois; ++i, ++moisActuel) {

		afficherMois(moisActuel, annee, jourSemaine);

		if (moisActuel % MOIS_PAR_ANNEE == 0) {
			annee++;
			moisActuel %= MOIS_PAR_ANNEE;
		}
	}
}
