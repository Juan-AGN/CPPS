#include <iostream>
#include <exception>

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <class T>
class  Array {
    public:
        Array();
        ~Array();
        Array(const Array &arr);
        Array(unsigned int len);
        Array &operator=(const Array &arr);
        T &operator[](unsigned long n);
        const T operator[](unsigned long n) const;

        unsigned int size() const;

        class OverflowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

    private:
        T *_elements;
        unsigned int _len;
};

template <typename T> Array<T>::Array() : _elements(new T[0]), _len(0) {}

template <typename T> Array<T>::Array(unsigned int len) : _elements(new T[len]), _len(len) {}

template <typename T> Array<T>::~Array()
{
    delete[] this->_elements;
}

template <typename T> Array<T>::Array(const Array<T> &arr) : _elements(new T[0]), _len(0) {
    *this = arr;
}

template <typename T> Array<T> &Array<T>::operator=(const Array<T> &arr) {
    if (this != &arr)
    {
        delete[] (this->_elements);
        this->_elements = new T[arr._len];
        this->_len = arr._len;
        for (unsigned int i = 0; i < _len; i ++)
            this->_elements[i] = arr._elements[i];
    }
    return (*this);
}


template <typename T> unsigned int Array<T>::size() const {
    return (this->_len);
}

template <typename T> const char *Array<T>::OverflowException::what() const throw() {
    return ("Array: Overflow");
}

template <typename T> T &Array<T>::operator[](unsigned long n)
{
    if (n >= this->_len)
        throw OverflowException();

    return (this->_elements[n]);
}

template <typename T> const T Array<T>::operator[](unsigned long n) const
{
    if (n >= this->_len)
        throw OverflowException();

    return (this->_elements[n]);
}

#endif