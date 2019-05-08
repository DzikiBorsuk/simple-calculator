#pragma once

#include "Base.h"
#include "Numbers.h"
#include "Operators.h"
#include "Brackets.h"
#include "Functions.h"
#include <string>
#include <vector>
#include <memory>



class ONP
{
private:
	std::string equation;
	std::vector<std::shared_ptr<MainElement>> before_conv;
	std::vector<std::shared_ptr<MainElement>> after_conv;
	double last_result;

public:
	ONP();
	explicit ONP(std::string equation);
	~ONP();

	void new_equation(std::string eq);

	void split();

	void convert();

	double calculate();

	double calculator(std::string eq);

};