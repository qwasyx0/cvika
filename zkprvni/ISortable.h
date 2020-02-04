#ifndef _ISORTABLE_H
#define _ISORTABLE_H

#include "IComparable.h"

struct ISortable
{
public:
	virtual int size()const = 0;
	virtual IComparable* get(int index) = 0;
	virtual void set(int index, IComparable* prvek) = 0;
	virtual ~ISortable() {}
};

#endif // !_ISORTABLE_H
