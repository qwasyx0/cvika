#include <iostream>
#include "IObject.h"
#include "Double.h"
#include "Integer.h"
#include "Cas.h"
#include "stdafx.h"
using namespace std;

void SeraditPole(IComparable** pole, int velikostPole)
{
	for (size_t i = 1; i < velikostPole; i++)
	{
		for (size_t j = 0; j < i; j++) {
			if (pole[j]->compareTo(pole[i]) == 1) {
				IComparable* pom = pole[j];
				pole[j] = pole[i];
				pole[i] = pom;
			}
		}
	}
}

struct Container {
	Container(IComparable** arry, int size) : arry(arry), size(size) { }

	IComparable& search(IComparable* needle) /*noexcept*/{
		for (int i = 0; i < size; i++) {
			if (arry[i]->compareTo(needle) == 0) {
				return *arry[i];
			}
		}
		throw std::exception{ "Not found" };
		//throw new std:exception{ "Item not found 2" };
	}


};

int main()
{
	IComparable** pole = new IComparable * [10];
	pole[0] = new Cas{ 16,25,30 };
	pole[1] = new Cas{ 0,30,0 };
	pole[2] = new Cas{ 0,2,3 };
	pole[3] = new Cas{ 20,25,50 };
	pole[4] = new Cas{ 6,5,3 };
	pole[5] = new Cas{ 22,18,50 };
	pole[6] = new Cas{ 5,31,58 };
	pole[7] = new Cas{ 12,28,10 };
	pole[8] = new Cas{ 18,2,3 };
	pole[9] = new Cas{ 8,50,50 };

	Container cnt{ pole, 10 }; 
	try {
		IComparable& found = cnt.search(new Cas(19,2,3));
	}
	catch (exception ex) { //kdyz bylo new tak *ex, ale nepouzivat
		cerr <<ex->what() << endl;
		//delete ex; //kdyz se pouzilo new
	}
//spravnejsi nez dole, vykona se prvni (logic se hleda prvni)
catch (const logic_error& ex) {
cerr << ex.what() << endl;
}
//nebo nasledujici vyjimky
	catch (const exception& ex)
{	cerr << ex.what() << endl;
}
//obecna vyjimka
catch(...) {
cerr << "Neco se nepovedlo" << endl;
}
	
	/*for (size_t i = 0; i < 10; i++)
	{
		cout << pole[i]->toString() << endl;
	}

		SeraditPole(pole, 10);

	cout << "Serazene pole:\n" << endl;

	for (size_t i = 0; i < 10; i++)
	{
		cout << pole[i]->toString() << endl;
	}

	for (size_t i = 0; i < 5; i++) {
		delete pole[i];
	}
	delete[] pole; */
	return 0;
}
