#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <exception>

class NotFound : public std::exception {
    public:
        virtual const char *what() const throw() {
            return ("easyfind: Not found");
        }
};



template <typename T>
typename T::const_iterator easyfind(const T &cont, const int find)
{
    typename T::const_iterator found = std::find(cont.begin(), cont.end(), find);

    if (found == cont.end())
        throw NotFound();
    return (found);
}


#endif