#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iomanip>
# include <iostream>
# include <string>
# include <stdlib.h>
# include "Weapon.hpp"

class HumanB {
    public:
        HumanB(std::string name);

        void setWeapon(Weapon &theWeapon);

        void attack();

    private:
        std::string _name;
        Weapon *_toAttack;
        
};

#endif