#ifndef _OBJECT_H
#define _OBJECT_H

#include <string>

struct Object
{
public:
	virtual std::string toString()const = 0;
	virtual ~Object() {}
};

#endif // !_OBJECT_H
