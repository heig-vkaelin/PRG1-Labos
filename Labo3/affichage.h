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

#ifndef LABO3_AFFICHAGE_H
#define LABO3_AFFICHAGE_H

#include <string>

void saisirDate(bool estDateDeDebut, unsigned int &mois, unsigned int &annee);

bool dateDebutAvantFin(unsigned moisDebut, unsigned moisFin, unsigned anneeDebut,
							  unsigned anneeFin);

void afficherDemandesDeSaisie(unsigned &moisDebut, unsigned &moisFin,
										unsigned &anneeDebut, unsigned &anneeFin);

bool relancerProgramme();

void afficheJoursSemaine();

std::string nomDuMois(unsigned noMois);

void afficheMois(unsigned mois, unsigned annee, unsigned joursMois,
					  unsigned &jourDeLaSemaine);

#endif //LABO3_AFFICHAGE_H
