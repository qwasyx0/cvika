#include "Double.h"
using namespace std;

Double::Double(double value)
{
	this->value = value;
}

string Double::toString() const
{
	return to_string(value);
}
