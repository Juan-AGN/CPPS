#include <iostream>
#include <ctime>
#include <cstdlib>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base * generate(void)
{
	srand((unsigned)time(NULL));

	switch (rand() % 3)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
	}
	return (NULL);
}

void identify(Base* p)
{
	A *casea = dynamic_cast<A*>(p);
	B *caseb = dynamic_cast<B*>(p);
	C *casec = dynamic_cast<C*>(p);

	if (casea)
		std::cout << "A" << std::endl;
	else if (caseb)
		std::cout << "B" << std::endl;
	else if (casec)
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		Base &checkerone = dynamic_cast<A&>(p);
		(void) checkerone;
		std::cout << "A" << std::endl;
	}
	catch (std::exception &error)
	{
		try
		{
			Base &checkertwo = dynamic_cast<B&>(p);
			(void) checkertwo;
			std::cout << "B" << std::endl;
		}
		catch (std::exception &error)
		{
			try
			{
				Base &checkertree = dynamic_cast<C&>(p);
				(void) checkertree;
				std::cout << "C" << std::endl;
			}
			catch (std::exception &error)
			{
				return ;
			}
		}	
	}
}


int main()
{
	Base *toid = generate();

	identify(toid);
	identify(*toid);
	delete (toid);
	return (0);
}