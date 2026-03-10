#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::~ScavTrap(void)
{
    std::cout << "Destructor called for the ScavTrap " << Name << "." << std::endl;
}

ScavTrap::ScavTrap() {
    std::cout << "Scavtrap constructor called" << std::endl; 
    this->Name = "ScavTrap";
    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
    this->gate = 0;
}

ScavTrap::ScavTrap(std::string ClapName) : ClapTrap(ClapName){
    std::cout << "ScavTrap " << ClapName << " has been constructed." << std::endl; 

    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
    this->gate = 0;
}

void ScavTrap::attack(const std::string& target) {
    if (this->HitPoints <= 0 || this->EnergyPoints <= 0)
        return ;
    this->EnergyPoints -= 1;
    std::cout << "ScavTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl; 
}

void ScavTrap::takeDamage(unsigned int amount) {
    if (this->HitPoints < amount)
        this->HitPoints = 0;
    else
        this->HitPoints -= amount;

    std::cout << "ScavTrap received " << amount << " hit points of damage, its health is now at " << this->HitPoints << " hit points!" << std::endl; 
}

void ScavTrap::beRepaired(unsigned int amount) {
    if (this->HitPoints <= 0 || this->EnergyPoints <= 0)
        return ;
    this->HitPoints += amount;
    this->EnergyPoints -= 1;
    if (this->HitPoints > 100)
        this->HitPoints = 100;
    std::cout << "ScavTrap healed " << amount << ", its health is now at " << this->HitPoints << " hit points!" << std::endl; 
}

void ScavTrap::guardGate() {
    if (this->gate == 0)
    {
        this->gate = 1;
        std::cout << "ScavTrap activated his special ability, guardGate!!, he is now indeed guarding the gate." << std::endl; 
        return ;
    }
    else
        this->gate = 0;
    std::cout << "ScavTrap dactivated his special ability, guardGate, he is no longer guarding the gate." << std::endl; 
    
}

ScavTrap::ScavTrap(const ScavTrap &toCopy)
{
    std::cout << "Scavtrap copy constructor called" << std::endl; 
    *this = toCopy;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "Scavtrap copy assignment operator called" << std::endl;
    if (this == &other)
		return (*this);
    this->Name = other.Name;
    this->HitPoints = other.HitPoints;
    this->EnergyPoints = other.EnergyPoints;
    this->AttackDamage = other.AttackDamage;
    this->gate = other.gate;
    return (*this);
}
