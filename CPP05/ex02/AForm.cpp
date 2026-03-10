#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::~AForm(void)
{
    std::cout << "AForm destructor called" << std::endl; 
}

AForm::AForm() : name("Paperware AForm"), gradeSign(150), gradeExec(150), isSigned(false) {
    std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(const AForm& src) : name(src.name), gradeSign(src.gradeSign), gradeExec(src.gradeExec), isSigned(src.isSigned) {
    std::cout << "AForm copy constructor called" << std::endl;
    if (this->gradeSign > 150 || this->gradeExec > 150)
        throw AForm::GradeTooLowException();
    if (this->gradeSign < 1 || this->gradeExec < 1)
        throw AForm::GradeTooHighException();
}

AForm::AForm(std::string sname, int sgrade, int egrade) : name(sname), gradeSign(sgrade), gradeExec(egrade), isSigned(false) {
    std::cout << "AForm string and grade constructor called" << std::endl;
    if (this->gradeSign > 150 || this->gradeExec > 150)
        throw AForm::GradeTooLowException();
    if (this->gradeSign < 1 || this->gradeExec < 1)
        throw AForm::GradeTooHighException();
}

AForm& AForm::operator=(const AForm& src) {
    std::cout << "AForm assign operator called" << std::endl;

    if (this != &src)
    {
        this->isSigned = src.isSigned;
    }
    return (*this);
}

std::string AForm::getName() const {
    return (this->name);
}

int AForm::getGradeSign() const {
    return (this->gradeSign);
}

int AForm::getGradeExec() const {
    return (this->gradeExec);
}

bool AForm::getIsSigned() const {
    return (this->isSigned);
}


void AForm::beSigned(const Bureaucrat &buro) {
    if (this->gradeSign < buro.getGrade())
        throw AForm::GradeTooLowException();
    else
        this->isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (this->getIsSigned() == false)
        throw AForm::NotSignedException();
    else if (executor.getGrade() > this->getGradeExec())
        throw AForm::GradeTooLowException();
    else
        this->beExecuted();
}

const char *AForm::GradeTooHighException::what() const throw() {
    return ("AForm: Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw() {
    return ("AForm: Grade too low");
}

const char *AForm::NotSignedException::what() const throw() {
    return ("AForm: Not signed");
}

std::ostream &operator<<(std::ostream& os, const AForm& theform)
{
    os << theform.getName() << ", grade to sign " << theform.getGradeSign() << ", grade to exec " << theform.getGradeExec() << ", is signed: " << theform.getIsSigned();
    return (os);
}
