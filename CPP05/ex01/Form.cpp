#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::~Form(void)
{
    std::cout << "Form destructor called" << std::endl; 
}

Form::Form() : name("Paperware Form"), gradeSign(150), gradeExec(150), isSigned(false) {
    std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form& src) : name(src.name), gradeSign(src.gradeSign), gradeExec(src.gradeExec), isSigned(src.isSigned) {
    std::cout << "Form copy constructor called" << std::endl;
    if (this->gradeSign > 150 || this->gradeExec > 150)
        throw Form::GradeTooLowException();
    if (this->gradeSign < 1 || this->gradeExec < 1)
        throw Form::GradeTooHighException();
}

Form::Form(std::string sname, int sgrade, int egrade) : name(sname), gradeSign(sgrade), gradeExec(egrade), isSigned(false) {
    std::cout << "Form string and grade constructor called" << std::endl;
    if (this->gradeSign > 150 || this->gradeExec > 150)
        throw Form::GradeTooLowException();
    if (this->gradeSign < 1 || this->gradeExec < 1)
        throw Form::GradeTooHighException();
}

Form& Form::operator=(const Form& src) {
    std::cout << "Form assign operator called" << std::endl;

    if (this != &src)
    {
        this->isSigned = src.isSigned;
    }
    return (*this);
}

std::string Form::getName() const {
    return (this->name);
}

int Form::getGradeSign() const {
    return (this->gradeSign);
}

int Form::getGradeExec() const {
    return (this->gradeExec);
}

bool Form::getIsSigned() const {
    return (this->isSigned);
}


void Form::beSigned(const Bureaucrat &buro) {
    if (this->gradeSign < buro.getGrade())
        throw Form::GradeTooLowException();
    else
        this->isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
    return ("Form: Grade too high");
}

const char *Form::GradeTooLowException::what() const throw() {
    return ("Form: Grade too low");
}

std::ostream &operator<<(std::ostream& os, const Form& theform)
{
    os << theform.getName() << ", grade to sign " << theform.getGradeSign() << ", grade to exec " << theform.getGradeExec() << ", is signed: " << theform.getIsSigned();
    return (os);
}
