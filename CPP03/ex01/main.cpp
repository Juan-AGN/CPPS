#include <iostream>

#include "ClapTrap.hpp"

#include "ScavTrap.hpp"

int main( void ) {
	ClapTrap a("ScrapTrap");
	ScavTrap b("SlackTrap");

	a.attack("BurnTrap");
	a.takeDamage(5);
	a.beRepaired(5);
	a.takeDamage(5);
	a.takeDamage(2);
	a.takeDamage(999);
	a.beRepaired(5);
	b.attack("SleepTrap");
	b.takeDamage(5);
	b.beRepaired(5);
	b.takeDamage(5);
	b.takeDamage(2);
	b.guardGate();
	b.takeDamage(999);
	b.beRepaired(5);
	b.guardGate();
	
	return 0;
}