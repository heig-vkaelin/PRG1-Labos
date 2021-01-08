/*
-----------------------------------------------------------------------------------
Nom du fichier : Date.h
Auteur(s)      : Jonathan Friedli, Valentin Kaelin, Lazar Pavicevic
Date creation  : 05.01.2021

Description    : Classe permettant de modéliser des dates. Il est possible de
                 créer une date et de l'afficher selon différents formats. Il est
                 également possible d'incrémenter et de décrémenter les dates d'un
                 certain nombre de jours. Pour finir, la classe propose une
                 soustraction entre deux dates retournant le nombre de jours les
                 séparant.

Remarque(s)    : La classe Date est conçue pour le calendrier Grégorien. Ses
                 fonctionnalités sont garanties depuis le 15 octobre 1582 (1er
                 jour du calendrier Grégorien) jusqu'au 31 décembre 9999.
                 Les opérations d'addition et de soustraction étant erronées pour
                 des dates antérieures au début du calendrier Grégorien. Ceci est
                 dû au fait que les années bisextiles n'étaient pas encore
                 implémentées.
                 La validité des paramètres entrés pour les diverses méthodes
                 n'est pas vérifiée.

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

	/**
	 * Surcharge de l'opérateur - retournant le nombres de jours entre deux dates
	 * @param lhs : première date
	 * @param rhs : seconde date
	 * @return le nombre de jours séparant les deux dates
	 */
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

	/**
	 * Foncteur permettant d'afficher une date dans plusieurs formats possibles.
	 * Si le format n'est pas précisé ou inconnu, la date est formatée avec le
	 * format par défaut.
	 * @param format : Formats possibles:
	 * [jj.mm.aaaa (défaut), jj-mm-aaaa, aaaa.mm.jj, aaaa-mm-jj]
	 * @return la date sous forme de chaîne de caractères au format choisi
	 */
	std::string operator()(const std::string &format = "jj.mm.aaaa") const;

private:
	unsigned jour, mois, annee;
};

#endif // LABO5_DATE_H
