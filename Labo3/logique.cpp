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

bool estBissextile(unsigned annee) {
	return annee % 400 == 0 || (annee % 4 == 0 && annee % 100 != 0);
}

unsigned nbJoursParMois(unsigned noMois, unsigned annee) {
	enum class Mois {
		JANVIER = 1, FEVRIER, MARS, AVRIL, MAI, JUIN, JUILLET, AOUT,
		SEPTEMBRE, OCTOBRE, NOVEMBRE, DECEMBRE
	};
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
	unsigned debut = anneeDebut * 12 + moisDebut;
	unsigned fin = anneeFin * 12 + moisFin;

	// Si la date de début se trouve après la date de fin: arrêt du programme car
	// problème dans la logique du code. En effet, ce cas ne devrait jamais se
	// produire grâce aux différents tests réalisés lors de la saisie
	assert(debut <= fin);

	// Mois de début et de fin compris
	return fin - debut + 1;
}

bool dateDansIntervalle(unsigned mois, unsigned annee) {
	unsigned int MOIS_BORNE_INFERIEURE = 1;
	unsigned int MOIS_BORNE_SUPERIEURE = 12;
	unsigned int ANNEE_BORNE_INFERIEURE = 1900;
	unsigned int ANNEE_BORNE_SUPERIEURE = 2100;

	return mois >= MOIS_BORNE_INFERIEURE && mois <= MOIS_BORNE_SUPERIEURE &&
			 annee >= ANNEE_BORNE_INFERIEURE && annee <= ANNEE_BORNE_SUPERIEURE;
}

bool dateDebutAvantFin(unsigned moisDebut, unsigned moisFin, unsigned anneeDebut,
							  unsigned anneeFin) {
	return anneeDebut * 12 + moisDebut <= anneeFin * 12 + moisFin;
}

