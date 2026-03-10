#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <exception>
# include <ctime>
# include <cstdlib>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        virtual ~RobotomyRequestForm(void);
        RobotomyRequestForm(const RobotomyRequestForm& src);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& src);
        const std::string getTarget() const;

    private:
        std::string target;

    protected:
        void beExecuted() const;
};

std::ostream &operator<<(std::ostream& os, const RobotomyRequestForm& theform);

#endif