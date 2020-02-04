#pragma once
#include <istream>
#include "APotrubniPrvek.h"
#include <istream>
struct Potrubi : IPotrubi {
	Potrubi(std::istream & is);
	~Potrubi();
	virtual const APotrubniPrvek* DejPrvek(int x, int y) const override;
	virtual bool JePotrubiOk() const override;
	int rozmer;
	APotrubniPrvek** prvky;
};