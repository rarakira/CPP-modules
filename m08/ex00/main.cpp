#include <iostream>
#include <iomanip>
#include <vector>
#include "easyfind.hpp"

void print_status(std::string const msg) {
	std::cout	<< std::endl
				<< std::left << std::setw(40) << std::setfill('-')
				<< msg << std::endl;
}

int main(void) {
	{
		print_status("--- Create the array ");
		std::vector<int>					a;
		std::vector<int>::const_iterator	ptr;

		try {
			ptr = easyfind(a, 21);
			std::cout << *ptr << " is found" << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << COLOUR_RED  << ">> Exception caught: " << e.what() << COLOUR_FIN << '\n';
		}
		print_status("--- Fill the array ");
		for (size_t i = 0; i < 22; i++) {
			a.push_back(i);
			std::cout << a[i] << " ";
		}
		std::cout << std::endl;

		print_status("--- Find 21 ");
		try {
			ptr = easyfind(a, 21);
			std::cout << *ptr << " is found" << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << COLOUR_RED << ">> Exception caught: " << e.what() << COLOUR_FIN << '\n';
		}

		print_status("--- Find -42 ");
		try {
			ptr = easyfind(a, -42);
			std::cout << *ptr << " is found" << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << COLOUR_RED << ">> Exception caught: " << e.what() << COLOUR_FIN << '\n';
		}
	}
	return 0;
}
