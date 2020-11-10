/*
-----------------------------------------------------------------------------------
Nom du fichier	: affichage.h
Auteur(s)		: Valentin Kaelin, Jonathan Friedli, Lazar Pavicevic
Date creation	: 05.11.2020

Description		: <à compléter>

Remarque(s)		: <à compléter>

Compilateur		: Mingw-w64 g++ 8.1.0
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
void saisirDate(bool estDateDeDebut, unsigned int &mois, unsigned int &annee);

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
void afficherDemandesDeSaisie(unsigned &moisDebut, unsigned &moisFin,
										unsigned &anneeDebut, unsigned &anneeFin);

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
void afficherJourDuMois(unsigned jour, unsigned jourSemaine);

/**
 * Affiche le mois de l'année passé en paramètre dans la console
 * @param mois : mois à afficher [1-12]
 * @param annee : année du mois
 * @param jourDeLaSemaine: jour de la semaine du premier jour du mois [0-6]
 */
void afficherMois(unsigned mois, unsigned annee, unsigned &jourDeLaSemaine);

/**
 * Affiche un calendrier dans la console du mois de début au mois de fin. Les 2
 * mois sont compris dans l'intervalle.
 * @param moisDebut
 * @param moisFin
 * @param anneeDebut
 * @param anneeFin
 */
void afficherCalendrier(unsigned moisDebut, unsigned moisFin,
								unsigned anneeDebut, unsigned anneeFin);

#endif //LABO3_AFFICHAGE_H
