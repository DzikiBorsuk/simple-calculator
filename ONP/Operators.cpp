#include <cmath>
#include "Operators.h"

Addition::Addition():OperatorBase(left,1){}
Addition::~Addition() {}
double Addition::calculate(double left, double right)
{
	return left + right;
}

Substraction::Substraction() :OperatorBase(left, 1) {}
Substraction::~Substraction() {}
double Substraction::calculate(double left, double right)
{
	return left - right;
}

Multiplication::Multiplication() :OperatorBase(left, 2) {}
Multiplication::~Multiplication() {}
double Multiplication::calculate(double left, double right)
{
	return left * right;
}

Division::Division() :OperatorBase(left, 2) {}
Division::~Division() {}
double Division::calculate(double left, double right)
{
	return left / right;
}

Power::Power() :OperatorBase(right, 3) {}
Power::~Power() {}
double Power::calculate(double left, double right)
{
	return pow(left, right);
}
