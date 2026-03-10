#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    public:
        FragTrap(std::string ClapName);
        ~FragTrap(void);
        FragTrap();
        FragTrap(const FragTrap &toCopy);
        FragTrap& operator=(const FragTrap& other);
    
        void attack(const std::string& target);

        void takeDamage(unsigned int amount);

        void beRepaired(unsigned int amount);

        void highFivesGuys(void);

    private:
     
};

#endif