//
// Created by Valentin on 26.11.2020.
//

#include <array>
#include <iostream>
#include "affichage.h"
#include "logique.h"

using namespace std;

void jeuDeLaVie(CONFIG_INITIALES config, int nbGenerations) {
	Grille grille = {};

	configurationInitiale(grille, config);
	afficherGrille(grille);

	while (nbGenerations > 0 || nbGenerations == -1) {
		analyseGrille(grille);

		afficherGrille(grille);


		actualiserGrille(grille);


		if (nbGenerations != -1) {
			nbGenerations--;
		}
	}
}

void configurationInitiale(Grille &grille, CONFIG_INITIALES config) {
	switch (config) {
		case CONFIG_INITIALES::TETRAMINO_T:
			return tetraminoT(grille);
		default:
			return tetraminoT(grille);
	}
}

void tetraminoT(Grille &grille) {
	grille.at(4).at(4) = ETATS_CELLULES::VIVANTE;
	grille.at(4).at(5) = ETATS_CELLULES::VIVANTE;
	grille.at(4).at(6) = ETATS_CELLULES::VIVANTE;
	grille.at(5).at(5) = ETATS_CELLULES::VIVANTE;
}


void analyseGrille(Grille &grille) {
	for (size_t ligne = 0; ligne < grille.size(); ++ligne) {
		for (size_t colonne = 0; colonne < grille.at(ligne).size(); ++colonne) {
			grille.at(ligne).at(colonne) =
				actualiserEtatCellule(grille, ligne, colonne);
		}
		cout << endl;
	}
}

ETATS_CELLULES actualiserEtatCellule(Grille &grille, size_t ligne, size_t colonne) {
	ETATS_CELLULES etatCellule = grille.at(ligne).at(colonne);
	unsigned nbOccurrences = occurrences(grille, ligne, colonne);
	cout << nbOccurrences;

	if (etatCellule == ETATS_CELLULES::VIVANTE &&
		 nbOccurrences != 2 && nbOccurrences != 3) {
		etatCellule = ETATS_CELLULES::MOURANTE;
	} else if (etatCellule == ETATS_CELLULES::MORTE && nbOccurrences == 3) {
		etatCellule = ETATS_CELLULES::NAISSANTE;
	}

	return etatCellule;
}

unsigned occurrences(Grille &grille, size_t ligne, size_t colonne) {
	unsigned nbOccupees = 0;
	unsigned nbBoucle = 0;
	size_t i = ligne == 0 ? 0 : ligne - 1;
	size_t j = colonne == 0 ? 0 : colonne - 1;

	size_t iMax = ligne + 1 == NB_LIGNES ? NB_LIGNES - 1 : ligne + 1;
	size_t jMax = colonne + 1 == NB_COLONNES ? NB_COLONNES - 1 : colonne + 1;

	for (; i <= iMax; ++i) {
		for (; j <= jMax; ++j) {
			nbBoucle++;
			// Passer le tour de boucle s'il s'agit de la cellule analysée
			if (i == ligne && j == colonne) {
				continue;
			}
			ETATS_CELLULES cellule = grille.at(i).at(j);

			if (cellule == ETATS_CELLULES::VIVANTE ||
				 cellule == ETATS_CELLULES::MOURANTE) {
				nbOccupees++;
			}
		}
	}

	return nbOccupees;
}

void actualiserGrille(Grille &grille) {
	for (Colonne &col : grille) {
		for (ETATS_CELLULES &val : col) {
			if (val == ETATS_CELLULES::NAISSANTE) {
				val = ETATS_CELLULES::VIVANTE;
			} else if (val == ETATS_CELLULES::MOURANTE) {
				val = ETATS_CELLULES::MORTE;
			}
		}
	}
}
