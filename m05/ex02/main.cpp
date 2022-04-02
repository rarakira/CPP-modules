#include <iostream>
#include <iomanip>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

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
		try
		{
			Bureaucrat	bill("Bill", 100);
			Bureaucrat	paul("Paul", 150);
			ShrubberyCreationForm		argeement1("Home");
			ShrubberyCreationForm		argeement2("Jack's Flat");

			std::cout << bill << std::endl;
			std::cout << paul << std::endl;
			std::cout << argeement1 << std::endl;
			std::cout << argeement2 << std::endl;

			std::cout << std::endl << "- Bill recieved Agreement 1:" << std::endl;
			bill.signForm(argeement1);
			std::cout << std::endl << "- Paul recieved Agreement 2:" << std::endl;
			paul.signForm(argeement2);
			std::cout << std::endl << "- Paul to execute Agreement 2:" << std::endl;
			paul.executeForm(argeement2);
		}
		catch(const std::exception& e)
		{
			std::cerr << "(main) CAUGHT EXCEPTION: " << e.what() << '\n';
		}
	}
	{
		print_status("--- TEST 2 ");
		try
		{
			Bureaucrat	bill("Bill", 100);
			Bureaucrat	paul("Paul", 150);
			ShrubberyCreationForm		argeement1("Here");

			std::cout << bill << std::endl;
			std::cout << paul << std::endl;
			std::cout << argeement1 << std::endl;

			std::cout << std::endl << "- Bill recieved Agreement 1:" << std::endl;
			bill.signForm(argeement1);
			std::cout << std::endl << "- Paul to execute Agreement 2:" << std::endl;
			paul.executeForm(argeement1);
		}
		catch(const std::exception& e)
		{
			std::cerr << "(main) CAUGHT EXCEPTION: " << e.what() << '\n';
		}
	}
	{
		print_status("--- TEST 3 ");
		try
		{
			Bureaucrat	bill("Bill", 100);
			Bureaucrat	paul("Paul", 140);
			ShrubberyCreationForm		argeement1("Here");

			std::cout << bill << std::endl;
			std::cout << paul << std::endl;
			std::cout << argeement1 << std::endl;

			std::cout << std::endl << "- Bill recieved Agreement 1:" << std::endl;
			bill.signForm(argeement1);
			std::cout << std::endl << "- Paul to execute Agreement 2:" << std::endl;
			paul.executeForm(argeement1);
		}
		catch(const std::exception& e)
		{
			std::cerr << "(main) CAUGHT EXCEPTION: " << e.what() << '\n';
		}
	}
	return 0;
}
