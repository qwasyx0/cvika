#include "VsestrannySpoj.h"

VsestrannySpoj::VsestrannySpoj(int x, int y)
{
	this->_x = x;
	this->_y = y;
}

bool VsestrannySpoj::JeKorektneZapojen(const IPotrubi* potrubi) const
{
	if (potrubi[_x, _y - 1].DejPrvek != nullptr && potrubi[_x, _y + 1].DejPrvek != nullptr && potrubi[_x+1, _y].DejPrvek != nullptr && potrubi[_x-1, _y].DejPrvek != nullptr) {
		return true;
	}
	else {
		return false;
	}
}
