//
// Created by Valentin on 26.11.2020.
//

#include <iostream>
#include <iomanip>
#include "outils_jeu_vie.h"
#include "outils_affichage.h"

using namespace std;

void afficherGrille(const Grille &grille, char caractereVivante, char
caractereMorte, int espacement) {
	for (const Ligne &ligne : grille) {
		for (size_t i = 0; i < ligne.size(); ++i) {
			int largeur = i > 0 ? espacement + 1 : espacement;
			cout << setw(largeur)
				  << (ligne.at(i) == EtatsCellules::VIVANTE ? vivante : morte);
		}
		cout << endl;
	}
	cout << endl;
}