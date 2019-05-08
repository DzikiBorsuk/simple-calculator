#pragma once
#define _USE_MATH_DEFINES
#include "Base.h"
#include <cmath>


class Numbers : public NumberBase
{
public:
	Numbers(double v);
	Numbers(std::string name);
	~Numbers();

	double return_value() override;
};

class Pi : public NumberBase
{
public:
	Pi();
	~Pi();

	double return_value() override;
};

class Euler : public NumberBase
{
public:
	Euler();
	~Euler();

	double return_value() override;
};