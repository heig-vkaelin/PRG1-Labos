/*
-----------------------------------------------------------------------------------
Nom du fichier : outils_jeu_vie.h
Auteur(s)      : Jonathan Friedli, Valentin Kaelin, Lazar Pavicevic
Date creation  : 01.12.2020

Description    :

Remarque(s)    :

Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#ifndef LABO4_OUTILS_JEU_VIE_H
#define LABO4_OUTILS_JEU_VIE_H

#include <vector>

enum class EtatsCellules {
	MORTE,
	VIVANTE,
	MOURANTE,
	NAISSANTE
};

const int NB_MIN_SURVIE = 2;
const int NB_MAX_SURVIE = 3;
const int NB_POUR_NAISSANCE = 3;

using Configuration = std::vector<std::vector<size_t>>;
using Ligne = std::vector<EtatsCellules>;
using Grille = std::vector<Ligne>;

/**
 * Lance un nombre de générations du jeu de la vie avec une configuration de
 * polyomino initiale et une grille modifiable.
 * @param configuration Coordonnées du polyomino à créer pour la première génération
 * @param nbGenerations Nombre de générations à effectuer et à afficher
 * @param nbLignes Nombre de lignes à afficher pour la grille
 * @param nbColonnes Nombre de colonnes à afficher pour la grille
 * @param caractereVivante Caractère représentant les cellules vivantes
 * @param caractereMorte Caractère représentant les cellules mortes
 * @param espacementHorizontal Nombre d'espace horizontal entre chaque cellule
 */
void jeuDeLaVie(Configuration &configuration, unsigned nbGenerations,
					 unsigned nbLignes, unsigned nbColonnes, char caractereVivante,
					 char caractereMorte, unsigned espacementHorizontal);

/**
 *
 * @param cellule
 * @return
 */
EtatsCellules confirmerEtatCellule(EtatsCellules cellule);

/**
 *
 * @param grille
 */
void nouvelleGenerationGrille(Grille &grille);

/**
 *
 * @param grille
 * @param ligne
 * @param colonne
 * @return
 */
EtatsCellules actualiserEtatCellule(Grille &grille, size_t ligne, size_t colonne);

/**
 *
 * @param grille
 * @param ligneInitiale
 * @param colonneInitiale
 * @return
 */
unsigned nombreCellulesVoisinesOccupees(Grille &grille, size_t ligneInitiale,
													 size_t colonneInitiale);

#endif //LABO4_OUTILS_JEU_VIE_H
