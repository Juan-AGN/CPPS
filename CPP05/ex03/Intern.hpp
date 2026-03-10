#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern{
    public:
        ~Intern(void);

        Intern();

        Intern(const Intern& src);

        Intern& operator=(const Intern& src);

        AForm *makeForm(const std::string name, const std::string target);
};

#endif