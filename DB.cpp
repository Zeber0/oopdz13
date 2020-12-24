#include "DB.h"

DB::DB()
{
}

void DB::add(Base* obj)
{
	db.insert(obj);
}

void DB::copy(const DB& d, bool sw)
{
	
	if (sw == 0) {
		std::set<Base*, predicate>::iterator i = d.db.begin(), ie = d.db.begin();
		advance(ie, d.db.size() / 2);
		for (; i != ie; ++i)
		{
			Base* t = *i;
			if(typeid(*t).name()== typeid(Base).name())
			db.insert(t->ret());
		}
	}
	else {
		std::set<Base*, predicate>::iterator i = d.db.begin(), ie = d.db.end();
		advance(i, d.db.size() / 2);
		for (; i != ie; ++i)
		{
			Base* t = *i;
			if (typeid(*t).name() == typeid(Derived).name())
			db.insert(t->ret());
		}
	}
}

void DB::print()
{
	//std::copy(db.begin(), db.end(), std::ostream_iterator<int>(std::cout, " ")); как мне с помощью копи доставать аргументы класса?
	for (std::set<Base*, predicate>::iterator i = db.begin(); i != db.end(); ++i) 
	{ 
		(*i)->getx();
		std::cout << " ";
		(*i)->gety();
		std::cout << std::endl;
	}
}

DB::~DB()
{
	for (std::set<Base*, predicate>::iterator i = db.begin(); i != db.end(); ++i)
		delete* i;
	db.clear();
}

bool predicate::operator()(Base* a, Base* b) const
{
	return *(a->x) < *(b->x);
}
