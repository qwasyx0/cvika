#pragma once
#ifndef __Double_h
#define __Double_h

#include "IObject.h"
#include <string>


struct Double : IObject {
public:
	Double(double value);
	virtual string toString() const override; //virtual preda na prehlednosti override overi zda vse ok
private:
	double value;
};
#endif // Double_h