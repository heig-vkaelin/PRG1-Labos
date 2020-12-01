/*
-----------------------------------------------------------------------------------
Nom du fichier : outils_affichage.cpp
Auteur(s)      : Jonathan Friedli, Valentin Kaelin, Lazar Pavicevic
Date creation  : 01.12.2020

Description    : Fichier contenant la logique de l'affichage des grilles du jeu de
                 la vie.

Remarque(s)    : Nous avons créé un module pour l'affichage en dépit du fait qu'il
                 ne contient qu'une seule fonction par soucis d'évolutivité.

Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include <iostream>
#include <iomanip>
#include "outils_jeu_vie.h"
#include "outils_affichage.h"

using namespace std;

void afficherGrille(const Grille &grille, char caractereVivante,
						  char caractereMorte, unsigned espacementHorizontal) {
	for (const Ligne &ligne : grille) {
		for (size_t i = 0; i < ligne.size(); ++i) {
			unsigned largeur = i > 0 ? espacementHorizontal + 1 : espacementHorizontal;
			cout << setw((int) largeur)
				  << (ligne[i] == EtatsCellules::VIVANTE ? caractereVivante
																	  : caractereMorte);
		}
		cout << endl;
	}
	cout << endl;
}
