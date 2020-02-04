#pragma once
#ifndef DATUM_H
#define DATUM_H
#include <string>
struct  Datum {
private:
	int _den;
	int _mesic;
	int _rok;
public:
	Datum();
	Datum(int den, int mesic, int rok);
	void setDen(int den);
	void setMesic(int mesic);
	void setRok(int rok);
	int getDen() const;
	int getMesic() const;
	int getRok() const;
	std::string toString() const;
};
std::ostream& operator<<(std::ostream& os, const Datum& datum);
std::istream& operator>>(std::istream& is, Datum& datum);
#endif // DATUM_H