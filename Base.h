#pragma once
#include <iostream>
#include <ctime>
class DB;
class Base
{
public:
	int* x= new int;
	Base();
	Base(int in);
	Base(const Base& obj);
	void getx();
	virtual void gety();
	virtual void copybase(DB& db);
	virtual void copyder(DB& db);
	virtual Base* copy();
	virtual ~Base();
};