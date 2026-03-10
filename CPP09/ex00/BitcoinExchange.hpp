#ifndef  BITCOINTEXCHANGE_HPP
# define  BITCOINTEXCHANGE_HPP

# include <map>
# include <algorithm>
# include <iostream>
# include <fstream>
# include <string>


class   BitcoinExchange {
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const std::string &inFile);
        BitcoinExchange(const BitcoinExchange &toCopy);
        BitcoinExchange &operator=(const BitcoinExchange &toCopy);
    
        void getValues();

        class parseError : public std::exception {
        public:
            virtual const char *what() const throw() {
                return ("BitcoinExchange: Parse error");
            }
        };

        class openError : public std::exception {
        public:
            virtual const char *what() const throw() {
                return ("BitcoinExchange: Open error");
            }
        };

    private:
        std::map<std::string, float> _database;
        std::string _input;

        void ParseDatabase(std::ifstream &inFile);
        bool acceptNumbers(std::string str);
        bool dateNumbers(std::string str);
        bool LeapYear(int year);
        bool softAcceptNumbers(std::string str);
        void execLine(std::string str);
        bool acceptNumbersInput(std::string str);
};

#endif