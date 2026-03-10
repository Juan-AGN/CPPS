#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() 
{
    std::cout << "No input file, defaulting to input.txt" << std::endl;

    std::ifstream openDataBase("data.csv");
	if (!openDataBase)
    {
        std::cout << "Unable to open file" << std::endl;;
    	throw openError();
    }

    this->ParseDatabase(openDataBase);

    this->_input = "input.txt";
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &toCopy)
{
    *this = toCopy;
}

BitcoinExchange::BitcoinExchange(const std::string &inFile)
{
    std::ifstream openDataBase("data.csv");
	if (!openDataBase)
    {
        std::cout << "Unable to open file" << std::endl;;
    	throw openError();
    }

    this->ParseDatabase(openDataBase);
    this->_input = inFile;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &toCopy)
{
    if (this == &toCopy)
        return (*this);
    this->_database = toCopy._database;
    this->_input = toCopy._input;
    return (*this);
}

void BitcoinExchange::ParseDatabase(std::ifstream &inFile)
{
    std::string line;
    std::map<std::string, float> temp;
    unsigned long len;
    unsigned long nline = 1;

    if (getline(inFile, line))
    {
        if (line != "date,exchange_rate")
        {
            std::cout << "Invalid database line: " << nline << std::endl;
            throw parseError();
        }
        nline ++;
    }

	while (getline(inFile, line))
	{
        len = line.length();
        if (len >= 12)
        {
            if (line[10] != ',' || line[4] != '-' || line[7] != '-' || !this->acceptNumbers(line.substr(11)) || !this->dateNumbers(line))
            {
                std::cout << "Invalid database line: <" << nline << "> " << line << std::endl;
                throw parseError();
            }
            if (nline < 3)
                temp.insert(std::make_pair(line.substr(0, 10), std::atof(line.substr(11).c_str())));
            else
            {
                if ((temp.rbegin())->first < line.substr(0, 10))
                    temp.insert(std::make_pair(line.substr(0, 10), std::atof(line.substr(11).c_str())));
                else
                {
                    std::cout << "Invalid database line: <" << nline << "> " << line << std::endl;
                    throw parseError();    
                }
            } 
        }
        else
        {
            std::cout << "Invalid database line: <" << nline << "> " << line << std::endl;
            throw parseError();
        }
        nline ++;
    }
    if (nline < 3)
    {
        std::cout << "Database has no entries" << std::endl;
        throw parseError();
    }
    this->_database = temp;
}

bool BitcoinExchange::acceptNumbers(std::string str)
{
    unsigned long i = 0;
    bool point = false;

    if (str[0] == '.' && str.length() == 1)
        return (false);

    for (; i < str.length(); i ++)
    {
        if (!isdigit(str[i]) && str[i] != '.')
            return (false);
        if (str[i] == '.')
        {
            if (point == true)
                return (false);
            point = true;
        }
    }

    long double n = std::strtod(str.c_str(), NULL);
    if (n > 2147483648.0)
        return (false);
    return (true);
}

bool BitcoinExchange::acceptNumbersInput(std::string str)
{
    unsigned long i = 0;
    bool point = false;

    if (str[0] == '.' && str.length() == 1)
        return (false);

    for (; i < str.length(); i ++)
    {
        if (!isdigit(str[i]) && str[i] != '.')
            return (false);
        if (str[i] == '.')
        {
            if (point == true)
                return (false);
            point = true;
        }
    }

    long double n = std::strtod(str.c_str(), NULL);
    if (n > 1000)
        return (false);
    return (true);
}

bool BitcoinExchange::softAcceptNumbers(std::string str)
{
    unsigned long i = 0;
    bool point = false;

    if (str[0] == '.' && str.length() == 1)
        return (false);

    if (str[i] == '-')
        i ++;

    for (; i < str.length(); i ++)
    {
        if (!isdigit(str[i]) && str[i] != '.')
            return (false);
        if (str[i] == '.')
        {
            if (point == true)
                return (false);
            point = true;
        }
    }
    if (i == 1 && str[0] == '-')
        return (false);
    return (true);
}

bool BitcoinExchange::dateNumbers(std::string str)
{
    int nonleap[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int leap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (!std::isdigit(str[0]) || !std::isdigit(str[1]) || !std::isdigit(str[2]) || !std::isdigit(str[3]) || !std::isdigit(str[5]) || !std::isdigit(str[6]) || !std::isdigit(str[8]) || !std::isdigit(str[9]))
        return (false);
    int year = std::atoi(str.substr(0, 4).c_str());
    int month = std::atoi(str.substr(5, 2).c_str());
    int day = std::atoi(str.substr(8, 2).c_str());

    if (year < 2009)
        return (false);
    
    if (month > 12 || month == 0)
        return (false);
    if (day == 0)
        return (false);
    if (this->LeapYear(year) && day > leap[month -1])
        return (false);
    else if (!this->LeapYear(year) && day > nonleap[month - 1])
        return (false);
    return (true);
}

void BitcoinExchange::getValues()
{
    std::ifstream inFile(this->_input.c_str());

	if (!inFile) {
        std::cout << "Unable to open file" << std::endl;
    	throw openError();
    }

    std::string line;
    unsigned long len;

    if (getline(inFile, line))
    {
        if (line != "date | value")
        {
            std::cout << "Invalid input header: " << line << std::endl;
            throw parseError();
        }
    }

	while (getline(inFile, line))
	{
        len = line.length();
        if (len >= 14)
        {
            if (line[10] != ' ' || line[12] != ' ' || line[11] != '|' || line[4] != '-' || line[7] != '-' || !this->dateNumbers(line))
                std::cout << "Error: Bad input => " << line << std::endl;
            else if (!this->softAcceptNumbers(line.substr(13)))
                std::cout << "Error: Bad input => " << line << std::endl;
            else if (line[13] == '-')
                std::cout << "Error: not a positive number." << std::endl;
            else if (!acceptNumbersInput(line.substr(13)))
                std::cout << "Error: too large a number." << std::endl;
            else
                execLine(line);
        }
        else
            std::cout << "Error: Bad input => " << line << std::endl;
    }
}

void BitcoinExchange::execLine(std::string str)
{
    float tocalc;

    if ((this->_database.begin())->first > str.substr(0, 10))
    {
        std::cout << "Error: date too early." << std::endl;
        return ;
    }

    std::map<std::string, float>::iterator node = this->_database.upper_bound(str.substr(0, 10));
    node --;

    tocalc = node->second;

    float input = std::atof(str.substr(13).c_str());

    if (input * tocalc > 2147483648.0)
    {
        std::cout << "Error: too large a number." << std::endl;
        return ;
    }

    std::cout << str.substr(0, 10) << " => " << input << " = " << tocalc * input << std::endl;
}

bool BitcoinExchange::LeapYear(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}
