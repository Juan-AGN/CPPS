#include <iostream>
#include <ctime>

#include "PmergeMe.hpp"

int main(int n, char **args)
{
	if (n < 2)
		return (1);

    try
    {
	    PmergeMe calculator(&args[1], n - 1);

        calculator.execInput();
    }
    catch (std::exception &error)
    {
        return (1);
    }

	return (0);
}