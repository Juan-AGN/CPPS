#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
class Bureaucrat;

class AForm {
    public:
        AForm();
        AForm(std::string sname, int sgrade, int egrade);
        virtual ~AForm(void);
        AForm(const AForm& src);
        AForm& operator=(const AForm& src);
        std::string getName() const;
        int getGradeExec() const;
        int getGradeSign() const;
        bool getIsSigned() const;
        void beSigned(const Bureaucrat &buro);
        void execute(Bureaucrat const & executor) const;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class NotSignedException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

    private:
        const std::string   name;
        const int           gradeSign;
        const int           gradeExec;
        bool                isSigned;

    protected:
        virtual void beExecuted() const = 0;
        
};

std::ostream &operator<<(std::ostream& stream, const AForm& buro);

#endif