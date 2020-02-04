#pragma once
#ifndef __IComaparable_h
#define __IComparable_h

#include "IObject.h"
#include <String.h>

struct IComparable : IObject {
public:
	virtual ~IComparable();
	virtual int compareTo(IComparable* obj) const = 0;
	//virtual string toString() const override;
private:
};
#endif // IComparable_h