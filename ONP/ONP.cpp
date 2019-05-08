#include "ONP.h"
#include <memory>
#include <stack>
#include <string>
#include "Exception.h"
#include <iostream>

ONP::ONP() :equation(""), last_result(0) {}
ONP::ONP(std::string equation) :equation(equation),last_result(0){}
ONP::~ONP(){}

void ONP::new_equation(std::string eq)
{
	equation = eq;
}

void ONP::split()
{
	typedef std::shared_ptr<MainElement> elem_ptr;

	if (!before_conv.empty())
	{
		before_conv.clear();
	}
	if (equation == "")
	{
		throw blank_input();
		return;
	}
	std::string temp = "";
	for (int i = 0; equation[i] != 0; i++)
	{
		if (equation[i] > 47 && equation[i] < 58 || equation[i]=='.')
		{
			while (1)
			{
				if (equation[i] > 47 && equation[i] < 58 || equation[i] == '.')
				{
					temp += equation[i];
					i++;
				}
				else if (equation[i] == ' ')
				{
					i++;
					continue;
				}
				else
				{
					equation.erase(0, i);
					i = -1;
					before_conv.push_back(elem_ptr(new Numbers(temp)));
					temp = "";
					break;
				}
			}
			continue;
		}

		if (equation[i] > 96 && equation[i] < 123)
		{
			while (1)
			{
				if (equation[i] > 96 && equation[i] < 123)
				{
					temp += equation[i];
					i++;
				}
				else
				{
					if (temp == "pi")
					{
						before_conv.push_back(elem_ptr(new Pi()));
					}
					else if (temp == "e")
					{
						before_conv.push_back(elem_ptr(new Euler()));
					}
					else if(temp == "sin")
					{
						before_conv.push_back(elem_ptr(new Sin()));
					}
					else if (temp == "cos")
					{
						before_conv.push_back(elem_ptr(new Cos()));
					}
					else if (temp == "tan")
					{
						before_conv.push_back(elem_ptr(new Tan()));
					}
					else if (temp == "asin")
					{
						before_conv.push_back(elem_ptr(new Asin()));
					}
					else if (temp == "acos")
					{
						before_conv.push_back(elem_ptr(new Acos()));
					}
					else if (temp == "atan")
					{
						before_conv.push_back(elem_ptr(new Atan()));
					}
					else if (temp == "sinh")
					{
						before_conv.push_back(elem_ptr(new Sinh()));
					}
					else if (temp == "cosh")
					{
						before_conv.push_back(elem_ptr(new Cosh()));
					}
					else if (temp == "tanh")
					{
						before_conv.push_back(elem_ptr(new Tanh()));
					}
					else if (temp == "asinh")
					{
						before_conv.push_back(elem_ptr(new Asinh()));
					}
					else if (temp == "acosh")
					{
						before_conv.push_back(elem_ptr(new Acosh()));
					}
					else if (temp == "atanh")
					{
						before_conv.push_back(elem_ptr(new Atanh()));
					}
					else if (temp == "sqrt")
					{
						before_conv.push_back(elem_ptr(new Sqrt()));
					}
					else if (temp == "root")
					{
						before_conv.push_back(elem_ptr(new Root()));
					}
					else if (temp == "ln")
					{
						before_conv.push_back(elem_ptr(new Log()));
					}
					else if (temp == "log")
					{
						before_conv.push_back(elem_ptr(new Log10()));
					}
					else if (temp == "lb")
					{
						before_conv.push_back(elem_ptr(new Log2()));
					}
					else if (temp == "ans")
					{
						before_conv.push_back(elem_ptr(new Numbers(last_result)));
					}



					else
					{
						throw input_error();
						return;
					}



					equation.erase(0, i);
					i = -1;
					temp = "";
					break;
				}
				continue;
			}
		}

		if (equation[i] == ',' || equation[i]==' ')
		{
			continue;
		}


		if (equation[i] == '+')
		{
			before_conv.push_back(elem_ptr(new Addition()));
			i = -1;
			equation.erase(0, 1);
			continue;
		}

		if (equation[i] == '-')
		{
			if (before_conv.empty() || before_conv.back()->return_name() == "(")
			{
				temp += "-";
			}
			else
			{
				before_conv.push_back(elem_ptr(new Substraction()));
				i = -1;
				equation.erase(0, 1);
				continue;
			}
		}

		if (equation[i] == '*')
		{
			before_conv.push_back(elem_ptr(new Multiplication()));
			i = -1;
			equation.erase(0, 1);
			continue;
		}

		if (equation[i] == '/')
		{
			before_conv.push_back(elem_ptr(new Division()));
			i = -1;
			equation.erase(0, 1);
			continue;
		}

		if (equation[i] == '^')
		{
			before_conv.push_back(elem_ptr(new Power()));
			i = -1;
			equation.erase(0, 1);
			continue;
		}

		if (equation[i] == '(')
		{
			before_conv.push_back(elem_ptr(new LeftBracket()));
			i = -1;
			equation.erase(0, 1);
			continue;
		}

		if (equation[i] == ')')
		{
			before_conv.push_back(elem_ptr(new RightBracket()));
			i = -1;
			equation.erase(0, 1);
			continue;
		}
	}
}



void ONP::convert()
{
	typedef std::shared_ptr<MainElement> elem_ptr;
	std::stack<elem_ptr> elem;

	if (!after_conv.empty())
	{
		after_conv.clear();
	}
	for (unsigned int i = 0; i < before_conv.size(); i++)
	{
		if (before_conv[i]->return_name() == "number")
		{
			after_conv.push_back(before_conv[i]);
			continue;
		}

		if (before_conv[i]->return_name() == "operator")
		{
			while (1)
			{
				if (elem.empty() || elem.top()->return_name() == "(")
				{
					elem.push(before_conv[i]);
					break;
				}
				else if(elem.top()->return_name() == "function")
				{
					after_conv.push_back(elem.top());
					elem.pop();
				}
				else
				{
					if (before_conv[i]->return_associative())
					{
						if (before_conv[i]->return_priority() < elem.top()->return_priority())
						{
							after_conv.push_back(elem.top());
							elem.pop();
						}
						else
						{
							elem.push(before_conv[i]);
							break;
						}
					}
					else
					{
						if (before_conv[i]->return_priority() <= elem.top()->return_priority())
						{
							after_conv.push_back(elem.top());
							elem.pop();
						}
						else
						{
							elem.push(before_conv[i]);
							break;
						}

					}
				}
			}
			continue;
		}

		if (before_conv[i]->return_name() == "function")
		{
			elem.push(before_conv[i]);
			continue;
		}

		if (before_conv[i]->return_name() == "(")
		{
			elem.push(before_conv[i]);
			continue;
		}


		if (before_conv[i]->return_name() == ")")
		{
			if (elem.empty())
			{
				throw input_error();
			}
			while (elem.top()->return_name() != "(")
			{
				after_conv.push_back(elem.top());
				elem.pop();
				if (elem.empty())
				{
					throw input_error();
				}
			}
			elem.pop();
			continue;
		}
			throw input_error();

	}
	while (!elem.empty())
	{
		after_conv.push_back(elem.top());
		elem.pop();
	}
}


double ONP::calculate()
{
	typedef std::shared_ptr<MainElement> elem_ptr;
	std::stack<elem_ptr> elem;
	double result;
	for (unsigned int i = 0; i < after_conv.size(); i++)
	{
		if (after_conv[i]->return_name() == "number")
		{
			elem.push(after_conv[i]);
			continue;
		}
		if (after_conv[i]->return_name() == "operator")
		{
			if (elem.empty())
			{
				throw input_error();
			}
			double b = elem.top()->return_value();
			elem.pop();
			if (elem.empty())
			{
				throw input_error();
			}
			double a = elem.top()->return_value();
			elem.pop();
			result = after_conv[i]->calculate(a, b);
			elem.push(elem_ptr(new Numbers(result)));
		}
		if (after_conv[i]->return_name() == "function")
		{
			int number_of_arg = after_conv[i]->return_n_of_arg();
			double *arg = new double[number_of_arg];
			for (int i = number_of_arg - 1; i >= 0; i--)
			{
				if (elem.empty())
				{
					throw input_error();
				}
				else
				{
					arg[i] = elem.top()->return_value();
					elem.pop();
				}
			}
			result= after_conv[i]->calculate(arg);
			delete[] arg;
			elem.push(elem_ptr(new Numbers(result)));
		}
	}
	if (elem.empty())
	{
		throw input_error();
	}
	last_result= elem.top()->return_value();
	return last_result;
}

double ONP::calculator(std::string eq)
{
	new_equation(eq);
	try
	{
		split();
		convert();
		return calculate();
	}
	catch (blank_input &e)
	{
		std::cout << std::endl << "####" << std::endl << e.error << std::endl << "####" << std::endl;
	}
	catch (input_error &e)
	{
		std::cout << std::endl << "####" << std::endl << e.error << std::endl << "####" << std::endl;
	}
	catch(std::out_of_range &e)
	{
		std::cout << std::endl << "####" << std::endl << e.what() << std::endl << "####" << std::endl;
	}
	catch (...)
	{
		std::cout << std::endl << "####" << std::endl << "error" << std::endl << "####" << std::endl;
	}
}

