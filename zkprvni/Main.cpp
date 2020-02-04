#include <iostream>
#include <string>

#include "BubbleSort.h"
#include "Point3D.h"
#include "ArrayList.h"

#define _CRTDBG_MAP_ALLOC
#include "stdlib.h"
#include "crtdbg.h"

using namespace std;

int main() {

	ArrayList* list = new ArrayList();
	IComparable* bod1 = new Point3D(1, 0, 8);
	IComparable* bod2 = new Point3D(1, 1, 0);
	IComparable* bod3 = new Point3D(1, 0, 5.4);
	IComparable* bod4 = new Point3D(5, 3, -7);
	IComparable* bod5 = new Point3D(2, 0, 2);
	list->add(bod1);
	list->add(bod2);
	list->add(bod3);
	list->add(bod4);
	list->add(bod5);


	for (int i = 0; i < list->size(); i++)
	{
		cout << ((Point3D*)list->get(i))->toString() << endl;;
	}

	BubbleSort::sort(list);
	cout << "serazeno: " << endl;
	for (int i = 0; i < list->size(); i++)
	{
		cout << ((Point3D*)list->get(i))->toString() << endl;
	}
	
	delete list;

	_CrtDumpMemoryLeaks();

	cin.get();
	return 0;
}