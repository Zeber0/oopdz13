#include "DB.h"

DB::DB()
{
}

void DB::add(Base* obj)
{
	std::pair<std::set <Base*, predicate>::iterator, bool> a;
	Base* in = obj;
	a = db.insert(in);
	if (a.second == false) delete in;
}

void DB::copy(const DB& d, bool sw)
{
	
	if (sw == 0) {
		std::set<Base*, predicate>::iterator i = d.db.begin(), ie = d.db.begin();
		advance(ie, d.db.size() / 2);
		for (; i != ie; ++i)
		{
			Base* t = *i;
			t->copybase(d);
		}
	}
	else {
		std::set<Base*, predicate>::iterator i = d.db.begin(), ie = d.db.end();
		advance(i, d.db.size() / 2);
		for (; i != ie; ++i)
		{
			Base* t = *i;
			db.insert(t->copyder());
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

DBMAP::DBMAP()
{
}

void DBMAP::copydb(const DB& d)
{
	for (std::set<Base*, predicate>::iterator i = d.db.begin(); i != d.db.end(); ++i)
	{
		Base* t = *i;
		map.insert(std::pair<int*, Base*>(t->ret()->x, t));
	}
}

DBMAP::~DBMAP()
{
}
