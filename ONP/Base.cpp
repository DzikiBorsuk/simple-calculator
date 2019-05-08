#include "Base.h"

MainElement::MainElement(std::string name) : name(name) {}
MainElement::~MainElement() {}
std::string MainElement::return_name()
{
	return name;
}


OperatorBase::OperatorBase(bool a, int p) : MainElement("operator"), associative(a), priority(p) {}
OperatorBase::~OperatorBase() {}
std::string OperatorBase::return_name()
{
	return name;
}
bool OperatorBase::return_associative()
{
	return associative;
}
int OperatorBase::return_priority()
{
	return priority;
}

FunctionBase::FunctionBase(int n) : MainElement("function"), number_of_arg(n) {}
FunctionBase::~FunctionBase() {}
std::string FunctionBase::return_name()
{
	return name;
}
int FunctionBase::return_n_of_arg()
{
	return number_of_arg;
}


NumberBase::NumberBase(double v) : MainElement("number"), value(v) {}
NumberBase::~NumberBase() {}
std::string NumberBase::return_name()
{
	return name;
}



