/*
-----------------------------------------------------------------------------------
Nom du fichier : date.cpp
Auteur(s)      : Jonathan Friedli, Valentin Kaelin, Lazar Pavicevic
Date creation  : 05.11.2020

Description    : Fichier contenant toute la logique se rapportant aux dates.
                 C'est également dans ce fichier que les constantes concernant les
                 dates sont déclarées. Comme par exemple les bornes inférieures et
                 supérieures pour les années.

Remarque(s)    : Une année est bissextile est divisible par 400 ou alors par 4
                 mais pas par 100.
                 Utilisation de tableaux interdite.
                 Voici le site où l'on a trouvé l'algorithme pour la fonction
                 jourDeLasemaine : https://bit.ly/3eHAmw3

Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include <string>
#include "date.h"

using namespace std;

enum class Mois {
	JANVIER = 1, FEVRIER, MARS, AVRIL, MAI, JUIN, JUILLET, AOUT,
	SEPTEMBRE, OCTOBRE, NOVEMBRE, DECEMBRE
};

const int JOURS_PAR_SEMAINE = 7;
const int MOIS_PAR_ANNEE = 12;
const int ANNEE_BORNE_INFERIEURE = 1900;
const int ANNEE_BORNE_SUPERIEURE = 2100;
const int MOIS_BORNE_INFERIEURE = 1;
const int MOIS_BORNE_SUPERIEURE = MOIS_PAR_ANNEE;

bool estBissextile(int annee) {
	return annee % 400 == 0 || (annee % 4 == 0 && annee % 100 != 0);
}

int nbJoursParMois(int noMois, int annee) {
	switch ((Mois) noMois) {
		case Mois::FEVRIER:
			return estBissextile(annee) ? 29 : 28;
		case Mois::AVRIL:
		case Mois::JUIN:
		case Mois::SEPTEMBRE:
		case Mois::NOVEMBRE:
			return 30;
		default:
			return 31;
	}
}

int nbMoisEntreDeuxDates(int moisDebut, int moisFin, int anneeDebut, int anneeFin) {
	int dateDebut = anneeDebut * MOIS_PAR_ANNEE + moisDebut;
	int dateFin = anneeFin * MOIS_PAR_ANNEE + moisFin;

	// Mois de début et de fin compris
	return dateFin - dateDebut + 1;
}

bool dateDansIntervalle(int mois, int annee) {
	return mois >= MOIS_BORNE_INFERIEURE && mois <= MOIS_BORNE_SUPERIEURE &&
			 annee >= ANNEE_BORNE_INFERIEURE && annee <= ANNEE_BORNE_SUPERIEURE;
}

bool dateDebutAvantFin(int moisDebut, int moisFin, int anneeDebut, int anneeFin) {
	return anneeDebut * MOIS_PAR_ANNEE + moisDebut <=
			 anneeFin * MOIS_PAR_ANNEE + moisFin;
}

int jourDeLaSemaine(int jour, int mois, int annee) {
	// On compense le fait que février n'a que 28 jours.
	int compensationFevrier = 2;
	if (mois < 3) {
		annee--;
		compensationFevrier = 4;
	}
	// On a rajouté un -1 à l'algorithme afin que le dimanche ne soit plus le jour 0
	// mais le jour 6.
	return
		(23 * mois / 9 + jour + compensationFevrier + annee + annee / 4 - annee / 100 +
		 annee / 400 - 1) % JOURS_PAR_SEMAINE;
}

string nomDuMois(int noMois) {
	switch ((Mois) noMois) {
		case Mois::JANVIER:
			return "Janvier";
		case Mois::FEVRIER:
			return "Fevrier";
		case Mois::MARS:
			return "Mars";
		case Mois::AVRIL:
			return "Avril";
		case Mois::MAI:
			return "Mai";
		case Mois::JUIN:
			return "Juin";
		case Mois::JUILLET:
			return "Juillet";
		case Mois::AOUT:
			return "Aout";
		case Mois::SEPTEMBRE:
			return "Septembre";
		case Mois::OCTOBRE:
			return "Octobre";
		case Mois::NOVEMBRE:
			return "Novembre";
		case Mois::DECEMBRE:
			return "Decembre";
		default:
			return "";
	}
}
