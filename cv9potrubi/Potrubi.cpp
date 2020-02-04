#include "Potrubi.h"
#include "HorizSpoj.h"
#include "Kolecko.h"
#include "TSpoj.h"
#include "VertSpoj.h"
#include "VsestrannySpoj.h"
#include "Fronta.h"
Potrubi::Potrubi(std::istream& is)
{
	is >> rozmer;

	prvky = new APotrubniPrvek* { rozmer * rozmer };
	for (int i = 0; i < rozmer * rozmer; i++) {
		prvky[i] = nullptr;
	}
	for (int i = 0; i < rozmer; i++) {
		for (int j = 0; j < rozmer; j++) {
			char znak = is.get();
			APotrubniPrvek* prvek = nullptr;
			switch (znak) {
			case ' ':
				break;
			case '-':
				prvek = new HorizSpoj(j, i);
			case 'I':
				prvek = new VertSpoj(j, i);
			case 'o':
				prvek = new Kolecko(j, i);
			case 'T':
				prvek = new TSpoj(j, i);
			case '+':
				prvek = new VsestrannySpoj(j, i);
			}
			prvky[i * rozmer + j] = prvek;
		}
		is.get();
	}

}
Potrubi::~Potrubi()
{
	for (int i = 0; i < rozmer*rozmer; i++) {
		if (prvky[i]) {
			delete prvky[i];
		}
		delete[] prvky;
	}
}
const APotrubniPrvek* Potrubi::DejPrvek(int x, int y) const
{
	if (x < 0 || y < 0 || x >= rozmer || y >= rozmer) {
		return nullptr;
	}
	return prvky[y * rozmer + x];
}

bool Potrubi::JePotrubiOk() const
{
	for (int i = 0; i < rozmer * rozmer; i++) {
		if (prvky[i]) {
			if (!prvky[i]->JeKorektneZapojen(this))
				return false;
		}
	}
	return true;
}
