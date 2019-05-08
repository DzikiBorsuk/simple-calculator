#pragma once

#include "Base.h"

class Addition : public OperatorBase
{
public:
	Addition();
	~Addition();

	double calculate(double left, double right) override;
};

class Substraction : public OperatorBase
{
public:
	Substraction();
	~Substraction();

	double calculate(double left, double right) override;
};

class Multiplication : public OperatorBase
{
public:
	Multiplication();
	~Multiplication();

	double calculate(double left, double right) override;
};

class Division : public OperatorBase
{
public:
	Division();
	~Division();

	double calculate(double left, double right) override;
};

class Power : public OperatorBase
{
public:
	Power();
	~Power();

	double calculate(double left, double right) override;
};

