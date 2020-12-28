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

Base* Derived::ret()
{
	return copyder();
}

Base* Derived::copyder()
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
