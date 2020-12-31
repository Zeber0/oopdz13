#include "Base.h"

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

Base* Base::ret()
{
	
}






void Base::copybase(const DB& db)
{
	db.add(new Base(*this));
}

void Base::copyder(const DB& db)
{
	
}

Base::~Base()
{
	delete x;
}
