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

Fixed::Fixed(int toCopy)
{
    std::cout << "Int constructor called" << std::endl; 
    this->value = toCopy << this->bits;
}

Fixed::Fixed(float toCopy)
{
    std::cout << "Float constructor called" << std::endl; 
    this->value = static_cast<int>(roundf((toCopy) * (1 << this->bits)));
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
    this->value = other.value;
    return (*this);
}

std::ostream &operator<<(std::ostream& os, const Fixed& p)
{
    os << p.toFloat();
    return (os);
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl; 
    this->value = raw;
}

int Fixed::toInt( void ) const
{
    return (static_cast<int>(this->value >> this->bits));
}

float Fixed::toFloat( void ) const
{
    return (static_cast<float>(this->value) / (1 << this->bits));
}
