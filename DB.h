#pragma once
#include "Derived.h"
struct predicate
{
	bool operator()(Base* a, Base* b) const;
};

class DB
{
private:
	std::set <Base*, predicate> db;
public:
	DB();
	void add(Base* obj);
	void copy(const DB& db,		bool sw);
	void print();
	~DB();
};