/*
-----------------------------------------------------------------------------------
Nom du fichier : affichage.h
Auteur(s)      : Jonathan Friedli, Valentin Kaelin, Lazar Pavicevic
Date creation  : 05.11.2020

Description    : Fichier d'en-tête contenant les prototypes des fonctions du
                 fichier affichage.cpp.

Remarque(s)    : Les paramètres de mois et jours de la semaine des différentes
                 fonctions d'affichage sont supposés corrects (dans les bonnes
                 intervalles, [1-12] pour les mois et [0-6] pour les jours de la
                 semaine).

Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#ifndef LABO3_AFFICHAGE_H
#define LABO3_AFFICHAGE_H

/**
 * Traite la saisie utilisateur d'une date sous le format "mm aaaa" et la stocke dans
 * les variables "mois" et "annee" passées par référence. Un message d'erreur
 * apparaît en cas de saisie incorrecte puis une nouvelle tentative sera
 * proposée à l'utilisateur.
 * @param estDateDeDebut : indication permettant d'afficher le message de saisie
 * adéquat.
 * @param mois : passé par référence
 * @param annee : passée par référence
 */
void saisirDate(bool estDateDeDebut, int &mois, int &annee);

/**
 * Affiche deux demandes de saisie de date (une de début et une de fin). Vérifie
 * que la date de début soit plus ancienne que la date de fin. Si ce n'est pas le
 * cas, un message d'erreur est affiché et l'utilisateur est invité à saisir les
 * dates depuis le début.
 * @param moisDebut : mois de début, passé par référence
 * @param moisFin : mois de fin, passé par référence
 * @param anneeDebut : année de début, passée par référence
 * @param anneeFin : année de fin, passée par référence
 */
void afficherDemandesDeSaisie(int &moisDebut, int &moisFin, int &anneeDebut,
										int &anneeFin);

/**
 * Demande à l'utilisateur s'il veut quitter le programme ou alors recommencer son
 * exécution
 * @return true si l'utilisateur veut quitter le programme, false s'il veut
 * recommencer
 */
bool quitterProgramme();

/**
 * Affiche le jour du mois passé en paramètre dans la console
 * @param jour : jour du mois [1-31]
 * @param jourSemaine : jour de la semaine [0-6]
 */
void afficherJourDuMois(int jour, int jourSemaine);

/**
 * Affiche le mois de l'année passé en paramètre dans la console
 * @param mois : mois à afficher [1-12]
 * @param annee : année du mois
 * @param jourSemaine: jour de la semaine du premier jour du mois [0-6]
 */
void afficherMois(int mois, int annee, int &jourSemaine);

/**
 * Affiche un calendrier dans la console du mois de début au mois de fin. Les 2
 * mois sont compris dans l'intervalle.
 * @param moisDebut
 * @param moisFin
 * @param anneeDebut
 * @param anneeFin
 */
void afficherCalendrier(int moisDebut, int moisFin, int anneeDebut, int anneeFin);

#endif // LABO3_AFFICHAGE_H
