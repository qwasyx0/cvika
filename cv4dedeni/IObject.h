#pragma once
#ifndef __IObject_h
#define __IObject_h

#include <string>

struct IObject {
public:
	virtual ~IObject(); //kdyz mame virtual metodu meli bysme mit i virtual destruktor
	virtual string toString() const = 0;
private:

};
#endif // IObject_h