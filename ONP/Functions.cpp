#include "Functions.h"

Sin::Sin() :FunctionBase(1){}
double Sin::calculate(double arg[])
{
	return sin(arg[0]);
}

Cos::Cos() :FunctionBase( 1) {}
double Cos::calculate(double arg[])
{
	return cos(arg[0]);
}

Tan::Tan() :FunctionBase(1) {}
double Tan::calculate(double arg[])
{
	return tan(arg[0]);
}

Asin::Asin() :FunctionBase(1) {}
double Asin::calculate(double arg[])
{
	return asin(arg[0]);
}

Acos::Acos() :FunctionBase(1) {}
double Acos::calculate(double arg[])
{
	return acos(arg[0]);
}

Atan::Atan() :FunctionBase(1) {}
double Atan::calculate(double arg[])
{
	return atan(arg[0]);
}

Sinh::Sinh() :FunctionBase(1) {}
double Sinh::calculate(double arg[])
{
	return sinh(arg[0]);
}

Cosh::Cosh() :FunctionBase(1) {}
double Cosh::calculate(double arg[])
{
	return cosh(arg[0]);
}

Tanh::Tanh() :FunctionBase(1) {}
double Tanh::calculate(double arg[])
{
	return tanh(arg[0]);
}

Asinh::Asinh() :FunctionBase(1) {}
double Asinh::calculate(double arg[])
{
	return asinh(arg[0]);
}

Acosh::Acosh() :FunctionBase(1) {}
double Acosh::calculate(double arg[])
{
	return acosh(arg[0]);
}

Atanh::Atanh() :FunctionBase(1) {}
double Atanh::calculate(double arg[])
{
	return atanh(arg[0]);
}

Sqrt::Sqrt() :FunctionBase(1) {}
double Sqrt::calculate(double arg[])
{
	return sqrt(arg[0]);
}

Root::Root() :FunctionBase(2) {}
double Root::calculate(double arg[])
{
	return pow(arg[0], 1/arg[1]);
}

Log::Log() :FunctionBase(1) {}
double Log::calculate(double arg[])
{
	return log(arg[0]);
}

Log10::Log10() :FunctionBase(1) {}
double Log10::calculate(double arg[])
{
	return log10(arg[0]);
}

Log2::Log2() :FunctionBase(1) {}
double Log2::calculate(double arg[])
{
	return log2(arg[0]);
}