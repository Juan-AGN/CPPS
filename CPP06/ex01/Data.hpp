#ifndef DATA_HPP
# define DATA_HPP

class  Data {
    public:
        Data();
        ~Data();
        Data(int number);
        Data(const Data &toCopy);
        Data &operator=(const Data &toCopy);

        int getNumber() const;

    private:

        int _magicNumber;

};


#endif