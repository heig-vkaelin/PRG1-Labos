/*
-----------------------------------------------------------------------------------
Nom du fichier : Date.cpp
Auteur(s)      : Jonathan Friedli, Valentin Kaelin, Lazar Pavicevic
Date creation  : 05.01.2021

Description    : Fichier contenant l'implémentation de la classe Date ainsi que
                 quelques fonctions utilitaires.

Remarque(s)    : Pour calculer le nombre de jours entre deux dates, nous calculons
                 le nombre de jours depuis le début du calendrier Grégorien (15
                 octobre 1582) et nous soustrayons les deux résultats obtenus.
                 Cet algorithme a des effets de bord si nous utilisons des dates
                 supérieures à 5'800'000 années.

Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include "Date.h"

using namespace std;

/**
 * Détermine si une année est bissextile ou pas
 * @param annee
 * @return true si l'année est bissextile, false autrement
 */
bool estBissextile(unsigned annee) {
	return annee % 400 == 0 || (annee % 4 == 0 && annee % 100 != 0);
}

/**
 * Détermine le nombre de jours d'un mois d'une année
 * @param noMois : numéro du mois [1-12]
 * @param annee
 * @return nombre de jours d'un mois
 */
unsigned nbJoursParMois(unsigned noMois, unsigned annee) {
	switch ((Mois) noMois) {
		case Mois::FEVRIER:
			return estBissextile(annee) ? 29 : 28;
		case Mois::AVRIL:
		case Mois::JUIN:
		case Mois::SEPTEMBRE:
		case Mois::NOVEMBRE:
			return 30;
		default:
			return 31;
	}
}

/**
 * Calcule le nombre de jours séparant la date entrée en paramètre du début du
 * calendrier Grégorien.
 * @param date
 * @return le nombre de jours
 */
int nbJoursDepuisDebutCalendrierGregorien(const Date &date) {
	int nbJours;
	// 1er jour du calendrier Grégorien
	const Date PREMIER_JOUR = Date(15, 10, 1582);
	// Addition des jours du 15 octobre au 31 décembre
	const unsigned JOURS_RESTANTS_PREMIERE_ANNEE = 17 + 30 + 31;

	// Nombre de jours depuis le 15 octobre jusqu'à la date choisie (si en 1582)
	if (date.getAnnee() == PREMIER_JOUR.getAnnee()) {
		nbJours = (int) date.getJour() - (int) PREMIER_JOUR.getJour() + 1;
		for (unsigned i = PREMIER_JOUR.getMois(); i < date.getMois(); ++i) {
			nbJours += (int) nbJoursParMois(i, date.getAnnee());
		}
		return nbJours;
	}

	// Autrement, addition du nombre de jours de chaque année puis de chaque mois
	// de la dernière année
	nbJours = (int) (JOURS_RESTANTS_PREMIERE_ANNEE + date.getJour());
	for (unsigned i = PREMIER_JOUR.getAnnee() + 1; i < date.getAnnee(); ++i) {
		nbJours += estBissextile(i) ? 366 : 365;
	}

	for (unsigned i = 1; i < date.getMois(); ++i) {
		nbJours += (int) nbJoursParMois(i, date.getAnnee());
	}

	return nbJours;
}

bool operator<(const Date &lhs, const Date &rhs) {
	if (lhs.annee != rhs.annee)
		return lhs.annee < rhs.annee;
	if (lhs.mois != rhs.mois)
		return lhs.mois < rhs.mois;
	return lhs.jour < rhs.jour;
}

bool operator>(const Date &lhs, const Date &rhs) {
	return rhs < lhs;
}

bool operator<=(const Date &lhs, const Date &rhs) {
	return !(lhs > rhs);
}

bool operator>=(const Date &lhs, const Date &rhs) {
	return !(lhs < rhs);
}

bool operator==(const Date &lhs, const Date &rhs) {
	return lhs.annee == rhs.annee && lhs.mois == rhs.mois && lhs.jour == rhs.jour;
}

bool operator!=(const Date &lhs, const Date &rhs) {
	return !(lhs == rhs);
}

Date operator+(Date lhs, unsigned int nbJours) {
	return lhs += nbJours;
}

Date operator-(Date lhs, unsigned int nbJours) {
	return lhs -= nbJours;
}

int operator-(const Date &lhs, const Date &rhs) {
	int nbJoursDate1 = nbJoursDepuisDebutCalendrierGregorien(lhs);
	int nbJoursDate2 = nbJoursDepuisDebutCalendrierGregorien(rhs);
	return nbJoursDate1 - nbJoursDate2;
}

ostream &operator<<(ostream &lhs, const Date &rhs) {
	return lhs << rhs();
}

Date::Date(unsigned jour, unsigned mois, unsigned annee)
	: jour(jour), mois(mois), annee(annee) {}

unsigned Date::getJour() const {
	return jour;
}

unsigned Date::getMois() const {
	return mois;
}

unsigned Date::getAnnee() const {
	return annee;
}

Date &Date::operator++() {
	return *this += 1;
}

Date Date::operator++(int) {
	Date temp = *this;
	++*this;
	return temp;
}

Date &Date::operator+=(unsigned int nbJours) {
	jour += nbJours;
	while (jour > nbJoursParMois(mois, annee)) {
		jour -= nbJoursParMois(mois, annee);
		if (++mois > 12) {
			mois = 1;
			++annee;
		}
	}
	return *this;
}

Date &Date::operator--() {
	return *this -= 1;
}

Date Date::operator--(int) {
	Date temp = *this;
	--*this;
	return temp;
}

Date &Date::operator-=(unsigned nbJours) {
	int joursSoustraits = (int) jour - (int) nbJours;
	while (joursSoustraits < 1) {
		joursSoustraits += (int) nbJoursParMois(--mois, annee);
		if (mois < 1) {
			mois = 12;
			--annee;
		}
	}
	jour = (unsigned) joursSoustraits;
	return *this;
}

string Date::operator()(const std::string &format) const {
	string strJour = (jour < 10 ? "0" : "") + to_string(jour);
	string strMois = (mois < 10 ? "0" : "") + to_string(mois);
	string strAnnee = to_string(annee);

	if (format == "jj-mm-aaaa") {
		return strJour + "-" + strMois + "-" + strAnnee;
	} else if (format == "aaaa.mm.jj") {
		return strAnnee + "." + strMois + "." + strJour;
	} else if (format == "aaaa-mm-jj") {
		return strAnnee + "-" + strMois + "-" + strJour;
	}

	// Format par défaut: jj.mm.aaaa
	return strJour + "." + strMois + "." + strAnnee;
}
