#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        virtual ~PresidentialPardonForm(void);
        PresidentialPardonForm(const PresidentialPardonForm& src);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
        std::string getTarget() const;

    private:
        std::string target;

    protected:
        void beExecuted() const;
};

std::ostream &operator<<(std::ostream& os, const PresidentialPardonForm& theform);

#endif