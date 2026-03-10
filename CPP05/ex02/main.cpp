#include <iostream>

#include "Bureaucrat.hpp"

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    Bureaucrat newone("Eustaquio", 150);
    Bureaucrat lowone("Paco", 70);
    Bureaucrat highone("Tim", 4);
    Bureaucrat middleone("J.avi", 20);

    AForm *creation = new ShrubberyCreationForm("Anton");
    RobotomyRequestForm robots("Smoke");
    PresidentialPardonForm pardon("The one and only");

    std::cout << std::endl << "********************" << std::endl;
    std::cout << "Everyone!, to work!" << std::endl;
    std::cout << "********************" << std::endl << std::endl;

    std::cout << lowone << " is trying to execute " << *creation << "." << std::endl;
    lowone.executeForm(*creation);
    std::cout << std::endl << "********************" << std::endl << std::endl;
    std::cout << middleone << " is trying to sign " << *creation << "." << std::endl;
    middleone.signForm(*creation);
    std::cout << newone << " is trying to execute " << *creation << "." << std::endl;
    newone.executeForm(*creation);
    std::cout << std::endl << "********************" << std::endl << std::endl;
    std::cout << lowone << " is trying again to execute " << *creation << "." << std::endl;
    lowone.executeForm(*creation);
    std::cout << std::endl << "********************" << std::endl << std::endl;
    std::cout << highone << " is signing everything." << std::endl;
    highone.signForm(robots);
    highone.signForm(pardon);
    std::cout << std::endl << "********************" << std::endl << std::endl;
    std::cout << middleone << " is trying to execute " << robots << "." << std::endl;
    middleone.executeForm(robots);
    std::cout << std::endl << "********************" << std::endl << std::endl;
    std::cout << highone << " is trying to execute " << pardon << "." << std::endl;
    highone.executeForm(pardon);
    std::cout << std::endl << "********************" << std::endl << std::endl;

    delete (creation);
}