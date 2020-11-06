#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "affichage.h"
#include "logique.h"

using namespace std;

int main() {
	do {
		// Valeurs pour tester rapidement
		//	unsigned moisDebut = 12;
		//	unsigned anneeDebut = 2015;
		//	unsigned moisFin = 11;
		//	unsigned anneeFin = 2021;

		unsigned moisDebut, anneeDebut, moisFin, anneeFin;
		afficherDemandesDeSaisie(moisDebut, moisFin, anneeDebut, anneeFin);

		unsigned nbMois = nbMoisEntreDeuxDates(moisDebut, moisFin, anneeDebut, anneeFin);

		unsigned anneeActuelle = anneeDebut;
		for (unsigned i = 0; i < nbMois; ++i) {
			unsigned moisActuel = (moisDebut + i - 1) % 12 + 1;
			unsigned nbJours = nbJoursParMois(moisActuel, anneeActuelle);

			cout << "Mois actuel: " << moisActuel << "." << anneeActuelle << " "
				  << nbJours << " jours - Index: " << i << endl;

			// afficherUnMois(moisActuel, anneeActuelle);
			// Fonction Afficher un mois
			cout << setw(9) << moisActuel << " " << anneeActuelle << endl;
			// Fonction Afficher jours de la semaine
			for (int jour = 0; jour < 7; ++jour) {
				cout << "" << " ";
			}
			cout << endl;
			// Fin Fonction Afficher jours de la semaine
			// Fin fonction Afficher un mois

			if (moisActuel == 12) {
				anneeActuelle++;
			}
		}
	} while(relancerProgramme());


	return EXIT_SUCCESS;
}
