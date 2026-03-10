#ifndef Brain_HPP
# define Brain_HPP

# include <iostream>

class Brain {
    public:
        Brain();
        Brain(const Brain &tocopy);
        Brain& operator=(const Brain &src);
        ~Brain();
        std::string ideas[100];

    private:
        

    protected:

        
};

#endif