#include "Datum.h"
#include <istream>
using namespace std;
Datum::Datum()
{
}

Datum::Datum(int den, int mesic, int rok)
{
	this->_den = den;
	this->_mesic = mesic;
	this->_rok = rok;
}

void Datum::setDen(int den)
{
	_den = den;
}

void Datum::setMesic(int mesic)
{
	_mesic = mesic;
}

void Datum::setRok(int rok)
{
	_rok = rok;
}

int Datum::getDen() const
{
	return _den;
}

int Datum::getMesic() const
{
	return _mesic;
}

int Datum::getRok() const
{
	return _rok;
}
std::string Datum::toString() const
{
	return to_string(_den) + " " + to_string(_mesic) + " " + to_string(_rok);
}

std::ostream& operator<<(std::ostream& os, const Datum& datum)
{
	os << datum.getDen() << " " << datum.getMesic() << " " << datum.getRok();

	return os;
}

std::istream& operator>>(std::istream& is, Datum& datum)
{
	int pom;

	is >> pom;
	datum.setDen(pom);

	is >> pom;
	datum.setMesic(pom);

	is >> pom;
	datum.setRok(pom);

	return is;
}

