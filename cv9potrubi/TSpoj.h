#pragma once
#ifndef TSPOJ_H
#define TSPOJ_H
#include "APotrubniPrvek.h"
struct TSpoj : APotrubniPrvek {
	TSpoj(int x, int y);
	virtual bool JeKorektneZapojen(const IPotrubi* potrubi) const override;
};
#endif // !TSPOJ_H