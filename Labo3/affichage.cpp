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
                 La date de début entrée doit se trouver avant la date de fin. Si
                 cette condition n'est pas respectée, l'utilisateur saisit les
                 dates depuis le début.
                 En cas de saisie incorrecte, l'utilisateur est invité à ressaisir
                 la date.
                 Les semaines du calendrier s'affichent du lundi au dimanche.

Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "affichage.h"
#include "date.h"

using namespace std;

void saisirDate(bool estDateDeDebut, int &mois, int &annee) {
	bool saisieCorrecte;
	do {
		cout << "Entrez la date de" << (estDateDeDebut ? " debut" : " fin")
			  << " [mm aaaa] :";

		cin >> noskipws >> mois;

		// En faisant get() on enlève le caractère qui sépare les deux nombres.
		int separateur = cin.get();

		// Vu que les espaces sont pris en compte avec noskipws, on s'assure que notre
		// séparateur soit forcément un espace pour que la saisie soit correcte.
		if (separateur == ' ') {
			saisieCorrecte = cin >> annee && cin.peek() == '\n'
								  && dateDansIntervalle(mois, annee);
		} else {
			saisieCorrecte = false;
		}
		if (!saisieCorrecte) {
			cout << "Date non valide. Elle doit etre comprise entre " <<
				  ANNEE_BORNE_INFERIEURE << "-" << ANNEE_BORNE_SUPERIEURE
				  << ". Veuillez SVP recommencer." << endl << endl;

			// On efface le cin seulement s'il reste des caractères. Sinon il demande
			// un retour a la ligne en plus
			if (separateur != '\n') {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
	} while (!saisieCorrecte);
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void afficherDemandesDeSaisie(int &moisDebut, int &moisFin, int &anneeDebut,
										int &anneeFin) {
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

void afficherJourDuMois(int jour, int jourSemaine) {
	const int LARGEUR_COLONNE = 3;
	const int LARGEUR_PREMIERE_COLONNE = 2;
	int largeurJour;

	if (jour == 1) {
		largeurJour = jourSemaine * LARGEUR_COLONNE + LARGEUR_PREMIERE_COLONNE;
	} else {
		largeurJour = jourSemaine == 0 ? LARGEUR_PREMIERE_COLONNE : LARGEUR_COLONNE;
	}

	cout << setw((int) largeurJour) << jour;
}

void afficherMois(int mois, int annee, int &jourSemaine) {
	int nbJours = nbJoursParMois(mois, annee);

	cout << nomDuMois(mois) << " " << annee << endl << endl;
	cout << " L  M  M  J  V  S  D" << endl;

	for (int jour = 1; jour <= nbJours; ++jour, ++jourSemaine) {
		// Nouvelle semaine
		if (jourSemaine == JOURS_PAR_SEMAINE) {
			cout << endl;
			jourSemaine = 0;
		}

		afficherJourDuMois(jour, jourSemaine);
	}
	cout << endl << endl;
	jourSemaine %= JOURS_PAR_SEMAINE;
}

void afficherCalendrier(int moisDebut, int moisFin, int anneeDebut, int anneeFin) {
	int nbMois = nbMoisEntreDeuxDates(moisDebut, moisFin, anneeDebut, anneeFin);
	int jourSemaine = jourDeLaSemaine(1, moisDebut, anneeDebut);
	int moisActuel = moisDebut,
		anneeActuelle = anneeDebut;

	for (int i = 1; i <= nbMois; ++i, ++moisActuel) {
		afficherMois(moisActuel, anneeActuelle, jourSemaine);

		// Nouvelle année
		if (moisActuel % MOIS_PAR_ANNEE == 0) {
			anneeActuelle++;
			moisActuel %= MOIS_PAR_ANNEE;
		}
	}
}
