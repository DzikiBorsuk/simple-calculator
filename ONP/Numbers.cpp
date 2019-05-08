#include "Numbers.h"

Numbers::Numbers(std::string name):NumberBase(std::stod(name)){}
Numbers::Numbers(double v) : NumberBase(v) {}
Numbers::~Numbers(){}

double Numbers::return_value()
{
	return value;
}


Pi::Pi() :NumberBase(M_PI) {}
Pi::~Pi() {}

double Pi::return_value()
{
	return value;
}


Euler::Euler() :NumberBase(M_E) {}
Euler::~Euler() {}

double Euler::return_value()
{
	return value;
}
