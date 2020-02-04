#include "Point3D.h"
#include <stdexcept>
#include <typeinfo>

Point3D::Point3D(double x, double y, double z): x(x), y(y), z(z)
{
}


std::string Point3D::toString() const
{
	return "Point3D: x = " + std::to_string(x) + "; y = " + std::to_string(y) + "; z = " + std::to_string(z);
}

int Point3D::compareTo(IComparable * prvek) const
{
	Point3D* bod = dynamic_cast<Point3D*>(prvek);
	if (bod == nullptr)
	{
		throw std::bad_cast();
	}
	double vzdalenostThis = std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
	double vzdalenostBod = std::sqrt(bod->x * bod->x + bod->y * bod->y + bod->z * bod->z);
	return vzdalenostThis - vzdalenostBod;
}

double Point3D::getX() const
{
	return x;
}

double Point3D::getY() const
{
	return y;
}

double Point3D::getZ() const
{
	return z;
}
