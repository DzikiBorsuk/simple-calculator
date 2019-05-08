#pragma once

#include <string>
class input_error
{
public:
	std::string error;
	input_error() : error("input_error") {}
};

class blank_input
{
public:
	std::string error;
	blank_input() :error("blank_input_error"){}
};