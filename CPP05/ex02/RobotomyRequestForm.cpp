#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl; 
}

RobotomyRequestForm::RobotomyRequestForm() : AForm::AForm("RobotomyRequestForm", 72, 45), target("Void") {
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm::AForm(src.getName(), src.getGradeSign(), src.getGradeExec()),  target(src.target) {
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string starget) : AForm::AForm("RobotomyRequestForm",72, 45), target(starget) {
    std::cout << "RobotomyRequestForm string and grade constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src) {
    std::cout << "RobotomyRequestForm assign operator called" << std::endl;

    if (this != &src)
        this->target = src.target;
    return (*this);
}

const std::string RobotomyRequestForm::getTarget() const {
    return (this->target);
}

void RobotomyRequestForm::beExecuted() const {
    srand(time(NULL));

    std::cout << "rizzz... rizzz.... bzzzzzz.......... bzzzzzz.." << std::endl;
    std::cout << "bzzzzzz.......... bzzz.. rizzzzzzzz.... " << std::endl;
    if (rand() % 2 == 1)
        std::cout << "Done!, " << this->getTarget() << " has been robotomized successfully."<< std::endl;
    else
        std::cout << "Failed robotimation " << this->getTarget() << " scaped robotimation.... For now."<< std::endl;
}

std::ostream &operator<<(std::ostream& os, const RobotomyRequestForm& theform)
{
    os << theform.getName() << ", grade to sign " << theform.getGradeSign() << ", grade to exec " << theform.getGradeExec() << ", target " << theform.getTarget() << ", is signed: " << theform.getIsSigned();
    return (os);
}

