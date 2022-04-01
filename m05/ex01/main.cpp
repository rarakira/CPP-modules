#include <iostream>
#include <iomanip>

#include "Bureaucrat.hpp"
#include "Form.hpp"

void print_status( std::string const msg)
{
	std::cout	<< std::endl
				<< std::left << std::setw(40) << std::setfill('-')
				<< msg << std::endl;
}

int main( void )
{
	{
		print_status("--- TEST 1 ");
		Bureaucrat	bill("Bill", 100);
		Bureaucrat	paul("Paul", 50);
		Form		argeement1("Agreement 1", 100, 110);
		Form		argeement2("Agreement 2", 50, 100);
		Form		argeement3("Agreement 3", 1, 50);

		std::cout << bill << std::endl;
		std::cout << paul << std::endl;
		std::cout << argeement1 << std::endl;
		std::cout << argeement2 << std::endl;
		std::cout << argeement3 << std::endl;
		try
		{
			std::cout << std::endl << "Bill recieved Agreement 1:" << std::endl;
			bill.signForm(argeement1);
			std::cout << std::endl << "Paul recieved Agreement 1:" << std::endl;
			paul.signForm(argeement1);
			std::cout << std::endl << "Bill recieved Agreement 2:" << std::endl;
			bill.signForm(argeement2);
			std::cout << std::endl << "Paul recieved Agreement 2:" << std::endl;
			paul.signForm(argeement2);
			std::cout << std::endl << "Paul recieved Agreement 3:" << std::endl;
			paul.signForm(argeement3);
		}
		catch(const std::exception& e)
		{
			std::cerr << "CAUGHT EXCEPTION: " << e.what() << '\n';
		}
	}
	return 0;
}
