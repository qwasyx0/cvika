#ifndef _ICOMPARABLE_H
#define _ICOMPARABLE_H

struct IComparable
{
public:
	virtual int compareTo(IComparable*)const = 0;
	virtual ~IComparable() {}
};

#endif // !_ICOMPARABLE_H
