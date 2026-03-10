#ifndef  RPN_HPP
# define  RPN_HPP

# include <stack>
# include <iostream>
# include <string>
# include <cctype>


class   RPN {
    public:
        RPN();
        ~RPN();
        RPN(const std::string &input);
        RPN(const RPN &toCopy);
        RPN &operator=(const RPN &toCopy);
    
        void execInput();

        class parseError : public std::exception {
        public:
            virtual const char *what() const throw() {
                return ("RPN: Parse error");
            }
        };

        class divideCero : public std::exception {
        public:
            virtual const char *what() const throw() {
                return ("RPN: Cant divide 0 by 0");
            }
        };

    private:
        std::stack<int> _stack;
        std::string _input;

        void stacker(char c);
        void calc(int one, int two, char operation);
};

#endif