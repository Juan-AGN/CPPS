#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <limits>
# include <cmath>
# include <cerrno>
# include <iomanip>

class  ScalarConverter {
    private:
        ScalarConverter();

    public:
        static void convert(std::string &str);

};

#endif