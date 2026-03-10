#include <iostream>

#include "Bureaucrat.hpp"

#include "Form.hpp"

int main()
{
    Bureaucrat lowone("Paco", 136);
    Bureaucrat highone("Tim", 20);

    Form lowform("Nonimportant thing", 135, 60);
    Form highform("Important thing", 21, 1);

    std::cout << "Graveyard shift is here!" << std::endl;
    std::cout << lowone << " is here to do his shift." << std::endl;
    std::cout << highone << " is for supervison." << std::endl;
    std::cout << lowone << " is on paco's table." << std::endl;
    std::cout << highone << " is on Tim's table." << std::endl << std::endl;
    std::cout << "********************" << std::endl << std::endl;
    std::cout << lowone << " is going to try and sign " << lowform << std::endl;
    lowone.signForm(lowform);
    std::cout << "Time to ask for a raise to sign the Form." << std::endl;
    lowone.getRaise();
    lowone.signForm(lowform);
    std::cout << std::endl << "********************" << std::endl << std::endl;
    std::cout << highone << " is going to try and sign " << highform << std::endl;
    highone.signForm(highform);
}