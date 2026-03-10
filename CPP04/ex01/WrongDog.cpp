#include "WrongDog.hpp"

WrongDog::~WrongDog(void)
{
    std::cout << "WrongDog destructor called" << std::endl; 
}

WrongDog::WrongDog() : WrongAnimal("WrongDog") {
    std::cout << "WrongDog constructor called" << std::endl; 
}

WrongDog::WrongDog(const WrongDog &tocopy) {
    std::cout << "WrongDog copy constructor called" << std::endl;
    this->type = tocopy.type; 
}

WrongDog& WrongDog::operator=(const WrongDog& src) {
    std::cout << "WrongDog assign operator called" << std::endl;
    if (this != &src)
        this->type = src.type;
    return (*this);
}

