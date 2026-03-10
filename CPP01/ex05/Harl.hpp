#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>
# include <map>

class Harl {
    public:
        void complain( std::string level );

        ~Harl(void);

        Harl(void);

    private:
        void debug( void );
    
        void info( void );
    
        void warning( void );
    
        void error( void );
        
};

typedef	void (Harl::*functions)(void);

#endif