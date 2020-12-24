#include "Base.h"

Base::Base()
{ 
	x =new int(0);
}

Base::Base(int in)
{
	x = new int(in);
}

Base::Base(const Base& obj)
{
	x = new int(*obj.x);
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
