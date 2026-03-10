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

        int getRawBits( void ) const;

        void setRawBits( int const raw );
        
        int toInt( void ) const;

        float toFloat( void ) const;

    private:
        int value;
        static const int bits = 8;
        
};

std::ostream &operator<<(std::ostream& stream, const Fixed& number);


#endif