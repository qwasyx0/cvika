#pragma once
#ifndef KOLECKO_H
#define KOLECKO_H
#include "APotrubniPrvek.h"
struct Kolecko : APotrubniPrvek{
	Kolecko(int x, int y);
	virtual bool JeKorektneZapojen(const IPotrubi* potrubi) const override;
};
#endif // !KOLECKO_H
