/*
-----------------------------------------------------------------------------------
Nom du fichier : outils_affichage.h
Auteur(s)      : Jonathan Friedli, Valentin Kaelin, Lazar Pavicevic
Date creation  : 01.12.2020

Description    :

Remarque(s)    :

Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#ifndef LABO4_OUTILS_AFFICHAGE_H
#define LABO4_OUTILS_AFFICHAGE_H

/**
 * Affiche la grille du jeu, avec des caractères à choix pour les cellules
 * vivantes et mortes.
 * @param grille : grille du jeu
 * @param caractereVivante : caractère à afficher si la cellule est vivante
 * @param caractereMorte : caractère à afficher si la cellule est morte
 * @param espacementHorizontal : nombre d'espace entre les cellules
 */
void afficherGrille(const Grille &grille, char caractereVivante, char
caractereMorte, unsigned espacementHorizontal);

#endif //LABO4_OUTILS_AFFICHAGE_H
