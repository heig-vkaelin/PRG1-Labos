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

void saisirDate(bool estDateDeDebut, unsigned int &mois, unsigned int &annee);

void afficherDemandesDeSaisie(unsigned &moisDebut, unsigned &moisFin,
										unsigned &anneeDebut, unsigned &anneeFin);

bool relancerProgramme();

void afficherJourDuMois(unsigned jour, unsigned jourSemaine);

void afficherMois(unsigned mois, unsigned annee, unsigned &jourDeLaSemaine);

void afficherCalendrier(unsigned moisDebut, unsigned annee, unsigned nbMois);

#endif //LABO3_AFFICHAGE_H
