/*
-----------------------------------------------------------------------------------
Nom du fichier : affichage.cpp
Auteur(s)      : Jonathan Friedli, Valentin Kaelin, Lazar Pavicevic
Date creation  : 05.11.2020

Description    : Fichier contenant tout le code concernant l'affichage du
                 calendrier dans la console ainsi que la saisie utilisateur.

Remarque(s)    : Les saisies utilisateur doivent être entièrement contrôlées.
                 Le mois et l'année doivent impérativement être saisis sur la même
                 ligne, séparés par un espace.
                 La date de début entrée doit se trouver avant la date de fin.
                 En cas de saisie incorrecte, l'utilisateur est invité à ressaisir
                 la date.

Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include <iostream>
#include <iomanip>
#include "affichage.h"
#include "date.h"

using namespace std;

void saisirDate(bool estDateDeDebut, unsigned &mois, unsigned &annee) {
	bool saisieCorrecte;
	do {
		cout << "Entrez la date de" << (estDateDeDebut ? " debut" : " fin")
			  << " [mm aaaa] :";

		// noskipws aide à la gestion du cas où l'utilisateur fait juste la
		// combinaison "space" + "enter".
		cin >> noskipws >> mois;

		int separateur = cin.get();

		if (separateur == ' ') {
			saisieCorrecte = cin >> annee && cin.peek() == '\n'
				&& dateDansIntervalle(mois,annee);
		} else {
			saisieCorrecte = false;
		}
		if (!saisieCorrecte) {
			cout << "Date non valide. Elle doit etre comprise entre " <<
				  ANNEE_BORNE_INFERIEURE << "-" << ANNEE_BORNE_SUPERIEURE
				  << ". Veuillez SVP recommencer." << endl << endl;

			if (separateur != '\n') {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
	} while (!saisieCorrecte);
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void afficherDemandesDeSaisie(unsigned &moisDebut, unsigned &moisFin,
										unsigned &anneeDebut, unsigned &anneeFin) {
	bool saisieCorrecte;
	do {
		saisirDate(true, moisDebut, anneeDebut);
		cout << endl;
		saisirDate(false, moisFin, anneeFin);

		saisieCorrecte = dateDebutAvantFin(moisDebut, moisFin, anneeDebut, anneeFin);

		if (!saisieCorrecte) {
			cout << "Date de fin plus petite que de date de debut. Veuillez SVP"
					  " recommencer.\n" << endl;
		}
	} while (!saisieCorrecte);
}

bool quitterProgramme() {
	string saisie;
	bool saisieCorrecte;
	do {
		cout << "Voulez-vous quitter le programme ? [o/n] :";
		cin >> saisie;
		saisieCorrecte = saisie == "o" || saisie == "n";

		if (!saisieCorrecte) {
			cin.clear();
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (!saisieCorrecte);

	return saisie == "o";
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
