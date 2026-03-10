#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
        ScavTrap(std::string ClapName);
        ~ScavTrap(void);
        ScavTrap();
        ScavTrap(const ScavTrap &toCopy);
        ScavTrap& operator=(const ScavTrap& other);
    
        void attack(const std::string& target);

        void takeDamage(unsigned int amount);

        void beRepaired(unsigned int amount);

        void guardGate();

    private:
        int gate;
     
};

#endif