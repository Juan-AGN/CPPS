#include "Span.hpp"

Span::Span() : _limit(0), _numbers() {}

Span::~Span() {}

Span::Span(unsigned int limit) : _limit(limit), _numbers() {}

Span::Span(const Span &toCopy)
{
    *this = toCopy;
}

Span &Span::operator=(const Span &toCopy)
{
    if (this == &toCopy)
        return (*this);
    this->_limit = toCopy._limit;
    this->_numbers = toCopy._numbers;
    return (*this);
}

void Span::addNumber(int number)
{
    if (_numbers.size() >= this->_limit)
        throw Full();
    
    _numbers.push_back(number);
}

void Span::insert(unsigned long size, int number)
{
    if (_numbers.size() + size > this->_limit)
        throw CantFit();
    
    for (unsigned long i = 0; i < size; i ++)
        _numbers.push_back(number);
}

unsigned long Span::shortestSpan() const
{
    unsigned long min = this->longestSpan();

    if (this->_numbers.size() < 2)
        throw FewNumbers();
    if (min == 0)
        return (0);
    
    std::vector<int> copy = this->_numbers;
    std::sort(copy.begin(), copy.end());

    for (std::vector<int>::iterator current = copy.begin(); (current + 1) != copy.end(); current ++)
        if (static_cast<unsigned long>(*(current + 1) - *current) < min)
            min = static_cast<unsigned long>(*(current + 1) - *current);
    return (min);
}

unsigned long Span::longestSpan() const
{
    if (this->_numbers.size() < 2)
        throw FewNumbers();
    return (*std::max_element(this->_numbers.begin(), this->_numbers.end()) - *std::min_element(this->_numbers.begin(), this->_numbers.end()));
}
