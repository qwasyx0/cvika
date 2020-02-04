#include "ArrayList.h"

ArrayList::ArrayList(): pocetPrvku(0), velikost(3), pole(new IComparable*[10])
{
}

ArrayList::~ArrayList()
{
	for (int i = 0; i < pocetPrvku; i++) {
		delete pole[i];
	}

	delete[] pole;
}

int ArrayList::size() const
{
	return pocetPrvku;
}

IComparable * ArrayList::get(int index)
{
	if (index > pocetPrvku || index < 0) {
		throw std::out_of_range("Jste mimo rozsah pole");
	}
	return pole[index];
}

void ArrayList::set(int index, IComparable * prvek)
{
	if (index > pocetPrvku || index < 0) {
		throw std::out_of_range("Jste mimo rozsah pole");
	}
	if (prvek == nullptr)
	{
		throw std::invalid_argument("nullptr neni prvek, takze ho nelze vložit");
	}
	pole[index] = prvek;
}

void ArrayList::add(IComparable * prvek)
{
	if (prvek == nullptr)
	{
		throw std::invalid_argument("nullptr neni prvek, takze ho nelze vložit");
	}
	if (pocetPrvku >= velikost)
	{	
		IComparable** nove = new IComparable*[velikost*2];
		for (int i = 0; i < velikost; i++)
		{
			nove[i] = pole[i];
		}
		delete[]pole;
		pole = nove;
		velikost = velikost * 2;
	}

	pole[pocetPrvku++] = prvek;
}

void ArrayList::remove(IComparable * prvek)
{
	if (prvek == nullptr)
	{
		throw std::invalid_argument("Nelze mazat nullptr");
	}
	int index = -1;
	for (int i = 0; i < pocetPrvku; i++)
	{
		if (pole[i] == prvek)
		{
			index = i;
			break;
		}
	}
	if (index == -1)
	{
		throw std::invalid_argument("Tento prvek se v ArrayListu nevyskytuje");
	}

	delete pole[index];
	for (int i = index; i < pocetPrvku -2; i++)
	{
		pole[i] = pole[i + 1];
	}
	pole[pocetPrvku - 1] = nullptr;
	pocetPrvku--;

}
