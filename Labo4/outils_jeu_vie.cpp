//
// Created by Valentin on 26.11.2020.
//

#include <iostream>
#include <algorithm>
#include "polyominos.h"
#include "outils_jeu_vie.h"
#include "outils_affichage.h"

using namespace std;

void jeuDeLaVie(ConfigInitiales config, unsigned nbGenerations, unsigned nbLignes,
					 unsigned nbColonnes) {
	Grille grille = {nbLignes, Ligne(nbColonnes)};
	const char VIVANTE = 'X';
	const char MORTE = '.';
	const int ESPACEMENT = 1;

	appliquerConfigurationInitiale(grille, config);
	afficherGrille(grille, VIVANTE, MORTE, ESPACEMENT);

	for (unsigned i = 0; i < nbGenerations; ++i) {
		etatNouvelleGenerationGrille(grille);
		appliquerNouvelleGenerationGrille(grille);
		afficherGrille(grille, VIVANTE, MORTE, ESPACEMENT);
	}
}

void appliquerConfigurationInitiale(Grille &grille, ConfigInitiales config) {
	Configuration configChoisie = configurationInitiale(config);

	for (vector<size_t> paire : configChoisie) {
		grille.at(paire.at(0)).at(paire.at(1)) = EtatsCellules::VIVANTE;
	}
}

void etatNouvelleGenerationGrille(Grille &grille) {
	for (size_t ligne = 0; ligne < grille.size(); ++ligne) {
		for (size_t colonne = 0; colonne < grille.at(ligne).size(); ++colonne) {
			grille.at(ligne).at(colonne) =
				actualiserEtatCellule(grille, ligne, colonne);
		}
	}
}

EtatsCellules nouvelEtatCelluleSelonRegles(EtatsCellules cellule, unsigned
nbOccurrences) {
	if (cellule == EtatsCellules::VIVANTE &&
		 nbOccurrences != 2 && nbOccurrences != 3) {
		return EtatsCellules::MOURANTE;
	} else if (cellule == EtatsCellules::MORTE && nbOccurrences == 3) {
		return EtatsCellules::NAISSANTE;
	}

	return cellule;
}

EtatsCellules actualiserEtatCellule(Grille &grille, size_t ligne, size_t colonne) {
	EtatsCellules etatCellule = grille.at(ligne).at(colonne);
	unsigned nbOccurrences = occurrences(grille, ligne, colonne);

	return nouvelEtatCelluleSelonRegles(etatCellule, nbOccurrences);
}

bool conditionsCelluleOccupee(EtatsCellules cellule) {
	return cellule == EtatsCellules::VIVANTE || cellule == EtatsCellules::MOURANTE;
}

unsigned occurrences(Grille &grille, size_t ligneInitiale, size_t colonneInitiale) {
	unsigned nbOccupees = 0;
	size_t ligne = ligneInitiale == 0 ? 0 : ligneInitiale - 1;
	size_t colonneMin = colonneInitiale == 0 ? 0 : colonneInitiale - 1;

	size_t ligneMax = min(ligneInitiale + 1, grille.size() - 1);
	size_t colonneMax = min(colonneInitiale + 1, grille.at(ligne).size() - 1);

	for (; ligne <= ligneMax; ++ligne) {
		for (size_t colonne = colonneMin; colonne <= colonneMax; ++colonne) {
			// Passer le tour de boucle s'il s'agit de la cellule analysée
			if (ligne == ligneInitiale && colonne == colonneInitiale) {
				continue;
			}
			EtatsCellules cellule = grille.at(ligne).at(colonne);

			if (conditionsCelluleOccupee(cellule)) {
				nbOccupees++;
			}
		}
	}

	return nbOccupees;
}

EtatsCellules confirmerEtatCellule(EtatsCellules cellule) {
	if (cellule == EtatsCellules::NAISSANTE) {
		return EtatsCellules::VIVANTE;
	} else if (cellule == EtatsCellules::MOURANTE) {
		return EtatsCellules::MORTE;
	}

	return cellule;
}

void appliquerNouvelleGenerationGrille(Grille &grille) {
	for (Ligne &ligne : grille) {
		transform(ligne.begin(), ligne.end(), ligne.begin(), confirmerEtatCellule);
	}
}
