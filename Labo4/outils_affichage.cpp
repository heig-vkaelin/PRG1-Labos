//
// Created by Valentin on 26.11.2020.
//

#include <iostream>
#include <iomanip>
#include "outils_jeu_vie.h"
#include "outils_affichage.h"

using namespace std;

void afficherGrille(const Grille &grille, char vivante, char morte, int espacement) {
	for (const Ligne &ligne : grille) {
		for (EtatsCellules val : ligne) {
			cout << (val == EtatsCellules::VIVANTE ? vivante : morte)
				  << setw(espacement + 1);
		}
		cout << endl;
	}
	cout << endl;
}