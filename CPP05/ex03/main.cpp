#include <iostream>

#include "Bureaucrat.hpp"

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern newone;
    Bureaucrat highone("Tim", 4);

    AForm *formOne = NULL;
    AForm *formTwo = NULL;
    AForm *formTree = NULL;

    std::cout << std::endl << "********************" << std::endl;
    std::cout << "Everyone!, to work!" << std::endl;
    std::cout << "********************" << std::endl << std::endl;

    formOne = newone.makeForm("Sausage", "Cafeteria");
    std::cout << "********************" << std::endl << std::endl;
    formOne = newone.makeForm("PresidentialPardonForm", "Bob");
    highone.executeForm(*formOne);
    std::cout << "********************" << std::endl << std::endl;
    formTwo = newone.makeForm("RobotomyRequestForm", "The other intern");
    highone.executeForm(*formTwo);
    std::cout << "********************" << std::endl << std::endl;
    formTree = newone.makeForm("ShrubberyCreationForm", "Ilikethrees");
    highone.executeForm(*formTree);
    std::cout << "********************" << std::endl << std::endl;

    delete (formOne);
    delete (formTwo);
    delete (formTree);
}