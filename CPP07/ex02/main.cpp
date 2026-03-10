#include "Array.hpp"
# include <ctime>
# include <cstdlib>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
	std::cout << "::";
    for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << numbers[i] << "::";
    }
	std::cout << std::endl;

	Array<std::string> test(4);

	test[0] = "a";
	test[1] = "b";
	test[2] = "c";
	test[3] = "d";
	std::cout << test[0] << test[1] << test[2] << test[3] << std::endl;

	Array<std::string> test2(test);

	std::cout << test2[0] << test2[1] << test2[2] << test2[3] << std::endl;
    return 0;
}