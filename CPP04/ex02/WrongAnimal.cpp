#include "WrongAnimal.hpp"

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructor called" << std::endl; 
}

WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal constructor called" << std::endl; 
}

WrongAnimal::WrongAnimal(const WrongAnimal& src) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    this->type = src.type;
}

WrongAnimal::WrongAnimal(std::string totype) {
    std::cout << "WrongAnimal string constructor called" << std::endl;
    this->type = totype;
}

void WrongAnimal::makeSound() const {
    std::cout << "What am i?" << std::endl;
}

std::string WrongAnimal::getType() const {
    return (this->type);
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src) {
    std::cout << "WrongAnimal assign constructor called" << std::endl;
    if (this != &src)
        this->type = src.type;
    return (*this);
}