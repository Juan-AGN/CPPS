#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
    public:
        ~Fixed(void);

        Fixed(void);

        Fixed(const Fixed &toCopy);

        Fixed& operator=(const Fixed& other);

        int getRawBits( void ) const;

        void setRawBits( int const raw );

    private:
        int value;
        static const int bits = 8;
        
};

#endif