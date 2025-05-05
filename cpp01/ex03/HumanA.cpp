#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &setWeapon) : _name(name), _toAttack(setWeapon) {};

void HumanA::attack() {
    std::cout << this->_name << " attacks with his " << this->_toAttack.getType() << std::endl;
}
