//
// Created by Valentin on 26.11.2020.
//

#ifndef LABO4_OUTILS_JEU_VIE_H
#define LABO4_OUTILS_JEU_VIE_H

#include <vector>
// TODO: pourquoi on a besoin de cet include ????
#include "polyominos.h"

enum class EtatsCellules {
	MORTE,
	VIVANTE,
	MOURANTE,
	NAISSANTE
};

using Ligne = std::vector<EtatsCellules>;
using Grille = std::vector<Ligne>;

void jeuDeLaVie(ConfigInitiales config, unsigned nbGenerations, unsigned nbLignes,
					 unsigned nbColonnes);

void appliquerConfigurationInitiale(Grille &grille, ConfigInitiales config);

void etatNouvelleGenerationGrille(Grille &grille);

EtatsCellules nouvelEtatCelluleSelonRegles(EtatsCellules cellule, unsigned
nbOccurrences);

EtatsCellules actualiserEtatCellule(Grille &grille, size_t ligne, size_t colonne);

bool conditionsCelluleOccupee(EtatsCellules cellule);

unsigned occurrences(Grille &grille, size_t ligneInitiale, size_t colonneInitiale);

EtatsCellules confirmerEtatCellule(EtatsCellules cellule);

void appliquerNouvelleGenerationGrille(Grille &grille);

#endif //LABO4_OUTILS_JEU_VIE_H
