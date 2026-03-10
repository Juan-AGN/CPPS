#include <iostream>
#include <ctime>

#include "RPN.hpp"

int main(int n, char **args)
{
	if (n != 2)
		return (1);

	std::string str = args[1];
    try
    {
	    RPN calculator(str);

        calculator.execInput();
    }
    catch (std::exception &error)
    {
        return (1);
    }

	return (0);
}