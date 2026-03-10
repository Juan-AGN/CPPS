#include "ClapTrap.hpp"

ClapTrap::~ClapTrap(void)
{
    std::cout << "Destructor called" << std::endl; 
}

ClapTrap::ClapTrap(std::string ClapName) {
    std::cout << "Constructor parameter called" << std::endl; 
    Name = ClapName;
    HitPoints = 10;
    EnergyPoints = 10;
    AttackDamage = 0;
}

ClapTrap::ClapTrap() {
    std::cout << "Constructor called" << std::endl; 
    this->Name = "ClapTrap";
    this->HitPoints = 10;
    this->EnergyPoints = 10;
    this->AttackDamage = 0;
}

void ClapTrap::attack(const std::string& target) {
    if (this->HitPoints <= 0 || this->EnergyPoints <= 0)
        return ;
    this->EnergyPoints --;
    std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl; 
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->HitPoints < amount)
        this->HitPoints = 0;
    else
        this->HitPoints -= amount;

    std::cout << "ClapTrap " << this->Name << " received " << amount << " hit points of damage, its health is now at " << this->HitPoints << " hit points!" << std::endl; 
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->HitPoints <= 0 || this->EnergyPoints <= 0)
        return ;
    this->HitPoints += amount;
   if (this->HitPoints > 10)
        this->HitPoints = 10; 
    std::cout << "ClapTrap  " << this->Name << " healed " << amount << ", its health is now at " << this->HitPoints << " hit points!" << std::endl; 
}

ClapTrap::ClapTrap(const ClapTrap &toCopy)
{
    std::cout << "Copy constructor called" << std::endl; 
    *this = toCopy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &other)
		return (*this);
    this->Name = other.Name;
    this->HitPoints = other.HitPoints;
    this->EnergyPoints = other.EnergyPoints;
    this->AttackDamage = other.AttackDamage;
    return (*this);
}
