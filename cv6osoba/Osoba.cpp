#include "Osoba.h"
#include <istream>
using namespace std;
Osoba::Osoba()
{
}

Osoba::Osoba(std::string jmeno, std::string prijmeni, Adresa adresa, Datum datum)
{
	this->_jmeno = jmeno;
	this->_prijmeni = prijmeni;
	this->_trvaleBydliste = adresa;
	this->_datumNarozeni = datum;
}

void Osoba::setJmeno(std::string jmeno)
{
	_jmeno = jmeno;
}

void Osoba::setPrijmeni(std::string prijmeni)
{
	_prijmeni = prijmeni;
}

void Osoba::setAdresa(Adresa adresa)
{
	_trvaleBydliste = adresa;
}

void Osoba::setDatum(Datum datum)
{
	_datumNarozeni = datum;
}

std::string Osoba::getJmeno() const
{
	return _jmeno;
}

std::string Osoba::getPrijmeni() const
{
	return _prijmeni;
}

Adresa Osoba::getAdresa() const
{
	return _trvaleBydliste;
}

Datum Osoba::getDatum() const
{
	return _datumNarozeni;
}


std::string Osoba::toString() const
{
	return  _jmeno + " " + _prijmeni + " " + _trvaleBydliste.toString() + " " + _datumNarozeni.toString();
}

std::ostream& operator<<(std::ostream& os, const Osoba& osoba) { 
	os << osoba.getJmeno() << " " << osoba.getPrijmeni() << " " << osoba.getAdresa() << " " << osoba.getDatum();

	return os;
}

std::istream& operator>>(std::istream& is, Osoba& osoba) {
	std::string pomocna{};
	int pom;
	Adresa adr{};
	Datum dat{};

	is >> pomocna;
	osoba.setJmeno(pomocna);

	is >> pomocna;
	osoba.setPrijmeni(pomocna);

	is >> pomocna;
	adr.setUlice(pomocna);

	is >> pomocna;
	adr.setMesto(pomocna);

	is >> pom;
	adr.setPsc(pom);
	osoba.setAdresa(adr);

	is >> pom;
	dat.setDen(pom);

	is >> pom;
	dat.setMesic(pom);

	is >> pom;
	dat.setRok(pom);
	osoba.setDatum(dat);

	return is;
}