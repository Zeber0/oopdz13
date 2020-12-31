#include "Derived.h"

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

void Derived::copybase(const DB& db)
{
}



void Derived::copyder(const DB& db)
{
	db.add(new Derived(*this));
}

Base* Derived::ret()
{
	return copyder();
}

void Derived::gety()
{
	std::cout << y;
}



Derived::~Derived()
{
}
