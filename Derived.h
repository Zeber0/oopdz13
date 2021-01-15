#pragma once
#include "Base.h"
class Derived : public Base
{
public:
	int y;
	Derived();
	Derived(int in);
	Derived(const Derived& obj);
	void copybase(DB& db) override;
	void copyder(DB& db) override;
	Base* copy() override;
	void gety();
	~Derived();
};