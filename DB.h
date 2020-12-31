#pragma once
#include "Derived.h"
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
	void add(Base* obj);
	void copy(const DB& db,		bool sw);
	void print();
	friend class DBMAP;
	/*
	это так-же не приносит результата
	friend class Base;
	friend class Derived;
	*/
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