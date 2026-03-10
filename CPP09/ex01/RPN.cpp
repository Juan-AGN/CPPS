#include "RPN.hpp"

RPN::RPN() 
{
    std::cout << "No input, defaulting empty string" << std::endl;

    this->_input = "1 1 +";
}

RPN::~RPN() {}

RPN::RPN(const RPN &toCopy)
{
    *this = toCopy;
}

RPN::RPN(const std::string &input)
{
    this->_input = input;
}

RPN &RPN::operator=(const RPN &toCopy)
{
    if (this == &toCopy)
        return (*this);
    this->_input = toCopy._input;
    return (*this);
}

void RPN::execInput()
{
    unsigned long i = 0;

    if (this->_input == "")
        return ;

    while (this->_input[i] == ' ')
        i ++;

    while (i < this->_input.length())
    {
        this->stacker(this->_input[i]);
        i ++;
        if (std::isdigit(static_cast<unsigned char>(this->_input[i])) || this->_input[i] == '+' || this->_input[i] == '-' || this->_input[i] == '/' || this->_input[i] == '*')
        {
            std::cerr << "Error" << std::endl;
            this->_stack = std::stack<int>();
            throw parseError();
        }
        while (this->_input[i] == ' ')
            i ++;
    }

    if (this->_stack.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        this->_stack = std::stack<int>();
        throw parseError();    
    }

    std::cout << this->_stack.top() << std::endl;
    this->_stack = std::stack<int>();
}

void RPN::stacker(char c)
{
    int one;
    int two;

    if (std::isdigit(static_cast<unsigned char>(c)))
    {
        this->_stack.push(c - '0');
    }
    else if (c == '+' || c == '-' || c == '/' || c == '*')
    {
        if (this->_stack.size() < 2)
        {
            std::cerr << "Error" << std::endl;
            throw parseError();        
        }
        two = this->_stack.top();
        this->_stack.pop();
        one = this->_stack.top();
        this->_stack.pop();
        this->calc(one, two, c);
    }
    else
    {
        std::cerr << "Error" << std::endl;
        throw parseError();    
    }
}

void RPN::calc(int one, int two, char operation)
{
    if (operation == '+')
        this->_stack.push(one + two);
    else if (operation == '-')
        this->_stack.push(one - two);
    else if (operation == '*')
        this->_stack.push(one * two);
    else if (operation == '/')
    {
        if (two == 0)
        {
            std::cerr << "Error" << std::endl;
            throw divideCero();      
        }
        this->_stack.push(one / two);
    }
}
