#include "Harl.hpp"

int	main()
{
	std::string	command;
	Harl		theHarl;

	std::cout << std::endl;
	std::cout << " _________________________________________________________________________ " << std::endl;
	std::cout << "|   EXIT   |on any other imput will call upon the corresponding Harl layer|" << std::endl;
	std::cout << "|__________|______________________________________________________________|" << std::endl << std::endl;
	while (1)
	{
		std::cout << std::endl;
		std::getline(std::cin, command);
		std::cout << std::endl;
		if (std::cin.eof())
		{
			std::cout << "EOF found, EOF not supported." << std::endl << std::endl;
			std::cout << std::endl;
			break ;
		}
		else if (command == "EXIT")
			break;
		else
			theHarl.complain(command);
	}
	std::cout << std::endl;
}