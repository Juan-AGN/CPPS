#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

void destroyZombie(Zombie *zombies) {
	delete [] zombies;
};

void showZombie(Zombie *zombies, int nzombies) {
	for (int n = 0; n < nzombies; n ++)
		zombies[n].announce();
};

int	main()
{
	std::string	command;
	Zombie		*zombies;
	int			nzombies = 0;

	std::cout << std::endl;
	std::cout << " __________________________________________________________________________________________________________ " << std::endl;
	std::cout << "| ANNOUNCE |   EXIT   |on any other imput will create a horde of that name with size incrementing each call|" << std::endl;
	std::cout << "|__________|__________|____________________________________________________________________________________|" << std::endl << std::endl;
	while (1)
	{
		std::cout << std::endl;
		std::getline(std::cin, command);
		std::cout << std::endl;
		if (std::cin.eof())
		{
			std::cout << "EOF found, EOF not supported." << std::endl << std::endl;
			if (nzombies != 0)
			{
				destroyZombie(zombies);
				std::cout << nzombies << " zombies deleted." << std::endl;
			}
			std::cout << std::endl;
			exit(1);
		}
		else if (command == "EXIT")
			break;
		else if (command == "ANNOUNCE")
			showZombie(zombies, nzombies);
		else
		{
			if (nzombies != 0)
			{
				destroyZombie(zombies);
				std::cout << nzombies << " zombies deleted." << std::endl;
			}
			nzombies ++;
			zombies = zombieHorde(nzombies, command);
		}
	}
	destroyZombie(zombies);
	std::cout << nzombies << " zombies deleted." << std::endl;
	std::cout << std::endl;
}