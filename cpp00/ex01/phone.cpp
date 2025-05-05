#include <iostream>
#include <cctype>
#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	book;
	std::string	command;

	std::cout << std::endl;
	std::cout << " __________________________________________" << std::endl;
	std::cout << "| COMMANDS |   ADD    | SEARCH  |   EXIT   |" << std::endl;
	std::cout << "|__________|__________|_________|__________|" << std::endl;
	while (1)
	{
		std::cout << "|"<< std::endl;
		std::cout << "|-->";
		std::getline(std::cin, command);
		if (std::cin.eof())
		{
			std::cout << "EOF found, EOF not supported." << std::endl  << "|" << std::endl << std::endl;
			exit(1);
		}
		if (command == "ADD")
			book.addContact();
		else if (command == "SEARCH")
			book.search();
		else if (command == "EXIT")
			break;
	}
	std::cout << "|" << std::endl;
	std::cout << std::endl;
}