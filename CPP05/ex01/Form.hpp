#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
class Bureaucrat;

class Form {
    public:
        Form();
        Form(std::string sname, int sgrade, int egrade);
        ~Form(void);
        Form(const Form& src);
        Form& operator=(const Form& src);
        std::string getName() const;
        int getGradeExec() const;
        int getGradeSign() const;
        bool getIsSigned() const;
        void beSigned(const Bureaucrat &buro);

        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

    private:
        const std::string   name;
        const int           gradeSign;
        const int           gradeExec;
        bool                isSigned;
        
};

std::ostream &operator<<(std::ostream& stream, const Form& buro);

#endif