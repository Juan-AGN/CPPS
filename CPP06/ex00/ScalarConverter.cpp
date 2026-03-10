#include "ScalarConverter.hpp"

void ft_allempty()
{
    std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: 0" << std::endl;
    std::cout << "float: 0.0f" << std::endl;
    std::cout << "double: 0.0" << std::endl;
}

void ft_impossible()
{
    std::cout << "char: Impossible" << std::endl;
    std::cout << "int: Impossible" << std::endl;
    std::cout << "float: Impossible" << std::endl;
    std::cout << "double: Impossible" << std::endl;
}

bool ft_isprintable(int c) {
    if (c < 127 && c > 31)
        return (true);
    else
        return (false);
}

void ft_trchar(std::string &str) {
    if (isprint(str[0]))
        std::cout << "char: " << str[0] << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
    std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
}

bool ft_trint(std::string &str) {
    unsigned long i = 0;

    if (str[i] == '-' || str[i] == '+')
        i ++;
    for (; i < str.length(); i ++)
        if (!isdigit(str[i]))
            return (false);
    return (true);
}

bool ft_trfloat(std::string &str) {
    unsigned long i = 0;
    bool point = false;

    if (str[i] == '-' || str[i] == '+')
        i ++;
    for (; i < str.length() - 1; i ++)
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
    if ((str[i] == 'f' || str[i] == 'F') && point == true)
        return (true);
    return (false);
}

bool ft_trdouble(std::string &str) {
    unsigned long i = 0;
    bool point = false;

    if (str[i] == '-' || str[i] == '+')
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
    if (point == true)
        return (true);
    return (false);
}

void ft_printer(std::string &str)
{
    long double n;

    n = std::strtod(str.c_str(), NULL);

    if (n > 127 || n < 0)
        std::cout << "char: Impossible" << std::endl;
    else if (!ft_isprintable(n))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(n) << std::endl;

    if (static_cast<long>(n) > std::numeric_limits<int>::max() || static_cast<long>(n) < std::numeric_limits<int>::min())
        std::cout << "int: " << "Impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(n) << std::endl;

    if (floor(n) == n && n <= 999999 && n >= -999999)
        std::cout << std::fixed << std::setprecision(1);

    if (static_cast<float>(n) > std::numeric_limits<float>::max())
        std::cout << "float: " << "+inff" << std::endl;
    else if (static_cast<float>(n) < -std::numeric_limits<float>::max())
        std::cout << "float: " << "-inff" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(n) << "f" << std::endl;

    if (static_cast<double>(n) > std::numeric_limits<double>::max())
        std::cout << "double: " << "+inf" << std::endl;
    else if (static_cast<double>(n) < -std::numeric_limits<double>::max())
        std::cout << "double: " << "-inf" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(n) << std::endl;
}

void ft_printspecial(std::string &str)
{
    long double n;

    if (str == "-inff" || str == "+inff" || str == "nanf" || str == "-inf" || str == "+inf" || str == "nan")
    {
        n = std::strtod(str.c_str(), NULL);
        std::cout << "char: Impossible" << std::endl;
        std::cout << "int: Impossible" << std::endl;
        if (n > 0)
            std::cout << "float: +" << static_cast<float>(n) << "f" << std::endl;
        else
            std::cout << "float: " << static_cast<float>(n) << "f" << std::endl;
        if (n > 0)
            std::cout << "double: +" << static_cast<double>(n) << std::endl;
        else
            std::cout << "double: " << static_cast<double>(n) << std::endl;
    }
    else
        ft_impossible();
}

void ScalarConverter::convert(std::string &str)
{
    if (str.empty())
        ft_allempty();
    else if (str.length() == 1 && !std::isdigit(str[0]))
        ft_trchar(str);
    else if (ft_trint(str) || ft_trfloat(str) || ft_trdouble(str))
        ft_printer(str);
    else
        ft_printspecial(str);
}
