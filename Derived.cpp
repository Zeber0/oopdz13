#include "DB.h"

Derived::Derived()
{
	y = 0;
}

Derived::Derived(int in)
{
	y = in;
}

Derived::Derived(const Derived& obj)
{
	y = obj.y;
	*x =  int(*obj.x);
}

void Derived::copybase(DB& db)
{
}


void Derived::copyder(DB& db)
{
	db.add(new Derived(*this));
}

Base* Derived::copy()
{
	return new Derived(*this);
}





void Derived::gety()
{
	std::cout << y;
}



Derived::~Derived()
{
}
