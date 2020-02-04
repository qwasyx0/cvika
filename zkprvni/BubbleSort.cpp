#include "BubbleSort.h"
#include <stdexcept>

void BubbleSort::sort(ISortable * list)
{
	if (list == nullptr)
	{
		throw std::invalid_argument("nelze radit nullptr");
	}
	for (int i = 0; i < list->size() -1; i++)
	{
		for (int j = 0; j < list->size() -i - 1; j++)
		{
			if (list->get(j+1)->compareTo(list->get(j)) >0)
			{
				IComparable* tmp = list->get(j + 1);
				list->set(j + 1, list->get(j));
				list->set(j, tmp);
			}
		}
	}
}
