#include <iostream>

#include "Bureaucrat.hpp"


int main()
{
	Bureaucrat daboss("Daboss", 1);
	Bureaucrat daexpendable("Tom", 150);
	Bureaucrat danewboss("Bob", 1);

	std::cout << std::endl;
	std::cout << "-----------------" << std::endl;
	std::cout << std::endl;
	try {
		std::cout << "Daboss test is being created." << std::endl;
		Bureaucrat dabossTest("Daboss", 1);
		std::cout << dabossTest << " is here on time." << std::endl;
		std::cout << "*****************" << std::endl;
	
		std::cout << "Tom test is being created." << std::endl;
		Bureaucrat daexpendableTest("Tom", 150);
		std::cout << daexpendableTest << " is here late." << std::endl;
		std::cout << "*****************" << std::endl;
	
		std::cout << "Jim test is being created." << std::endl;
		Bureaucrat dafired("Jim", 151);
		std::cout << dafired << " is here?." << std::endl;
	}
	catch (std::exception &error)
	{
		std::cout << std::endl << std::endl << "Caught!!" << std::endl;
		std::cout << error.what() << ", why are you here?." << std::endl;
	}

	std::cout << std::endl;
	std::cout << "-----------------" << std::endl;
	std::cout << std::endl;

	try {
		std::cout << daboss << " is being lowered." << std::endl;
		daboss.getLowered();
		std::cout << daboss << " is no longer a boss, now he only has a funny name." << std::endl;
		std::cout << "*****************" << std::endl;

		std::cout << daexpendable << " is being lowered." << std::endl;
		daexpendable.getLowered();
		std::cout << daexpendable << ", what have you done?" << std::endl;
	}
	catch (std::exception &error)
	{
		std::cout << std::endl << std::endl << "Caught!!" << std::endl;
		std::cout << error.what() << ", you have already hit rock bottom!" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "-----------------" << std::endl;
	std::cout << std::endl;

	try {
		std::cout << danewboss << " has taken the lead." << std::endl;
		std::cout << "*****************" << std::endl;

		std::cout << daexpendable << " is being raised." << std::endl;
		daexpendable.getRaise();
		std::cout << daexpendable << ", going up sport!" << std::endl;
		std::cout << "*****************" << std::endl;
	
		std::cout << danewboss << " is being raised." << std::endl;
		danewboss.getRaise();
		std::cout << danewboss << " how are you this up?" << std::endl;
	}
	catch (std::exception &error)
	{
		std::cout << std::endl << std::endl << "Caught!!" << std::endl;
		std::cout << error.what() << ", you can't go above the max grade." << std::endl;
	}

	std::cout << std::endl;
	std::cout << "-----------------" << std::endl;
	std::cout << std::endl;
}