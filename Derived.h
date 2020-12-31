#pragma once
#include "Base.h"
class Derived : public Base
{
public:
	int y;
	Derived(); 
	Derived(int in);
	Derived(const Derived& obj);
	void copybase(const DB& db) override;
	void copyder(const DB& db) override;
	void gety();
	~Derived();
};