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

#include <string>
#include <iostream>

enum class Mois {
	JANVIER = 1, FEVRIER, MARS, AVRIL, MAI, JUIN, JUILLET, AOUT,
	SEPTEMBRE, OCTOBRE, NOVEMBRE, DECEMBRE
};

class Date {
	friend bool operator<(const Date &lhs, const Date &rhs);

	friend bool operator>(const Date &lhs, const Date &rhs);

	friend bool operator<=(const Date &lhs, const Date &rhs);

	friend bool operator>=(const Date &lhs, const Date &rhs);

	friend bool operator==(const Date &lhs, const Date &rhs);

	friend bool operator!=(const Date &lhs, const Date &rhs);

	friend Date operator+(Date lhs, unsigned nbJours);

	friend Date operator-(Date lhs, unsigned nbJours);

	friend int operator-(const Date &lhs, const Date &rhs);

	friend std::ostream &operator<<(std::ostream &lhs, const Date &rhs);

public:
	Date(unsigned jour, unsigned mois, unsigned annee);

	unsigned getJour() const;

	unsigned getMois() const;

	unsigned getAnnee() const;

	Date &operator++();

	Date operator++(int);

	Date &operator+=(unsigned nbJours);

	Date &operator--();

	Date operator--(int);

	Date &operator-=(unsigned nbJours);

	std::string operator()(const std::string &format = "") const;

	static int nombreJoursDepuisDebutCalendrierGregorien(const Date &date);

private:
	unsigned jour, mois, annee;

};

#endif // LABO5_DATE_H
