#include "HorizSpoj.h"

HorizSpoj::HorizSpoj(int x, int y)
{
	this->_x = x;
	this->_y = y;
}

bool HorizSpoj::JeKorektneZapojen(const IPotrubi* potrubi) const
{
	if (potrubi[_x - 1, _y].DejPrvek != nullptr && potrubi[_x + 1, _y].DejPrvek != nullptr) {
		return true;
	}
	else {
		return false;
	}
}

