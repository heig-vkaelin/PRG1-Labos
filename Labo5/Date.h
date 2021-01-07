/*
-----------------------------------------------------------------------------------
Nom du fichier : date.h
Auteur(s)      : Jonathan Friedli, Valentin Kaelin, Lazar Pavicevic
Date creation  : 05.01.2021

Description    :

Remarque(s)    : La classe Date est utilisable uniquement dans le calendrier
                 Grégorien. Celui-ci commence le 15 octobre 1582.
                 La validité des paramètres des diverses méthodes n'est pas vérifiée.

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

	std::string operator()(const std::string &format = "jj.mm.aaaa") const;

private:
	unsigned jour, mois, annee;
};

#endif // LABO5_DATE_H
