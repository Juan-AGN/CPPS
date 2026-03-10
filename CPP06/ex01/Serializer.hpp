#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"
# include <iostream>
# include <exception>
# include <stdint.h>

class  Serializer {
    private:
        Serializer();

    public:
        static uintptr_t serialize(Data* ptr);

        static Data* deserialize(uintptr_t raw);

};


#endif