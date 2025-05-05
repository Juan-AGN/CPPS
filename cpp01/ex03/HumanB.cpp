#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _toAttack(NULL) {};

void    HumanB::setWeapon(Weapon& theWeapon) 
{
    this->_toAttack = &theWeapon;
}

void HumanB::attack() {
    if (this->_toAttack != NULL)
        std::cout << this->_name << " attacks with his " << this->_toAttack->getType() << std::endl;
    else
        std::cout << this->_name << " attacks with his fists" << std::endl;
}
