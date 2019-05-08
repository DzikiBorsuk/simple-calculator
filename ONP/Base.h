#pragma once

#include <string>

class MainElement
{
protected:
	std::string name;

public:
	MainElement(std::string name);
	virtual ~MainElement();

	virtual std::string return_name() = 0;
	virtual bool return_associative() { return false; };
	virtual int return_priority() { return -1; };
	virtual double return_value() { return -1; };
	virtual double calculate(double left, double right) { return - 1; }
	virtual double calculate(double arg[]) { return -1; }
	virtual int return_n_of_arg() { return -1; }

};

class OperatorBase : public MainElement
{
protected:
	enum{left=false,right=true};
	bool associative;
	int priority;
	
public:
	OperatorBase(bool a, int p);
	virtual ~OperatorBase();

	std::string return_name() override;
	double calculate(double left, double right) override = 0;
	bool return_associative() override;
	int return_priority() override;

};

class FunctionBase : public MainElement
{
protected:
	int number_of_arg;

public:
	FunctionBase(int n);
	virtual ~FunctionBase();

	std::string return_name() override;
	int return_n_of_arg() override;
	double calculate(double arg[]) override = 0;

};

class NumberBase : public MainElement
{
protected:
	double value;
public:
	NumberBase(double v);
	//NumberBase(double v);
	virtual ~NumberBase();
	std::string return_name() override;
	double return_value() override = 0;
};

class Separator : public MainElement
{
public:
	Separator():MainElement("separator"){}
	~Separator() {}
};



