#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T> void iter(const T arr[], const unsigned long l, void(*f)(const T &))
{
    for (unsigned long i = 0; i < l; i ++)
        f(arr[i]);
}

template <typename T> void iter(T arr[], const unsigned long l, void(*f)(T &))
{
    for (unsigned long i = 0; i < l; i ++)
        f(arr[i]);
}

#endif