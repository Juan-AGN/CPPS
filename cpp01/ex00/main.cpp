#include "Zombie.hpp"

Zombie *newZombie( std::string name );

void randomChump( std::string name );

void destroyZombie(Zombie *zombies[4], int nzombies) {
	for (int n = 0; n < nzombies; n ++)
		delete zombies[n];
};

void showZombie(Zombie *zombies[4], int nzombies) {
	for (int n = 0; n < nzombies; n ++)
		zombies[n]->announce();
};

std::string toStr(const int index) {
	if (index == 1)
		return ("1");
	else if (index == 2)
		return ("2");
	else if (index == 3)
		return ("3");
	else if (index == 4)
		return ("4");
	return ("destroyer of worlds and end of the stars");
};

int	main()
{
	std::string	command;
	Zombie		*zombies[4];
	int			nzombies = 0;

	std::cout << std::endl;
	std::cout << " ______________________________________________________________________________________________________ " << std::endl;
	std::cout << "| COMMANDS |  CREATE  | RANDOM  | ANNOUNCE |   EXIT   |on any other imput will create chum of that name|" << std::endl;
	std::cout << "|__________|__________|_________|__________|__________|________________________________________________|" << std::endl << std::endl;
	while (1)
	{
		std::cout << std::endl;
		std::getline(std::cin, command);
		std::cout << std::endl;
		if (std::cin.eof())
		{
			std::cout << "EOF found, EOF not supported." << std::endl << std::endl;
			destroyZombie(zombies, nzombies);
			std::cout << std::endl;
			exit(1);
		}
		if (command == "CREATE")
		{
			if (nzombies != 4)
			{
				zombies[nzombies] = newZombie(toStr(nzombies + 1));
				nzombies ++;
			}
		}
		else if (command == "RANDOM")
			randomChump("The Chump " + toStr(nzombies + 1));
		else if (command == "EXIT")
			break;
		else if (command == "ANNOUNCE")
			showZombie(zombies, nzombies);
		else
			randomChump(command);
	}
	destroyZombie(zombies, nzombies);
	std::cout << std::endl;
}