#include "Data.hpp"

Data::Data() : _magicNumber(0) {};

Data::~Data() {};

Data::Data(int number) : _magicNumber(number) {};

Data::Data(const Data &toCopy) : _magicNumber(toCopy._magicNumber) {};

Data &Data::operator=(const Data &toCopy)
{
    if (this == &toCopy)
        return (*this);
    
    this->_magicNumber = toCopy._magicNumber;
    return (*this);
}

int Data::getNumber() const
{
    return (this->_magicNumber);
}
