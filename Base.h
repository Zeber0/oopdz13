#pragma once
#include <set>
#include <iterator>
#include <iostream>
#include <clocale>
#include <ctime>
#include <typeinfo>
class Base
{
public:
	int* x;
	Base();
	Base(int in);
	Base(const Base& obj);
	void getx();
	virtual void gety();
	virtual Base* ret();
	Base* copybase();
	virtual ~Base();
};