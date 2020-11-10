/*
-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Auteur(s)      : Jonathan Friedli, Valentin Kaelin, Lazar Pavicevic
Date creation  : 05.11.2020

Description    : Fichier principal du programme. L'utilisateur entre une date de
                 début et une date de fin. Le programme affiche ensuite dans la
                 console le calendrier de tous les mois compris entre ces deux dates.
					  Une fois le programme terminé, l'utilisateur doit pouvoir choisir
					  entre recommencer le programme ou le quitter.

Remarque(s)    : Utilisation de la compilation séparée pour améliorer la
                 lisibilité du code.
                 Si nous souhaitons changer les bornes de notre code, il reste
                 fonctionnel de novembre 1582 à mars de l'année 357'913'941.
                 Si la date est inférieure à 1582, l'algorithme permettant de
                 calculer le jour de la semaine n'est pas fonctionnel à cause du
                 changement du calendrier julien au grégorien. Pour la bonne
                 supérieure, il s'agit du moment à partir duquel les unsigned int
                 vont produiront un dépassement de capacité (overflow) lors de la
                 multiplication par le nombre de mois dans la méthode
                 "nbMoisEntreDeuxDates".

Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include "affichage.h"

int main() {
	do {
		unsigned moisDebut, moisFin, anneeDebut, anneeFin;
		afficherDemandesDeSaisie(moisDebut, moisFin, anneeDebut, anneeFin);

		afficherCalendrier(moisDebut, moisFin, anneeDebut, anneeFin);
	} while (!quitterProgramme());

	return EXIT_SUCCESS;
}
