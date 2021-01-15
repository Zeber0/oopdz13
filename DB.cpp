#include "DB.h"

DB::DB()
{
}

DB::DB(const DB& a)
{
	if (this->db.size() != 0)
	{
		while (this->db.size() != 0)
			this->db.erase(this->db.begin());
	}
	std::set<Base*, predicate>::iterator i = a.db.begin(), ie = a.db.end();
	for (; i != ie; ++i)
	{
		this->add(*i);
	}
}

DB& DB::operator=(const DB& a)
{
	if (this == &a)
	{
		return *this;
	}
	if (this->db.size() != 0)
	{
		while (this->db.size() != 0)
			this->db.erase(this->db.begin());
	}
	std::set<Base*, predicate>::iterator i = a.db.begin(), ie = a.db.end();
	for (; i != ie; ++i)
	{
		this->add(*i);
	}
	return *this;
}



void DB::add(Base* obj)
{
	std::pair<std::set <Base*, predicate>::iterator, bool> a;
	Base* in = obj;
	a = db.insert(in);
	if (a.second == false) delete in;
}

void DB::copy(DB& d, bool sw)
{
	
	if (sw == 0) {
		std::set<Base*, predicate>::iterator i = d.db.begin(), ie = d.db.begin();
		advance(ie, d.db.size() / 2);
		for (; i != ie; ++i)
		{
			Base* t = *i;
			t->copybase(*this);
		}
	}
	else {
		std::set<Base*, predicate>::iterator i = d.db.begin(), ie = d.db.end();
		advance(i, d.db.size() / 2);
		for (; i != ie; ++i)
		{
			Base* t = *i;
			t->copyder(*this);
		}
	}
}



void DB::print()
{
	//std::copy(db.begin(), db.end(), std::ostream_iterator<int>(std::cout, " ")); можно ли с помощью копи доставать аргументы класса?
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
		map.insert(std::pair<int*, Base*>((*i)->x, (*i)->copy()));
	}
}


DBMAP::~DBMAP()
{
	for (std::multimap<int*, Base*>::iterator i = map.begin(); i != map.end(); ++i) {
		delete i->second;
	}
	map.clear();
}
