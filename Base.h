#pragma once
#include <set>
#include <iterator>
#include <iostream>
#include <clocale>
#include <ctime>
#include <typeinfo>
#include <map>
#include "DB.h"
class Base
{
public:
	int* x= new int;
	Base();
	Base(int in);
	Base(const Base& obj);
	void getx();
	virtual void gety();
	
	virtual void copybase(const DB& db);
	virtual void copyder(const DB& db);
	virtual Base* ret();
	virtual ~Base();
};