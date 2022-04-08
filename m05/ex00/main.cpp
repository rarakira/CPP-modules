#include <iostream>
#include <iomanip>

#include "Bureaucrat.hpp"

void print_status(std::string const msg) {
	std::cout	<< std::endl
				<< std::left << std::setw(40) << std::setfill('-')
				<< msg << std::endl;
}

int main(void) {
	{
		print_status("--- TEST 1: grade 200 ");
		try {
			Bureaucrat	bill("Bill", 200);
		}
		catch(const std::exception& e) {
			std::cerr << "CAUGHT EXCEPTION: " << e.what() << '\n';
		}
	}
	{
		print_status("--- TEST 2: increment by 140 ");
		Bureaucrat	bill("Bill", 100);
		Bureaucrat	paul("Paul", 100);

		std::cout << bill << std::endl;
		std::cout << paul << std::endl;
		try {
			bill.decrementGrade(30);
			paul.incrementGrade(40);
			bill.incrementGrade(140);
		}
		catch(const std::exception& e) {
			std::cerr << "CAUGHT EXCEPTION: " << e.what() << '\n';
		}
	}
	{
		print_status("--- TEST 2: decrement -30 ");
		Bureaucrat	bill("Bill", 10);
		Bureaucrat  paul = bill;

		std::cout << bill << std::endl;
		try {
			paul.incrementGrade(5);
			bill.decrementGrade(-30);
		}
		catch(const std::exception& e) {
			std::cerr << "CAUGHT EXCEPTION: " << e.what() << '\n';
		}
	}
	return 0;
}
