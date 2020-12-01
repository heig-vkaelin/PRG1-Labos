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
 *
 * @param grille
 * @param caractereVivante
 * @param caractereMorte
 * @param espacementHorizontal
 */
void afficherGrille(const Grille &grille, char caractereVivante, char
caractereMorte, unsigned espacementHorizontal);

#endif //LABO4_OUTILS_AFFICHAGE_H
