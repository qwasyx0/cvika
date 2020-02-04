#pragma once
#ifndef __Integer_h
#define __Integer_h

#include "IObject.h"
#include <string>

struct Integer : IObject {
public:
	Integer(int value);
	virtual string toString() const override; //virtual preda na prehlednosti override overi zda vse ok
private:
	int value;
};
#endif // Integer_h