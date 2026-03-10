#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iomanip>
# include <iostream>
# include <string>
# include <stdlib.h>


class Weapon {
    public:
        Weapon(std::string description);

        const std::string &getType();

        void setType(std::string description);

    private:
        std::string _type;
};

#endif