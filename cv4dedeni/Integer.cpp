#include "Integer.h"
using namespace std;

Integer::Integer(int value)
{
	this->value = value;
}
string Integer::toString() const
{
	return to_string(value);
}
