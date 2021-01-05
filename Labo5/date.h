/*
-----------------------------------------------------------------------------------
Nom du fichier : date.h
Auteur(s)      : Jonathan Friedli, Valentin Kaelin, Lazar Pavicevic
Date creation  : 05.01.2021

Description    :

Remarque(s)    :

Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#ifndef LABO5_DATE_H
#define LABO5_DATE_H

enum class Mois {
	JANVIER = 1, FEVRIER, MARS, AVRIL, MAI, JUIN, JUILLET, AOUT,
	SEPTEMBRE, OCTOBRE, NOVEMBRE, DECEMBRE
};

class Date {
public:
	Date(unsigned jour, unsigned mois, unsigned annee);

	unsigned getJour() const;

	unsigned getMois() const;

	unsigned getAnnee() const;

	friend bool operator<(const Date &lhs, const Date &rhs);

	friend bool operator>(const Date &lhs, const Date &rhs);

	friend bool operator<=(const Date &lhs, const Date &rhs);

	friend bool operator>=(const Date &lhs, const Date &rhs);

	friend bool operator==(const Date &lhs, const Date &rhs);

	friend bool operator!=(const Date &lhs, const Date &rhs);

private:
	unsigned jour, mois, annee;
};

long long nombreJoursDepuisDebutCalendrierGregorien(const Date &date);

long long nombreJoursEntreDeuxDates(const Date &date1, const Date &date2);

#endif // LABO5_DATE_H
