/*
-----------------------------------------------------------------------------------
Nom du fichier : date.h
Auteur(s)      : Jonathan Friedli, Valentin Kaelin, Lazar Pavicevic
Date creation  : 05.11.2020

Description    : Fichier d'en-tête contenant les prototypes des fonctions ainsi
                 que les variables externes du fichier date.cpp.

Remarque(s)    : Les paramètres de mois et jours du mois des différentes fonctions
                 sont supposés corrects (dans les bonnes intervalles, [1-12] pour
                 les mois et [1-31] pour les jours du mois).

Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#ifndef LABO3_DATE_H
#define LABO3_DATE_H

extern const int JOURS_PAR_SEMAINE;
extern const int MOIS_PAR_ANNEE;
extern const int ANNEE_BORNE_INFERIEURE;
extern const int ANNEE_BORNE_SUPERIEURE;

/**
 * Détermine si une année est bissextile ou pas
 * @param annee
 * @return true si l'année est bissextile, false autrement
 */
bool estBissextile(int annee);

/**
 * Détermine le nombre de jours d'un mois d'une année
 * @param noMois : numéro du mois [1-12]
 * @param annee
 * @return nombre de jours d'un mois
 */
int nbJoursParMois(int noMois, int annee);

/**
 * Détermine le nombre de mois (bornes comprises) entre deux dates
 * @param moisDebut : mois de début, compris dans le résultat final
 * @param moisFin : mois de fin, compris dans le résultat final
 * @param anneeDebut : année de début
 * @param anneeFin : année de fin
 * @return le nombre de mois entre les deux dates
 */
int nbMoisEntreDeuxDates(int moisDebut, int moisFin, int anneeDebut, int anneeFin);

/**
 * Vérifie que le mois et l'année sont compris dans leur intervalle respectif.
 * Intervalle du mois: [1;12]
 * @param mois
 * @param annee
 * @return true si le mois et l'année sont compris dans leur intervalle respectif.
 */
bool dateDansIntervalle(int mois, int annee);

/**
 * Vérifie que la date de début est plus petite (et donc plus ancienne) que la
 * date de fin.
 * @param moisDebut
 * @param moisFin
 * @param anneeDebut
 * @param anneeFin
 * @return true si la date de début est plus petite que la date de fin.
 */
bool dateDebutAvantFin(int moisDebut, int moisFin, int anneeDebut, int anneeFin);

/**
 * On entre une date et la fonction détermine le numéro du jour de la semaine.
 * Le jour vaudra 0 si c'est un lundi, 1 si c'est un mardi, ..., et 6 pour dimanche.
 * @param jour
 * @param mois
 * @param annee
 * @return Le numéro du jour de la semaine
 */
int jourDeLaSemaine(int jour, int mois, int annee);

/**
 * Retourne le nom du mois en français selon son index
 * @param noMois : numéro du mois [1-12]
 * @return une chaîne de caractères contenant le nom du mois en français
 */
std::string nomDuMois(int noMois);

#endif // LABO3_DATE_H
