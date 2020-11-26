//
// Created by Valentin on 26.11.2020.
//

#include <iostream>
#include "logique.h"

using namespace std;

void afficherGrille(const Grille &grille) {
	for (Colonne col : grille) {
		for (ETATS_CELLULES val : col) {

			char yolo;

			if(val == ETATS_CELLULES::MOURANTE) {
				yolo = 'M';
			} else if(ETATS_CELLULES::NAISSANTE == val) {
				yolo = 'N';
			} else if (ETATS_CELLULES::VIVANTE == val) {
				yolo = 'X';
			} else {
				yolo = '.';
			}

//			cout << (val == ETATS_CELLULES::VIVANTE ? 'X' : '.') << ' ';
			cout << yolo << ' ';
		}
		cout << endl;
	}
	cout << endl;
}