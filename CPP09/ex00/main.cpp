#include <iostream>
#include <ctime>

#include "BitcoinExchange.hpp"

int main(int n, char **args)
{
	if (n != 2)
		return (1);

	std::string str = args[1];
    try
    {
	    BitcoinExchange db(str);

        db.getValues();
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }

	return (0);
}