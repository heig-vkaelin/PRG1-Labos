/*
-----------------------------------------------------------------------------------
Nom du fichier : <nom du fichier>.<xxx> (xxx = h ou cpp)
Auteur(s) : <prénom> <nom>
Date creation : <jj.mm.aaaa>

Description : <à compléter>

Remarque(s) : <à compléter>

Compilateur : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#ifndef LABO3_LOGIQUE_H
#define LABO3_LOGIQUE_H

/**
 * Détermine si une année est bissextile ou pas
 * @param annee
 * @return vrai si l'année est bissextile, faux autrement
 */
bool estBissextile(unsigned annee);

/**
 * Détermine le nombre de jours d'un mois d'une année
 * @param noMois
 * @param annee
 * @return nombre de mois
 */
unsigned nbJoursParMois(unsigned noMois, unsigned annee);

#endif //LABO3_LOGIQUE_H
