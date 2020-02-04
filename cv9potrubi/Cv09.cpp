#include <iostream>
#include "Fronta.h"
#include "APotrubniPrvek.h"
#include "HorizSpoj.h"
#include "Potrubi.h"
#include "Kolecko.h"
#include "TSpoj.h"
#include "VertSpoj.h"
#include "VsestrannySpoj.h"
#include <string>
#include <iostream>
using namespace std;
int main()
{
	string vstup = string{ "5" };
	std::istringstream iss{ vstup };
	Potrubi potrubi{ iss };
	cout << (potrubi.JePotrubiOk() ? "FUNGUJE" : "ROZBITE") << endl;
	cin.get();
	return 0;
	//--------------------------------------------
	Fronta<APotrubniPrvek*> f;
	HorizSpoj* hs = new HorizSpoj(1, 2);
	f.Vloz(static_cast<APotrubniPrvek*>(hs));
	TSpoj* ts = new TSpoj(1, 1);
	f.Vloz(static_cast<APotrubniPrvek*>(ts));
	f.Obsahuje(static_cast<APotrubniPrvek*>(hs));
}
