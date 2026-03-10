#include <iostream>
#include <vector>
#include <map>
#include <list>

#include "easyfind.hpp"


int main()
{
	std::vector<int> vcontainer(5, 6);
	vcontainer.push_back(8);
	vcontainer.push_back(9);

	std::cout << "--Vector test--" << std::endl;
	try
	{
		std::cout << *(easyfind(vcontainer, 8)) << std::endl;
	}
	catch (std::exception &error)
	{
		std::cout << error.what() << std::endl;
	}

	try
	{
		std::cout << *(easyfind(vcontainer, 9)) << std::endl;
	}
	catch (std::exception &error)
	{
		std::cout << error.what() << std::endl;
	}

	try
	{
		std::cout << (easyfind(vcontainer, 10))[0] << std::endl;
	}
	catch (std::exception &error)
	{
		std::cout << error.what() << std::endl;
	}

	std::cout << "--list test--" << std::endl;
	std::list<int> lcontainer;
	lcontainer.assign(4,2);
	lcontainer.push_back(4);
	lcontainer.push_back(60);
	lcontainer.push_back(6);

	try
	{
		std::cout << *(easyfind(lcontainer, 4)) << std::endl;
	}
	catch (std::exception &error)
	{
		std::cout << error.what() << std::endl;
	}

	try
	{
		std::cout << *(easyfind(lcontainer, 6)) << std::endl;
	}
	catch (std::exception &error)
	{
		std::cout << error.what() << std::endl;
	}

	try
	{
		std::cout << *(easyfind(lcontainer, 10)) << std::endl;
	}
	catch (std::exception &error)
	{
		std::cout << error.what() << std::endl;
	}

	return (0);
}