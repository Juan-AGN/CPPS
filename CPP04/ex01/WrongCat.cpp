#include "WrongCat.hpp"

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat destructor called" << std::endl; 
}

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << "WrongCat constructor called" << std::endl; 
}

WrongCat::WrongCat(const WrongCat &tocopy) {
    std::cout << "WrongCat copy constructor called" << std::endl;
    this->type = tocopy.type; 
}

WrongCat& WrongCat::operator=(const WrongCat& src) {
    std::cout << "WrongCat assign operator called" << std::endl;
    if (this != &src)
        this->type = src.type;
    return (*this);
}

