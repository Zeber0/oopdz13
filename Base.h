#pragma once
#include <set>
#include <iterator>
#include <iostream>
#include <clocale>
#include <ctime>
#include <typeinfo>
#include <map>
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
	//мне нужно, чтобы классы знали что такое дб, если я сюла буду подключать дб, то будет двойное подключение, тк в заголовке дб уже подключен заголовок base
	virtual void copybase(const DB& db);
	virtual void copyder(const DB& db);
	virtual ~Base();
};