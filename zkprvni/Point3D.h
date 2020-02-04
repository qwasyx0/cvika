#ifndef _POINT3D_H
#define _POINT3D_H

#include "IComparable.h"
#include "Object.h"
#include <cmath>

struct Point3D : Object, IComparable
{
public:
	Point3D(double x, double y, double z);
	virtual std::string toString()const override;
	virtual int compareTo(IComparable* prvek)const override;
	double getX()const;
	double getY()const;
	double getZ()const;

private:
	double x;
	double y;
	double z;

};

#endif // !_POINT3D_H
