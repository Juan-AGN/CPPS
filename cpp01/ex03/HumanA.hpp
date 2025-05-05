#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iomanip>
# include <iostream>
# include <string>
# include <stdlib.h>
# include "Weapon.hpp"

class HumanA {
    public:
        HumanA(std::string name, Weapon &setWeapon);

        void attack();

    private:
        std::string _name;
        Weapon &_toAttack;
        
};

#endif