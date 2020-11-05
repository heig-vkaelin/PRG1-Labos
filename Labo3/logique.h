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
 * @return true si l'année est bissextile, false autrement
 */
bool estBissextile(unsigned annee);

/**
 * Détermine le nombre de jours d'un mois d'une année
 * @param noMois
 * @param annee
 * @return nombre de mois
 */
unsigned nbJoursParMois(unsigned noMois, unsigned annee);


 /**
  * Détermine le nombre de mois (bornes comprises) entre deux dates
  * La fonction ne vérifie pas que la date de début soit bien avant celle de fin.
  * @param moisDebut : mois de début, compris dans le résultat final
  * @param moisFin : mois de fin, compris dans le résultat final
  * @param anneeDebut : année de début
  * @param anneeFin : année de fin
  * @return true si la date de fin est plus grande que la date de début
  */
unsigned nbMoisEntreDeuxDates(unsigned moisDebut, unsigned moisFin, unsigned
anneeDebut, unsigned anneeFin);

#endif //LABO3_LOGIQUE_H
