#include <iostream>
#include <ctime>

#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span sp2 = Span(15000);
	sp2.insert(15000, 0);
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;

	std::vector<int> tvector;
	srand((unsigned)time(NULL));
	int a = rand() % 50 + 1;   
	Span sp3 = Span(a);
	for (int i = 0; i < a; i++){
        int b = rand() % (a * 10) + 1;
        tvector.push_back(b);
    }

	try
	{
		sp3.insertRange(tvector.begin(), tvector.end());
		std::cout << sp3.shortestSpan() << std::endl;
		std::cout << sp3.longestSpan() << std::endl;
	}
	catch (std::exception &error)
	{
		std::cout << error.what() << std::endl;
	}
	
	return 0;
}