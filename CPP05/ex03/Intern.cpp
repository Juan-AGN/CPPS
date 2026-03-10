#include "Intern.hpp"
#include "Bureaucrat.hpp"

Intern::~Intern(void)
{
    std::cout << "Intern destructor called" << std::endl; 
}

Intern::Intern() {
    std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern& src) {
    (void)src;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& src) {
    std::cout << "Intern assign operator called" << std::endl;

    (void)src;
    return (*this);
}

AForm *Intern::makeForm(const std::string name, const std::string target)
{
    AForm *toret;
    std::string cases[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    int i = -1;

    while (i++ < 3)
        if (cases[i] == name)
            break ;

    switch (i)
    {
    case 0:
        toret = new ShrubberyCreationForm(target);
        std::cout << "Intern creates " << *toret << std::endl;
        return (toret);
    case 1:
        toret = new RobotomyRequestForm(target);
        std::cout << "Intern creates " << *toret << std::endl;
        return (toret);
    case 2:
        toret = new PresidentialPardonForm(target);
        std::cout << "Intern creates " << *toret << std::endl;
        return (toret);
    default:
        std::cout << "Intern couldn't create the form " << name << std::endl;
        return (NULL);
    }
}
