#pragma once
#ifndef HORIZSPOJ_H
#define HORIZSPOJ_H
#include "APotrubniPrvek.h"
struct HorizSpoj : APotrubniPrvek {
	HorizSpoj(int x, int y);
	virtual bool JeKorektneZapojen(const IPotrubi* potrubi) const override;
};
#endif // !HORIZSPOJ_H