/*
-----------------------------------------------------------------------------------
Nom du fichier	: date.h
Auteur(s)		: Valentin Kaelin, Jonathan Friedli, Lazar Pavicevic
Date creation	: 05.11.2020

Description		: <à compléter>

Remarque(s)		: <à compléter>

Compilateur		: Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#ifndef LABO3_DATE_H
#define LABO3_DATE_H

#include <string>

extern const unsigned JOURS_PAR_SEMAINE;
extern const unsigned MOIS_PAR_ANNEE;

/**
 * Détermine si une année est bissextile ou pas
 * @param annee
 * @return true si l'année est bissextile, false autrement
 */
bool estBissextile(unsigned annee);

/**
 * Détermine le nombre de jours d'un mois d'une année
 * @param noMois : numéro du mois [1-12]
 * @param annee
 * @return nombre de jours d'un mois
 */
unsigned nbJoursParMois(unsigned noMois, unsigned annee);


/**
 * Détermine le nombre de mois (bornes comprises) entre deux dates
 * Condition: date de début <= date de fin
 * Dans le cas contraire, la fonction assert et termine le programme si la date de
 * début est après celle de fin.
 * @param moisDebut : mois de début, compris dans le résultat final
 * @param moisFin : mois de fin, compris dans le résultat final
 * @param anneeDebut : année de début
 * @param anneeFin : année de fin
 * @return le nombre de mois entre les deux dates
 */
unsigned nbMoisEntreDeuxDates(unsigned moisDebut, unsigned moisFin, unsigned
anneeDebut, unsigned anneeFin);

/**
 * Vérifie que le mois et l'année sont compris dans leur intervalle respectif.
 * Intervalle du mois: [1;12]
 * @param mois
 * @param annee
 * @return true si le mois et l'année sont compris dans leur intervalle respectif.
 */
bool dateDansIntervalle(unsigned mois, unsigned annee);

/**
 * Vérifie que la date de début est plus petite (et donc plus ancienne) que la
 * date de fin.
 * @param moisDebut
 * @param moisFin
 * @param anneeDebut
 * @param anneeFin
 * @return true si la date de début est plus petite que la date de fin.
 */
bool dateDebutAvantFin(unsigned moisDebut, unsigned moisFin, unsigned anneeDebut,
							  unsigned anneeFin);

/**
 * On entre une date et la fonction détermine le numéro du jour de la semaine.
 * Le jour vaudra 0 si c'est un lundi, 1 si c'est un mardi, ..., et 6 pour dimanche.
 * @param jour
 * @param mois
 * @param annee
 * @return Le numéro du jour de la semaine
 */
unsigned jourDeLaSemaine(unsigned jour, unsigned mois, unsigned annee);

/**
 * Retourne le nom du mois en français selon son index
 * @param noMois : numéro du mois [1-12]
 * @return une chaîne de caractères contenant le nom du mois en français
 */
std::string nomDuMois(unsigned noMois);

#endif //LABO3_DATE_H
