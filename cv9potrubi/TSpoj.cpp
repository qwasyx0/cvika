#include "TSpoj.h"

TSpoj::TSpoj(int x, int y)
{
	this->_x = x;
	this->_y = y;
}

bool TSpoj::JeKorektneZapojen(const IPotrubi* potrubi) const
{
	if (potrubi[_x - 1, _y].DejPrvek != nullptr && potrubi[_x + 1, _y].DejPrvek != nullptr && potrubi[_x , _y-1].DejPrvek != nullptr) {
		return true;
	}
	else {
		return false;
	}
}
