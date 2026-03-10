#include <iostream>

#include "ClapTrap.hpp"

#include "ScavTrap.hpp"

#include "FragTrap.hpp"

int main( void ) {
	ClapTrap a("ScrapTrap");
	ScavTrap b("SlackTrap");
	FragTrap c("SpamTrap");

	a.attack("BurnTrap");
	a.takeDamage(5);
	a.beRepaired(5);
	a.takeDamage(5);
	a.takeDamage(2);
	a.takeDamage(999);
	a.beRepaired(5);
	b.guardGate();
	b.attack("SleepTrap");
	b.takeDamage(5);
	b.beRepaired(5);
	b.takeDamage(5);
	b.takeDamage(2);
	b.guardGate();
	b.takeDamage(999);
	b.beRepaired(5);
	c.attack("TvTrap");
	c.takeDamage(5);
	c.beRepaired(5);
	c.takeDamage(5);
	c.takeDamage(2);
	c.highFivesGuys();
	c.takeDamage(999);
	c.beRepaired(5);

	return 0;
}