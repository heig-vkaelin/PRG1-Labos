/*
-----------------------------------------------------------------------------------
Nom du fichier : outils_jeu_vie.h
Auteur(s)      : Jonathan Friedli, Valentin Kaelin, Lazar Pavicevic
Date creation  : 01.12.2020

Description    : Module contenant la logique concernant le jeu de la vie. Permet
                 de créer un nombre de générations de grille en partant d'une
                 configuration initiale. Toute la configuration initiale est
                 configurable par l'utilisateur.

Remarque(s)    : L'énumération des états des cellules contient deux états
                 principaux: morte et vivante ainsi que deux sous-états: mourante
                 et naissante. Ces sous-états sont nécessaires pour que le calcul
                 des voisins vivants de chaque cellule ne soit pas faussé.

Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#ifndef LABO4_OUTILS_JEU_VIE_H
#define LABO4_OUTILS_JEU_VIE_H

#include <vector>

enum class EtatsCellules : unsigned char {
	MORTE,
	VIVANTE,
	MOURANTE,
	NAISSANTE
};

using Configuration = std::vector<std::vector<size_t>>;
using Ligne = std::vector<EtatsCellules>;
using Grille = std::vector<Ligne>;

/**
 * Lance un nombre de générations du jeu de la vie avec une configuration de
 * polyomino initiale et une grille modifiable.
 * @param configuration : coordonnées du polyomino à créer pour la première
 * génération
 * @param nbGenerations : nombre de générations à effectuer et à afficher
 * @param nbLignes : nombre de lignes à afficher pour la grille
 * @param nbColonnes : nombre de colonnes à afficher pour la grille
 * @param caractereVivante : caractère représentant les cellules vivantes
 * @param caractereMorte : caractère représentant les cellules mortes
 * @param espacementHorizontal : nombre d'espace horizontal entre chaque cellule
 */
void jeuDeLaVie(Configuration &configuration, unsigned nbGenerations,
					 unsigned nbLignes, unsigned nbColonnes, char caractereVivante,
					 char caractereMorte, unsigned espacementHorizontal);

/**
 * Confirme l'état de la cellule pour la prochaine génération:
 * transforme les cellules naissante en vivante et les mourantes en mortes.
 * @param cellule : valeur initiale de la cellule
 * @return la nouvelle valeur de la cellule
 */
EtatsCellules confirmerEtatCellule(EtatsCellules cellule);

/**
 * Actualise l'état de chaque cellule de la grille pour la prochaine génération.
 * @param grille : grille du jeu
 */
void nouvelleGenerationGrille(Grille &grille);

/**
 * Met à jour l'état d'une cellule choisie en fonction de son état actuel ainsi
 * que du nombre de cellules occupées parmi ses voisins.
 * @param grille : grille du jeu
 * @param ligne : ligne de la cellule
 * @param colonne : colonne de la cellule
 * @return nouvelle valeur de la cellule
 */
EtatsCellules actualiserEtatCellule(Grille &grille, size_t ligne, size_t colonne);

/**
 * Calcule le nombre de cellules voisines qui sont vivantes (chaque cellule a 8
 * cellules voisines, exception faite pour les cellules étant au bord de la grille).
 * @param grille : grille du jeu
 * @param ligneInitiale : ligne de la cellule dont on veut calculer les voisins
 * vivants
 * @param colonneInitiale : colonne de la cellule dont on veut calculer les
 * voisins vivant
 * @return le nombre de cellules voisines vivantes
 */
unsigned nombreCellulesVoisinesOccupees(Grille &grille, size_t ligneInitiale,
													 size_t colonneInitiale);

#endif // LABO4_OUTILS_JEU_VIE_H
