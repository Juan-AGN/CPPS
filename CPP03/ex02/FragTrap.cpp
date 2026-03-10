#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::~FragTrap(void)
{
    std::cout << "[ A COOL DUMPSTER ] is waiting for the FragTrap " << Name << "." << std::endl;
}

FragTrap::FragTrap() {
    std::cout << "Fragtrap constructor called" << std::endl; 
    Name = "FragTrap";
    this->HitPoints = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
}

FragTrap::FragTrap(std::string ClapName) : ClapTrap(ClapName){
    std::cout << "FragTrap " << ClapName << " has been constructed [ FROM THE REMAINS OF THE OTHERS ]." << std::endl; 

    this->HitPoints = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &toCopy)
{
    std::cout << "Fragtrap copy constructor called" << std::endl; 
    *this = toCopy;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "Fragtrap copy assignment operator called" << std::endl;
    if (this == &other)
		return (*this);
    this->Name = other.Name;
    this->HitPoints = other.HitPoints;
    this->EnergyPoints = other.EnergyPoints;
    this->AttackDamage = other.AttackDamage;

    return (*this);
}

void FragTrap::attack(const std::string& target) {
    if (this->HitPoints <= 0 || this->EnergyPoints <= 0)
        return ;
    this->EnergyPoints -= 1;
    std::cout << "FragTrap is [ HAPPY ], he " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl; 
}

void FragTrap::takeDamage(unsigned int amount) {
    if (this->HitPoints < amount)
        this->HitPoints = 0;
    else
        this->HitPoints -= amount;

    std::cout << "FragTrap received " << amount << " hit points of damage, [ AH!, IT BURNS ] in my soul, its health is now at " << this->HitPoints << " hit points!" << std::endl; 
}

void FragTrap::beRepaired(unsigned int amount) {
    if (this->HitPoints <= 0 || this->EnergyPoints <= 0)
        return ;
    this->EnergyPoints--;
    this->HitPoints += amount;
    if (this->HitPoints > 100)
        this->HitPoints = 100;
    std::cout << "FragTrap healed " << amount << ", its health is now at [ 9'99$ DELIBERY FREE OF CHARGE], and " << this->HitPoints << " hit points!" << std::endl; 
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap activated his special ability, [ A NICE HAPPY HANDSHAKE ]!!, please, don't dissapoint him." << std::endl; 
}
