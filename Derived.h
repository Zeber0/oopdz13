#pragma once
#include "Base.h"
class Derived : public Base
{
public:
	int y;
	Derived(); 
	Derived(int in);
	Derived(const Derived& obj);
	Base* ret() override;
	Base* copyder();
	void gety();
	~Derived();
};