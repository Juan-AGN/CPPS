#include <iostream>

#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap a("ScrapTrap");

	a.attack("BurnTrap");
	a.takeDamage(5);
	a.beRepaired(5);
	a.takeDamage(5);
	a.takeDamage(2);
	a.takeDamage(999);
	a.beRepaired(5);
	
	return 0;
}