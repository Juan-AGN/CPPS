#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>
# include <iostream>
# include <limits>
# include <string>
# include <stdlib.h>
# include "Contact.hpp"

class PhoneBook {
    public:
        PhoneBook() {
            oldest = 0;
            ncontacts = 0;
            last = 0;
        }

        void    search() {
            int         index = 1;
            int         searchIndex;
            std::string strindex;

            std::cout << "|___________________________________________" << std::endl;
            std::cout << "|   INDEX  |FIRST NAME|LAST  NAME| NICKNAME |" << std::endl;
            std::cout << "|__________|__________|__________|__________|" << std::endl;
            if (ncontacts != 0)
            {
                    for (int n = oldest + 1; n < this->ncontacts; n ++)
                {
                    std::cout << "|";
                    displayLimited(toStr(index));
                    displayLimited(this->contacts[n].name);
                    displayLimited(this->contacts[n].lastName);
                    displayLimited(this->contacts[n].nickName);
                    std::cout << std::endl;
                    std::cout << "|----------|----------|----------|----------|" << std::endl;
                    index ++;
                }
                for (int n = 0; n <= this->oldest; n ++)
                {
                    std::cout << "|";
                    displayLimited(toStr(index));
                    displayLimited(this->contacts[n].name);
                    displayLimited(this->contacts[n].lastName);
                    displayLimited(this->contacts[n].nickName);
                    std::cout << std::endl;
                    if (n != oldest)
                        std::cout << "|----------|----------|----------|----------|" << std::endl;
                    else
                        std::cout << "|__________|__________|__________|__________|" << std::endl;
                    index ++;
                }
            }

            std::cout << "|------ SEARCH ------>";
            std::getline(std::cin, strindex);
            if (std::cin.eof())
            {
                std::cout << std::endl;
                std::cout << "|EOF found, EOF not supported." << std::endl << "|" << std::endl << std::endl;
                exit(1);
            }

            searchIndex = toNbr(strindex);
            if (searchIndex == 0 || searchIndex > this->ncontacts)
            {
                std::cout << "|Index does not exist, not in the list or not formated correctly." << std::endl;
                return ;
            }

            index = 1;
            for (int n = oldest + 1; n < this->ncontacts; n ++)
            {
                if (n + 1 == index)
                {
                    displayFound(contacts[n]);
                    return ;
                }
                index ++;
            }
            for (int n = 0; n <= this->oldest; n ++)
            {
                if (n + 1 == index)
                {
                    displayFound(contacts[n]);
                    return ;
                }
                index ++;
            }
        };

        void    addContact() {
            std::string inputs[5];

            for (int n = 0; n < 5; n ++)
                inputs[n] = "";
            
            while (inputs[0] == "")
                inputs[0] = addContactInfo("|------- NAME ------->");
            
            while (inputs[1] == "")
                inputs[1] = addContactInfo("|----- LAST NAME ---->");
            
            while (inputs[2] == "")
                inputs[2] = addContactInfo("|----- NICKNAME ----->");
            
            while (inputs[3] == "")
                inputs[3] = addContactInfo("|--- PHONE NUMBER --->");
            
            while (inputs[4] == "")
                inputs[4] = addContactInfo("|-- DARKEST SECRET -->");

            if (ncontacts == 8)
                this->oldest++;
            else
                oldest = ncontacts;
            if (this->ncontacts != 8)
                this->ncontacts ++;
            if (this->oldest == 8)
                this->oldest = 0;

            this->contacts[oldest].name = inputs[0];
            this->contacts[oldest].lastName = inputs[1];
            this->contacts[oldest].nickName = inputs[2];
            this->contacts[oldest].phoneNumber = inputs[3];
            this->contacts[oldest].darkestSecret = inputs[4];
        };

    private:
        int         oldest;
        int         ncontacts;
        int         last;
        Contact     contacts[8];

        std::string    addContactInfo(const std::string output) {
            std::string toret;

            std::cout << output;
            std::getline(std::cin, toret);
            if (std::cin.eof())
            {
                std::cout << "|EOF found, EOF not supported." << std::endl << "|" << std::endl << std::endl;
                exit(1);
            }
            if (toret.length() == 0)
                std::cout << "|Empty field not allowed." << std::endl;
            return (toret);
        };

        void        displayLimited(const std::string fieldContent) {
            std::string temp = fieldContent;

            if (temp.length() > 10)
            {
                temp.resize(9);
                std::cout << temp << ".";
            } else {
                for (int n = temp.length(); n < 10; n ++)
                    std::cout << " ";
                std::cout << temp;
            }
            std::cout << "|";
        };

        void        displayFound(const Contact fieldContent) {
            std::cout << "|------- NAME ------->" << fieldContent.name << std::endl;
            std::cout << "|----- LAST NAME ---->" << fieldContent.lastName << std::endl;
            std::cout << "|----- NICKNAME ----->" << fieldContent.nickName << std::endl;
            std::cout << "|--- PHONE NUMBER --->" << fieldContent.phoneNumber << std::endl;
        };


        std::string toStr(const int index) {
            if (index == 1)
                return ("1");
            else if (index == 2)
                return ("2");
            else if (index == 3)
                return ("3");
            else if (index == 4)
                return ("4");
            else if (index == 5)
                return ("5");
            else if (index == 6)
                return ("6");
            else if (index == 7)
                return ("7");
            else if (index == 8)
                return ("8");
            else
                return ("");
        };

        int toNbr(const std::string index) {
            if (index == "1")
                return (1);
            else if (index == "2")
                return (2);
            else if (index == "3")
                return (3);
            else if (index == "4")
                return (4);
            else if (index == "5")
                return (5);
            else if (index == "6")
                return (6);
            else if (index == "7")
                return (7);
            else if (index == "8")
                return (8);
            else
                return (0);
        };
};

#endif