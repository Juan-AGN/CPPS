#include <iostream>
#include <ctime>
#include <list>
#include <stack>

#include "MutantStack.hpp"

int main()
{
	std::cout << "- MutantStack -" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "- list -" << std::endl;
	std::list<int> nlist;
	nlist.push_back(5);
	nlist.push_back(17);
	std::cout << *nlist.begin() << std::endl;
	nlist.pop_front();
	std::cout << nlist.size() << std::endl;
	nlist.push_back(3);
	nlist.push_back(5);
	nlist.push_back(737);
	nlist.push_back(0);
	std::list<int>::iterator itl = nlist.begin();
	std::list<int>::iterator itle = nlist.end();
	++itl;
	--itl;
	while (itl != itle)
	{
	    std::cout << *itl << std::endl;
	    ++itl;
	}
	std::cout << "- MutantStack again-" << std::endl;
	MutantStack<int> mstack;
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
	mstack.push(4);
	mstack.push(5);
	mstack.push(6);
	MutantStack<int>::iterator it2 = mstack.begin();
	MutantStack<int>::iterator ite2 = mstack.end();
	std::cout << *it2 << std::endl;
	++it2;
	std::cout << *it2 << std::endl;
	--it2;
	std::cout << *it2 << std::endl;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
}