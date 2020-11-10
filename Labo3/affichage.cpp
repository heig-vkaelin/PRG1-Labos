/*
-----------------------------------------------------------------------------------
Nom du fichier	: affichage.cpp
Auteur(s)		: Valentin Kaelin, Jonathan Friedli, Lazar Pavicevic
Date creation	: 05.11.2020

Description		: <à compléter>

Remarque(s)		: <à compléter>

Compilateur		: Mingw-w64 g++ 8.1.0
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

		// noskipws aide la gestion du cas où l'utilisateur fait juste la
		// combinaison "space" + "enter".
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

bool quitterProgramme() {
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

	return saisie == 'o';
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

	cout << nomDuMois(mois) << " " << annee << endl << endl;
	cout << " L  M  M  J  V  S  D" << endl;

	for (unsigned jour = 1; jour <= nbJours; ++jour, ++jourSemaine) {
		if (jourSemaine == JOURS_PAR_SEMAINE) {
			cout << endl;
			jourSemaine = 0;
		}

		afficherJourDuMois(jour, jourSemaine);
	}
	cout << endl << endl;
	jourSemaine %= JOURS_PAR_SEMAINE;
}

void afficherCalendrier(unsigned moisDebut, unsigned moisFin, unsigned anneeDebut,
								unsigned anneeFin) {
	unsigned nbMois = nbMoisEntreDeuxDates(moisDebut, moisFin, anneeDebut, anneeFin);
	unsigned jourSemaine = jourDeLaSemaine(1, moisDebut, anneeDebut);
	unsigned moisActuel = moisDebut, anneeActuelle = anneeDebut;

	for (unsigned i = 1; i <= nbMois; ++i, ++moisActuel) {
		afficherMois(moisActuel, anneeActuelle, jourSemaine);

		if (moisActuel % MOIS_PAR_ANNEE == 0) {
			anneeActuelle++;
			moisActuel %= MOIS_PAR_ANNEE;
		}
	}
}
