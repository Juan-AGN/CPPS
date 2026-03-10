#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <iostream>

class  Span {
    public:
        Span();
        ~Span();
        Span(unsigned int limit);
        Span(const Span &toCopy);
        Span &operator=(const Span &toCopy);

        void addNumber(int number);

        void insert(unsigned long size, int number);

        unsigned long shortestSpan() const;

        unsigned long longestSpan() const;


        template <typename iterator>
        void insertRange(const iterator start, const iterator end);

        class Full : public std::exception {
        public:
            virtual const char *what() const throw() {
                return ("Span: Span full");
            }
        };

        class CantFit : public std::exception {
        public:
            virtual const char *what() const throw() {
                return ("Span: Cant fit numbers in Span");
            }
        };

        class FewNumbers : public std::exception {
        public:
            virtual const char *what() const throw() {
                return ("Span: Span too short");
            }
        };

    
    private:
        unsigned int _limit;
        std::vector<int> _numbers;
};

template <typename iterator>
void Span::insertRange(const iterator start, const iterator end)
{
    if (std::distance(start, end) + this->_numbers.size() > this->_limit)
        throw CantFit();

    this->_numbers.insert(this->_numbers.end(), start, end);
}


#endif