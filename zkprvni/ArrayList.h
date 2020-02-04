#ifndef _ARRAYLIST_H
#define _ARRAYLIST_H

#include"ISortable.h"
#include <stdexcept>

struct ArrayList :ISortable
{
public:
	ArrayList();
	~ArrayList();

	virtual int size()const override;
	virtual IComparable* get(int index) override;
	virtual void set(int index, IComparable* prvek) override;
	void add(IComparable* prvek);
	void remove(IComparable* prvek);

private:
	int pocetPrvku;
	int velikost;
	IComparable** pole;

};

#endif // !_ARRAYLIST_H
