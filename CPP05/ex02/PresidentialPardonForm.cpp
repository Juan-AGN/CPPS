#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl; 
}

PresidentialPardonForm::PresidentialPardonForm() : AForm::AForm("PresidentialPardonForm",25, 5), target("Void") {
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm::AForm(src.getName(), src.getGradeSign(), src.getGradeExec()),  target(src.target) {
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string starget) : AForm::AForm("PresidentialPardonForm",25, 5), target(starget) {
    std::cout << "PresidentialPardonForm string and grade constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src) {
    std::cout << "PresidentialPardonForm assign operator called" << std::endl;

    if (this != &src)
        this->target = src.target;
    return (*this);
}

std::string PresidentialPardonForm::getTarget() const {
    return (this->target);
}

void PresidentialPardonForm::beExecuted() const {
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox."<< std::endl;
}

std::ostream &operator<<(std::ostream& os, const PresidentialPardonForm& theform)
{
    os << theform.getName() << ", grade to sign " << theform.getGradeSign() << ", grade to exec " << theform.getGradeExec() << ", target " << theform.getTarget() << ", is signed: " << theform.getIsSigned();
    return (os);
}
