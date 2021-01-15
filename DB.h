#pragma once
#include "Derived.h"
#include <set>
#include <iterator>
#include <map>
struct predicate
{
	bool operator()(Base* a, Base* b) const;
};
class DBMAP;
class DB
{
private:
	std::set <Base*, predicate> db;
public:
	DB();
	DB& operator =(const DB& a);
	DB(const DB&);
	void add(Base* obj);
	void copy(DB& db,		bool sw);
	void print();
	friend class DBMAP;
	~DB();
};
class DBMAP 
{
private:
	std::multimap<int*, Base*> map;
public:
	DBMAP();
	void copydb(const DB&d);
	~DBMAP();
};