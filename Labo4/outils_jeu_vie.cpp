/*
-----------------------------------------------------------------------------------
Nom du fichier : outils_jeu_vie.cpp
Auteur(s)      : Jonathan Friedli, Valentin Kaelin, Lazar Pavicevic
Date creation  : 01.12.2020

Description    : Fichier contenant toute l'implémentation concernant le
                 fonctionnement du jeu de la vie.

Remarque(s)    : Dans l'actualisation de la grille, nous utilisons deux sous-états:
                 mourante et naissante. Ces sous-états sont nécessaires pour que
                 le calcul des voisins vivants de chaque cellule ne soit pas faussé.
                 En effet, si nous tuons une cellule instantanément, la cellule
                 voisine qui aurait peut-être pu survivre grâce à cette cellule
                 risque de mourir également.
                 Nous utilisons des vecteurs à deux dimensions pour la grille de
                 jeu afin que l'utilisateur puisse changer la taille de la grille
                 facilement.
                 Nous utilisons des vecteurs de unsigned char car les états
                 possibles pour les cellules sont limités et nous ne faisons pas
                 d'opérations arithmétiques dessus. Ce qui nous permet d'optimiser
                 la taille en mémoire de la grille.
                 Nous passons toujours la grille par référence dans les diverses
                 fonctions afin d'éviter de faire des copies inutiles.
                 Les constantes concernant les règles de survie et de mort des
                 cellules ne devraient pas être modifiées afin de respecter
                 l'implémentation du jeu de la vie de J. H. Conway.

Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include <algorithm>
#include "outils_jeu_vie.h"
#include "outils_affichage.h"

using namespace std;

constexpr int NB_MIN_SURVIE = 2;
constexpr int NB_MAX_SURVIE = 3;
constexpr int NB_POUR_NAISSANCE = 3;

void jeuDeLaVie(Configuration &configuration, unsigned nbGenerations,
					 unsigned nbLignes, unsigned nbColonnes, char caractereVivante,
					 char caractereMorte, unsigned espacementHorizontal) {

	Grille grille = {nbLignes, Ligne(nbColonnes)};

	// Application de la configuration initiale choisie
	// Utilisation de .at() car il s'agit d'une entrée utilisateur
	for (vector<size_t> paire : configuration) {
		grille.at(paire.at(0)).at(paire.at(1)) = EtatsCellules::VIVANTE;
	}
	afficherGrille(grille, caractereVivante, caractereMorte, espacementHorizontal);

	for (unsigned i = 0; i < nbGenerations; ++i) {
		nouvelleGenerationGrille(grille);
		afficherGrille(grille, caractereVivante, caractereMorte, espacementHorizontal);
	}
}

EtatsCellules confirmerEtatCellule(EtatsCellules cellule) {
	if (cellule == EtatsCellules::NAISSANTE) {
		return EtatsCellules::VIVANTE;
	} else if (cellule == EtatsCellules::MOURANTE) {
		return EtatsCellules::MORTE;
	}

	return cellule;
}

void nouvelleGenerationGrille(Grille &grille) {
	for (size_t ligne = 0; ligne < grille.size(); ++ligne) {
		for (size_t colonne = 0; colonne < grille[ligne].size(); ++colonne) {
			grille[ligne][colonne] = actualiserEtatCellule(grille, ligne, colonne);
		}
	}

	// Transformer les cellules qui vont naître en vivante et celles qui sont
	// mourantes en mortes
	for (Ligne &ligne : grille) {
		transform(ligne.begin(), ligne.end(), ligne.begin(), confirmerEtatCellule);
	}
}

EtatsCellules actualiserEtatCellule(Grille &grille, size_t ligne, size_t colonne) {
	EtatsCellules etatCellule = grille[ligne][colonne];
	unsigned nbOccurrences = nombreCellulesVoisinesOccupees(grille, ligne, colonne);

	if (etatCellule == EtatsCellules::VIVANTE &&
		 nbOccurrences != NB_MIN_SURVIE && nbOccurrences != NB_MAX_SURVIE) {
		return EtatsCellules::MOURANTE;
	} else if (etatCellule == EtatsCellules::MORTE &&
				  nbOccurrences == NB_POUR_NAISSANCE) {
		return EtatsCellules::NAISSANTE;
	}

	return etatCellule;
}

unsigned nombreCellulesVoisinesOccupees(Grille &grille, size_t ligneInitiale,
													 size_t colonneInitiale) {
	unsigned nbOccupees = 0;
	size_t ligne = ligneInitiale == 0 ? 0 : ligneInitiale - 1;
	size_t colonneMin = colonneInitiale == 0 ? 0 : colonneInitiale - 1;

	size_t ligneMax = min(ligneInitiale + 1, grille.size() - 1);
	size_t colonneMax = min(colonneInitiale + 1, grille[ligne].size() - 1);

	for (; ligne <= ligneMax; ++ligne) {
		for (size_t colonne = colonneMin; colonne <= colonneMax; ++colonne) {
			// Passer le tour de boucle s'il s'agit de la cellule analysée
			if (ligne == ligneInitiale && colonne == colonneInitiale) {
				continue;
			}
			EtatsCellules cellule = grille[ligne][colonne];

			if (cellule == EtatsCellules::VIVANTE ||
				 cellule == EtatsCellules::MOURANTE) {
				nbOccupees++;
			}
		}
	}

	return nbOccupees;
}
