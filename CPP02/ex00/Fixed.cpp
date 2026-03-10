#include "Fixed.hpp"

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl; 
}

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    this->value = 0; 
}

Fixed::Fixed(const Fixed &toCopy)
{
    std::cout << "Copy constructor called" << std::endl; 
    *this = toCopy;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl; 
    return (this->value);
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &other)
		return (*this);
    this->value = other.getRawBits();
    return (*this);
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl; 
    this->value = raw;
}
