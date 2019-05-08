#pragma once
#include "Base.h"

class LeftBracket : public MainElement
{
public:
	LeftBracket() :MainElement("(") {}
	std::string return_name() override
	{
		return name;
	}
};

class RightBracket : public MainElement
{
public:
	RightBracket() :MainElement(")") {}
	std::string return_name() override
	{
		return name;
	}
};