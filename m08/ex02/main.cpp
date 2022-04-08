#include <iostream>
#include <iomanip>
#include <list>
#include "MutantStack.hpp"
// #include "MutantStack.tpp"

void print_status(std::string const msg) {
	std::cout	<< std::endl
				<< std::left << std::setw(40) << std::setfill('-')
				<< msg << std::endl;
}

int main(void) {
	{
		print_status("--- MutantStack ");
		MutantStack<int>	mstack;
		mstack.push(5);
		mstack.push(17);
		// 5, 7
		std::cout << "mstack.top() " << mstack.top() << std::endl;
		mstack.pop();
		// 5
		std::cout << "mstack.size() " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		// 5, 3, 5, 737, 0
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		std::cout << "Iterater Incremented: " << *it << std::endl;
		--it;
		std::cout << "Iterater Decremented: " << *it << std::endl;
		int i = 1;
		while (it != ite)
		{
			std::cout << i++ << ": " << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		print_status("--- std::list ");
		std::list<int>	lstTest;
		lstTest.push_back(5);
		lstTest.push_back(17);
		// 5, 17
		std::cout << "lstTest.back() " << lstTest.back() << std::endl;
		// std::cout << "lstTest.front() " << lstTest.front() << std::endl;
		lstTest.pop_back();
		// 5
		std::cout << "lstTest.size() " << lstTest.size() << std::endl;
		lstTest.push_back(3);
		lstTest.push_back(5);
		lstTest.push_back(737);
		//[...]
		lstTest.push_back(0);
		// 5, 3, 5, 737, 0
		std::list<int>::iterator it = lstTest.begin();
		std::list<int>::iterator ite = lstTest.end();
		++it;
		std::cout << "Iterater Incremented: " << *it << std::endl;
		--it;
		std::cout << "Iterater Decremented: " << *it << std::endl;
		int i = 1;
		while (it != ite)
		{
			std::cout << i++ << ": " << *it << std::endl;
			++it;
		}
		std::list<int> s(lstTest);
	}
	return 0;
}
