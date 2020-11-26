//
// Created by Valentin on 26.11.2020.
//

#ifndef LABO4_LOGIQUE_H
#define LABO4_LOGIQUE_H

#include <array>

constexpr unsigned NB_LIGNES = 10;
constexpr unsigned NB_COLONNES = 11;

enum class CONFIG_INITIALES {
	TETRAMINO_T
};

enum class ETATS_CELLULES {
	MORTE,
	VIVANTE,
	MOURANTE,
	NAISSANTE
};

using Colonne = std::array<ETATS_CELLULES, NB_COLONNES>;
using Grille = std::array<Colonne, NB_LIGNES>;

void jeuDeLaVie(CONFIG_INITIALES config, int nbGenerations);

void configurationInitiale(Grille &grille, CONFIG_INITIALES config);

void tetraminoT(Grille &grille);

void analyseGrille(Grille &grille);

ETATS_CELLULES actualiserEtatCellule(Grille &grille, size_t ligne, size_t colonne);

unsigned occurrences(Grille &grille, size_t ligne, size_t colonne);

void actualiserGrille(Grille &grille);

#endif //LABO4_LOGIQUE_H
