#include <iostream>
#include "ONP.h"

int main()
{
	ONP onp;
	while (true)
	{
		std::string a;
		std::getline(std::cin, a);
		std::cout << std::endl << std::endl << a << " = " << onp.calculator(a) << std::endl << std::endl;
	}

	return 0;
}