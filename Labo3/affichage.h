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

void hello();

bool verifierDateDansIntervalle(unsigned mois, unsigned annee);

void saisirDate(bool estDateDeDebut, unsigned int &mois, unsigned int &annee);

bool comparerDateDebutEtFin(unsigned &moisDebut, unsigned &moisFin, unsigned
&anneeDebut, unsigned &anneeFin);

void afficherDemandesDeSaisie(unsigned &moisDebut, unsigned &moisFin, unsigned
&anneeDebut, unsigned &anneeFin);

#endif //LABO3_AFFICHAGE_H
