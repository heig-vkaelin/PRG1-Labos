#include <cstdlib>
#include "affichage.h"
#include "logique.h"

using namespace std;

const unsigned JOURS_PAR_SEMAINE = 7;
const unsigned MOIS_PAR_ANNEE = 12;

int main() {
	do {
		// Valeurs pour tester rapidement
//		unsigned moisDebut = 11;
//		unsigned anneeDebut = 2020;
//		unsigned moisFin = 1;
//		unsigned anneeFin = 2021;

		unsigned moisDebut, moisFin, anneeDebut, anneeFin;

		afficherDemandesDeSaisie(moisDebut, moisFin, anneeDebut, anneeFin);

		unsigned nbMois = nbMoisEntreDeuxDates(moisDebut, moisFin, anneeDebut,
															anneeFin);

		unsigned anneeActuelle = anneeDebut;
		unsigned premierJourDuMois = jourDeLaSemaine(1, moisDebut, anneeActuelle);
		unsigned jourDeLaSemaine = premierJourDuMois;
		for (unsigned i = 0; i < nbMois; ++i) {
			unsigned moisActuel = (moisDebut + i - 1) % MOIS_PAR_ANNEE + 1;
			unsigned nbJours = nbJoursParMois(moisActuel, anneeActuelle);

			afficheMois(moisActuel, anneeActuelle, nbJours, jourDeLaSemaine);

			if (moisActuel == MOIS_PAR_ANNEE) {
				anneeActuelle++;
			}
		}
	} while (relancerProgramme());

	return EXIT_SUCCESS;
}
