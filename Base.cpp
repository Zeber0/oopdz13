#include "DB.h"

Base::Base()
{
	*x = int(1+rand() % 100);
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







void Base::copybase(DB& db)
{
	db.add(new Base(*this));
}

void Base::copyder(DB& db)
{
	
}

Base* Base::copy()
{
	return this;
}

Base::~Base()
{
	delete x;
}
