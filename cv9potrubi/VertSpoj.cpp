#include "VertSpoj.h"

VertSpoj::VertSpoj(int x, int y)
{
	this->_x = x;
	this->_y = y;
}

bool VertSpoj::JeKorektneZapojen(const IPotrubi* potrubi) const
{
	if (potrubi[_x , _y-1].DejPrvek != nullptr && potrubi[_x , _y+1].DejPrvek != nullptr) {
		return true;
	}
	else {
		return false;
	}
}
