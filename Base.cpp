#include "Base.h"

Base::Base()
{
	*x = int(rand() % 100);
}

Base::Base(int in)
{
	*x = int(in);
}

Base::Base(const Base& obj)
{
	*x = int(*obj.x);
}

void Base::getx()
{
	std::cout << *x;
}

void Base::gety()
{
}





Base* Base::ret()
{
	return copybase();
}

Base* Base::copybase()
{
	return new Base(*this);
}

Base::~Base()
{
	delete x;
}
