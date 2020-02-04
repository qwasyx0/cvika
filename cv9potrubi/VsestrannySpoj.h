#pragma once
#ifndef VSESTRANNYSPOJ_H
#define VSESTRANNYSPOJ_H
#include "APotrubniPrvek.h"
struct VsestrannySpoj : APotrubniPrvek {
	VsestrannySpoj(int x, int y);
	virtual bool JeKorektneZapojen(const IPotrubi* potrubi) const override;
};
#endif // !VSESTRANNYSPOJ_H