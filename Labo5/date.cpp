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

unsigned Date::getJour() const {
	return jour;
}

unsigned Date::getMois() const {
	return mois;
}

unsigned Date::getAnnee() const {
	return annee;
}

bool operator<(const Date &lhs, const Date &rhs) {
	return false; // Utiliser fonction "nombre de jours entre 2 dates"
}

bool operator>(const Date &lhs, const Date &rhs) { return rhs < lhs; }

bool operator<=(const Date &lhs, const Date &rhs) { return !(lhs > rhs); }

bool operator>=(const Date &lhs, const Date &rhs) { return !(lhs < rhs); }

bool operator==(const Date &lhs, const Date &rhs) {
	return false;  // Utiliser fonction "nombre de jours entre 2 dates" == 0
}

bool operator!=(const Date &lhs, const Date &rhs) { return !(lhs == rhs); }

long long nombreJoursDepuisDebutCalendrierGregorien(const Date &date) {
	// 1er jour calendrier Grégorien: 15.10.1582
	long long joursDate = 0;
	const unsigned JOURS_RESTANTS_1582 = 17 + 30 + 31;

	// Jours depuis le 15 octobre jusqu'à la date
	if (date.getAnnee() == 1582) {
		joursDate = -14 + (int) date.getJour();
		for (unsigned i = 10; i < date.getMois(); ++i) {
			joursDate += nbJoursParMois(i, date.getAnnee());
		}
		return joursDate;
	}

	joursDate = JOURS_RESTANTS_1582 + date.getJour();
	for (unsigned i = 1583; i < date.getAnnee(); ++i) {
		joursDate += estBissextile(i) ? 366 : 365;
	}

	for (unsigned i = 1; i < date.getMois(); ++i) {
		joursDate += nbJoursParMois(i, date.getAnnee());
	}

	return joursDate;
}

long long nombreJoursEntreDeuxDates(const Date &date1, const Date &date2) {
	long long joursDate1 = nombreJoursDepuisDebutCalendrierGregorien(date1);
	long long joursDate2 = nombreJoursDepuisDebutCalendrierGregorien(date2);
	return joursDate1 - joursDate2;
}


