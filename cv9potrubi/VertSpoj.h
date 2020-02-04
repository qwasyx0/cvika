#pragma once
#ifndef VERTSPOJ_H
#define VERTSPOJ_H
#include "APotrubniPrvek.h"
struct VertSpoj : APotrubniPrvek {
	VertSpoj(int x, int y);
	virtual bool JeKorektneZapojen(const IPotrubi* potrubi) const override;
};
#endif // !VERTSPOJ_H