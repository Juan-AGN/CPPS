#include <iostream>

#include "ScalarConverter.hpp"


int main(int n, char **args)
{
	if (n != 2)
		return (1);
	std::string str = args[1];
	ScalarConverter::convert(str);

	return (0);
}