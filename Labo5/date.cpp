/*
-----------------------------------------------------------------------------------
Nom du fichier : date.cpp
Auteur(s)      : Jonathan Friedli, Valentin Kaelin, Lazar Pavicevic
Date creation  : 05.01.2021

Description    :

Remarque(s)    : La classe Date utilisable uniquement calendrier Grégorien

Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include "date.h"

using namespace std;

bool estBissextile(unsigned annee) {
	return annee % 400 == 0 || (annee % 4 == 0 && annee % 100 != 0);
}

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

Date::Date(unsigned jour, unsigned mois, unsigned annee)
	: jour(jour), mois(mois), annee(annee) {}

unsigned Date::getJour() const { return jour; }

unsigned Date::getMois() const { return mois; }

unsigned Date::getAnnee() const { return annee; }

bool operator<(const Date &lhs, const Date &rhs) {
	if (lhs.annee != rhs.annee)
		return lhs.annee < rhs.annee;
	if (lhs.mois != rhs.mois)
		return lhs.mois < rhs.mois;
	return lhs.jour < rhs.jour;
}

bool operator>(const Date &lhs, const Date &rhs) { return rhs < lhs; }

bool operator<=(const Date &lhs, const Date &rhs) { return !(lhs > rhs); }

bool operator>=(const Date &lhs, const Date &rhs) { return !(lhs < rhs); }

bool operator==(const Date &lhs, const Date &rhs) {
	return lhs.annee == rhs.annee && lhs.mois == rhs.mois && lhs.jour == rhs.jour;
}

bool operator!=(const Date &lhs, const Date &rhs) { return !(lhs == rhs); }

Date &Date::operator++() {
	*this += 1;
	return *this;
}

Date Date::operator++(int) {
	Date temp = *this;
	++*this;
	return temp;
}

Date operator+(Date lhs, unsigned int nbJours) {
	return lhs += nbJours;
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
	*this -= 1;
	return *this;
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

Date operator-(Date lhs, unsigned int nbJours) {
	return lhs -= nbJours;
}

int operator-(const Date &lhs, const Date &rhs) {
	int joursDate1 = Date::nombreJoursDepuisDebutCalendrierGregorien(lhs);
	int joursDate2 = Date::nombreJoursDepuisDebutCalendrierGregorien(rhs);
	return joursDate1 - joursDate2;
}

ostream &operator<<(ostream &lhs, const Date &rhs) {
	lhs << rhs();
	return lhs;
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

	// jj.mm.aaaa
	return strJour + "." + strMois + "." + strAnnee;
}

int Date::nombreJoursDepuisDebutCalendrierGregorien(const Date &date) {
	int nbJours;
	const Date PREMIER_JOUR = Date(15, 10, 1582); // 1er jour du calendrier Grégorien
	const unsigned JOURS_RESTANTS_PREMIERE_ANNEE = 17 + 30 + 31; // octobre->décembre

	// Jours depuis le 15 octobre jusqu'à la date (en 1582)
	if (date.getAnnee() == PREMIER_JOUR.getAnnee()) {
		nbJours = (int) date.getJour() - (int) PREMIER_JOUR.getJour() + 1;
		for (unsigned i = PREMIER_JOUR.getMois(); i < date.getMois(); ++i) {
			nbJours += (int) nbJoursParMois(i, date.getAnnee());
		}
		return nbJours;
	}

	nbJours = (int) (JOURS_RESTANTS_PREMIERE_ANNEE + date.getJour());
	for (unsigned i = PREMIER_JOUR.getAnnee() + 1; i < date.getAnnee(); ++i) {
		nbJours += estBissextile(i) ? 366 : 365;
	}

	for (unsigned i = 1; i < date.getMois(); ++i) {
		nbJours += (int) nbJoursParMois(i, date.getAnnee());
	}

	return nbJours;
}
