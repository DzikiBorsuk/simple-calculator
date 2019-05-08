#pragma once
#define _USE_MATH_DEFINES
#include "Base.h"
#include <cmath>

class Sin : public FunctionBase
{
public:
	Sin();
	~Sin() {}

	double calculate(double arg[]) override;
};

class Cos : public FunctionBase
{
public:
	Cos();
	~Cos() {}

	double calculate(double arg[]) override;
};

class Tan : public FunctionBase
{
public:
	Tan();
	~Tan() {}

	double calculate(double arg[]) override;
};

class Asin : public FunctionBase
{
public:
	Asin();
	~Asin() {}

	double calculate(double arg[]) override;
};

class Acos : public FunctionBase
{
public:
	Acos();
	~Acos() {}

	double calculate(double arg[]) override;
};

class Atan : public FunctionBase
{
public:
	Atan();
	~Atan() {}

	double calculate(double arg[]) override;
};

class Sinh : public FunctionBase
{
public:
	Sinh();
	~Sinh() {}

	double calculate(double arg[]) override;
};

class Cosh : public FunctionBase
{
public:
	Cosh();
	~Cosh() {}

	double calculate(double arg[]) override;
};

class Tanh : public FunctionBase
{
public:
	Tanh();
	~Tanh() {}

	double calculate(double arg[]) override;
};

class Asinh : public FunctionBase
{
public:
	Asinh();
	~Asinh() {}

	double calculate(double arg[]) override;
};

class Acosh : public FunctionBase
{
public:
	Acosh();
	~Acosh() {}

	double calculate(double arg[]) override;
};

class Atanh : public FunctionBase
{
public:
	Atanh();
	~Atanh() {}

	double calculate(double arg[]) override;
};

class Sqrt : public FunctionBase
{
public:
	Sqrt();
	~Sqrt() {}

	double calculate(double arg[]) override;
};

class Root : public FunctionBase
{
public:
	Root();
	~Root() {}

	double calculate(double arg[]) override;
};

class Log : public FunctionBase
{
public:
	Log();
	~Log() {}

	double calculate(double arg[]) override;
};

class Log10 : public FunctionBase
{
public:
	Log10();
	~Log10() {}

	double calculate(double arg[]) override;
};

class Log2 : public FunctionBase
{
public:
	Log2();
	~Log2() {}

	double calculate(double arg[]) override;
};