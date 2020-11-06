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

#include <cassert>
#include "logique.h"

enum class Mois {
	JANVIER = 1, FEVRIER, MARS, AVRIL, MAI, JUIN, JUILLET, AOUT,
	SEPTEMBRE, OCTOBRE, NOVEMBRE, DECEMBRE
};

bool estBissextile(unsigned annee) {
	return annee % 400 == 0 || (annee % 4 == 0 && annee % 100 != 0);
}

unsigned nbJoursParMois(unsigned noMois, unsigned annee) {
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

unsigned nbMoisEntreDeuxDates(unsigned moisDebut, unsigned moisFin, unsigned
anneeDebut, unsigned anneeFin) {
	unsigned debut = anneeDebut * MOIS_PAR_ANNEE + moisDebut;
	unsigned fin = anneeFin * MOIS_PAR_ANNEE + moisFin;

	// Si la date de début se trouve après la date de fin: arrêt du programme car
	// problème dans la logique du code. En effet, ce cas ne devrait jamais se
	// produire grâce aux différents tests réalisés lors de la saisie
	assert(debut <= fin);

	// Mois de début et de fin compris
	return fin - debut + 1;
}

bool dateDansIntervalle(unsigned mois, unsigned annee) {
	unsigned int MOIS_BORNE_INFERIEURE = 1;
	unsigned int MOIS_BORNE_SUPERIEURE = MOIS_PAR_ANNEE;
	unsigned int ANNEE_BORNE_INFERIEURE = 1900;
	unsigned int ANNEE_BORNE_SUPERIEURE = 2100;

	return mois >= MOIS_BORNE_INFERIEURE && mois <= MOIS_BORNE_SUPERIEURE &&
			 annee >= ANNEE_BORNE_INFERIEURE && annee <= ANNEE_BORNE_SUPERIEURE;
}

bool dateDebutAvantFin(unsigned moisDebut, unsigned moisFin, unsigned anneeDebut,
							  unsigned anneeFin) {
	return anneeDebut * MOIS_PAR_ANNEE + moisDebut <=
			 anneeFin * MOIS_PAR_ANNEE + moisFin;
}

unsigned jourDeLaSemaine(unsigned jour, unsigned mois, unsigned annee) {
	// On compense le fait que février n'a que 28 jours.
	unsigned compensationFevrier = 2;
	if (mois < 3) {
		annee--;
		compensationFevrier = 4;
	}
	return
		(23 * mois / 9 + jour + compensationFevrier + annee + annee / 4 - annee / 100 +
		 annee / 400 - 1) % JOURS_PAR_SEMAINE;
}

unsigned espacementJourDuMois(unsigned jour, unsigned jourDeLaSemaine) {
	const unsigned LARGEUR_COLONNE = 3;
	const unsigned LARGEUR_PREMIERE_COLONNE = 2;

	if (jour == 0) {
		return jourDeLaSemaine * LARGEUR_COLONNE + LARGEUR_PREMIERE_COLONNE;
	}
	return jourDeLaSemaine == 0 ? LARGEUR_PREMIERE_COLONNE : LARGEUR_COLONNE;
}
