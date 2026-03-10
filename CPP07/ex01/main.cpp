#include <iostream>
#include <string>

#include "iter.hpp"

void ft_print(const std::string &str)
{
	std::cout << str << std::endl;
}

void ft_printnumber(const int &n)
{
	std::cout << n << std::endl;
}

void ft_double(int &n)
{
	n *= 2;
}

void ft_addtostring(std::string &str)
{
	str += " emboar";
}

int main( void ) {
	std::string str[4] = {"Men", "I", "Love", "Tepig"};
	int numbers[5] = {1, 2, 3, 4, 5};

	::iter(str, 4, &ft_print);
	::iter(numbers, 5, &ft_printnumber);

	::iter(str, 4, &ft_addtostring);
	::iter(numbers , 5, &ft_double);

	::iter(str, 4, &ft_print);
	::iter(numbers, 5, &ft_printnumber);
}