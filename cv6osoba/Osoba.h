#pragma once
#ifndef OSOBA_H
#define OSOBA_H
#include <string>
#include "Adresa.h"
#include "Datum.h"
struct Osoba {
private:
	std::string _jmeno;
	std::string _prijmeni;
	Adresa _trvaleBydliste;
	Datum _datumNarozeni;
public:
	Osoba();
	Osoba(std::string jmeno, std::string prijmeni, Adresa adresa, Datum datum);
	void setJmeno(std::string jmeno);
	void setPrijmeni(std::string prijmeni);
	void setAdresa(Adresa adresa);
	void setDatum(Datum datum);
	std::string getJmeno() const;
	std::string getPrijmeni() const;
	Adresa getAdresa() const;
	Datum getDatum() const;
	std::string toString() const;
	
};
std::ostream& operator<<(std::ostream& os, const Osoba& osoba);
std::istream& operator>>(std::istream& is, Osoba& osoba);
#endif // OSOBA_H