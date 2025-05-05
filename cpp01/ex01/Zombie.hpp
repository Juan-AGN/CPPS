#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iomanip>
# include <iostream>
# include <string>
# include <stdlib.h>


class Zombie {
    public:
        void announce( void ); 

        void setName(std::string zomName);

        ~Zombie(void) {
            int random = std::rand() % 12;

            if (random == 0)
                std::cout << "The zombie named " << this->name << " was destroyed in an tragic accident involving a pointer and an lack of knowledge of the free function." << std::endl; 
            else if (random == 1)
                std::cout << "The zombie named " << this->name << " was destroyed in an tragic accident involving a fork and an electric outlet." << std::endl;
            else if (random == 2)
                std::cout << "The zombie named " << this->name << " was destroyed in an tragic accident involving a pipebomb and an lack of knowledge." << std::endl;
            else if (random == 3)
                std::cout << "The zombie named " << this->name << " was destroyed in an tragic accident involving a landmine an very determined turtle." << std::endl;
            else if (random == 4)
                std::cout << "The zombie named " << this->name << " was deleted from existence." << std::endl;
            else if (random == 5)
                std::cout << "The zombie named " << this->name << " was destroyed due to misteryous circunstances." << std::endl;
            else if (random == 6)
                std::cout << "The zombie named " << this->name << " noclipped trough the floor and was destroyed in the process." << std::endl;
            else if (random == 7)
                std::cout << "The zombie named " << this->name << " became toast and was destroyed by a enourmous pidgeon." << std::endl;
            else if (random == 8)
                std::cout << "The zombie named " << this->name << " found out the meaning of 'No thanks you', althouh he was quite ashamed about this, he stood tall and teavelled to many worlds trying to find a world where the 'No thanks you' became 'Yes please', he was determined he finally, but he finally was destroyed when he tried to capture a lighting into a bottle to make his dreams come true." << std::endl;
            else if (random == 9)
                std::cout << "The zombie named " << this->name << " found out why people usually don't wrestle with kangoroos the hard way and became a zombie pretzel, being destroyed in the proccess." << std::endl;
            else if (random == 10)
                std::cout << this->name << " never existed, there was never an " << this->name << " and if he existed, he probably was destroyed, so dont ever talk about him again." << std::endl;
            else if (random == 11)
                std::cout << "We dont talk about the zombie named " << this->name << " in this lair. (no, but seriously, he has been destroyed)" << std::endl;
        };

    private:
        std::string name;
        
};

#endif