#include "Weapon.hpp"

Weapon::Weapon(std::string description) {
    this->_type = description;
}

void Weapon::setType( std::string description ) {
    this->_type = description;
}

const std::string &Weapon::getType() {
    return (this->_type);
}