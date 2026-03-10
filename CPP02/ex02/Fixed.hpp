#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

# include <cmath>

class Fixed {
    public:
        ~Fixed(void);

        Fixed(void);

        Fixed(const Fixed &toCopy);

        Fixed(const int toCopy);

        Fixed(const float toCopy);

        Fixed& operator=(const Fixed& other);

        Fixed operator*(const Fixed& other);

        Fixed operator/(const Fixed& other);

        Fixed operator+(const Fixed& other);

        Fixed& operator++();

        Fixed operator++(int);

        Fixed operator-(const Fixed& other);

        Fixed& operator--();

        Fixed operator--(int);

        bool operator>(const Fixed& other);

        bool operator<(const Fixed& other);

        bool operator>=(const Fixed& other);

        bool operator<=(const Fixed& other);

        bool operator==(const Fixed& other);

        bool operator!=(const Fixed& other);

        int getRawBits( void ) const;

        void setRawBits( int const raw );
        
        int toInt( void ) const;

        float toFloat( void ) const;

        static const Fixed &max(const Fixed& one, const Fixed& two);

        static Fixed &max(Fixed& one, Fixed& two);

        static const Fixed &min(const Fixed& one, const Fixed& two);

        static Fixed &min(Fixed& one, Fixed& two);

    private:
        int value;
        static const int bits = 8;
        
};

std::ostream &operator<<(std::ostream& stream, const Fixed& number);

#endif