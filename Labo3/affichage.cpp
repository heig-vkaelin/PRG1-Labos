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

#include <cstdlib>
#include <iostream>

using namespace std;

void hello() {
	cout << "Hello World" << endl;
}

bool verifierDateDansIntervalle(unsigned mois, unsigned annee) {
	unsigned int MOIS_BORNE_INFERIEURE = 1;
	unsigned int MOIS_BORNE_SUPERIEURE = 12;
	unsigned int ANNEE_BORNE_INFERIEURE = 1900;
	unsigned int ANNEE_BORNE_SUPERIEURE = 2100;

	//Va donner true s'il y a une valeur fausse pour pouvoir continuer dans la boucle
	//while. C'est un peu contre-intuitif...
	return !(mois >= MOIS_BORNE_INFERIEURE && mois <= MOIS_BORNE_SUPERIEURE &&
				annee >= ANNEE_BORNE_INFERIEURE && annee <= ANNEE_BORNE_SUPERIEURE);
}

bool comparerDateDebutEtFin(unsigned &moisDebut, unsigned &moisFin, unsigned
&anneeDebut, unsigned &anneeFin) {
	if (anneeFin < anneeDebut || moisFin < moisDebut) {
		cout
			<< "Date de fin plus grande que de date de debut. Veuillez SVP recommencer."
			<< endl;
		return true;
	}
	return false;
}

void saisirDate(bool estDateDeDebut, unsigned &mois, unsigned &annee) {

	cout << "Entrez la date de" << (estDateDeDebut ? " debut" : " fin")
		  << " [mm aaaa] :";

	while (not(cin >> mois >> annee) || verifierDateDansIntervalle(mois, annee)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Date non valide. Veuillez SVP recommencer." << endl;
		cout << "Entrez la date de" << (estDateDeDebut ? " debut" : " fin")
			  << " [mm aaaa] :";
	}
}

void afficherDemandesDeSaisie(unsigned &moisDebut, unsigned &moisFin, unsigned
&anneeDebut, unsigned &anneeFin) {
	do {
		saisirDate(true, moisDebut, anneeDebut);
		saisirDate(false, moisFin, anneeFin);
	} while (comparerDateDebutEtFin(moisDebut, moisFin, anneeDebut, anneeFin));
}