#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        virtual ~ShrubberyCreationForm(void);
        ShrubberyCreationForm(const ShrubberyCreationForm& src);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);
        std::string getTarget() const;
        class OutfileFailException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

    private:
        std::string target;

    protected:
        void beExecuted() const;
};

std::ostream &operator<<(std::ostream& os, const ShrubberyCreationForm& theform);

#endif