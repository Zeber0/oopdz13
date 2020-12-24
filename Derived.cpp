#include "Derived.h"

Derived::Derived()
{
	y = 0;
}

Derived::Derived(int in)
{
	y = in;
	x = new int(rand() % 100);
}

Derived::Derived(const Derived& obj)
{
	y = obj.y;
	x = new int(*obj.x);
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
