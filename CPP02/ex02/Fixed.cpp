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

Fixed Fixed::operator*(const Fixed& other)
{
    Fixed toRet(this->toFloat() * other.toFloat());

    return (toRet);
}

Fixed Fixed::operator/(const Fixed& other)
{
    Fixed toRet(this->toFloat() / other.toFloat());

    return (toRet);
}

Fixed Fixed::operator+(const Fixed& other)
{
    Fixed toRet(this->toFloat() + other.toFloat());

    return (toRet);
}

Fixed& Fixed::operator++()
{
    this->value += 1;

    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed   toret(*this);
    this->value += 1;

    return (toret);
}

Fixed Fixed::operator-(const Fixed& other)
{
    Fixed toRet(this->toFloat() - other.toFloat());

    return (toRet);
}

Fixed& Fixed::operator--()
{
    this->value -= 1;

    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed   toret(*this);
    this->value -= 1;

    return (toret);
}

std::ostream &operator<<(std::ostream& os, const Fixed& p)
{
    os << p.toFloat();
    return (os);
}

bool Fixed::operator>(const Fixed& other)
{
    if (this->toFloat() > other.toFloat())
        return (true);
    return (false);
}

bool Fixed::operator<(const Fixed& other)
{
    if (this->toFloat() < other.toFloat())
        return (true);
    return (false);
}

bool Fixed::operator>=(const Fixed& other)
{
    if (this->toFloat() >= other.toFloat())
        return (true);
    return (false);
}

bool Fixed::operator<=(const Fixed& other)
{
    if (this->toFloat() <= other.toFloat())
        return (true);
    return (false);
}

bool Fixed::operator==(const Fixed& other)
{
    if (this->toFloat() == other.toFloat())
        return (true);
    return (false);
}

bool Fixed::operator!=(const Fixed& other)
{
    if (this->toFloat() != other.toFloat())
        return (true);
    return (false);
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

const Fixed &Fixed::max( const Fixed& one, const Fixed& two )
{
    if (one.toFloat() > two.toFloat())
        return (one);
    return (two);
}

Fixed &Fixed::max( Fixed& one, Fixed& two )
{
    if (one > two)
        return (one);
    return (two);
}

const Fixed &Fixed::min( const Fixed& one, const Fixed& two )
{
    if (one.toFloat() < two.toFloat())
        return (one);
    return (two);
}

Fixed &Fixed::min( Fixed& one, Fixed& two )
{
    if (one < two)
        return (one);
    return (two);
}
