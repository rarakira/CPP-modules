#include <iostream>
#include <iomanip>
#include <vector>
#include "Span.hpp"

void print_status(std::string const msg) {
	std::cout	<< std::endl
				<< std::left << std::setw(40) << std::setfill('-')
				<< msg << std::endl;
}

int main(void) {
	{
		print_status("--- 10 000 elem ");
		unsigned int size = 10000;
		Span A(size);

		for (unsigned int i = 0; i <= size; i++) {
			try {
				A.addNumber(std::rand());
			}
			catch(const std::exception& e) {
				std::cerr << COLOUR_RED << ">> Exception caught: " << e.what() << COLOUR_FIN << '\n';
			}
		}

		print_status("--- Shortest span ");
		try {
			int span = A.shortestSpan();
			std::cout << span << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << COLOUR_RED << ">> Exception caught: " << e.what() << COLOUR_FIN << '\n';
		}

		print_status("--- Longest span ");
		try {
			int span = A.longestSpan();
			std::cout << span << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << COLOUR_RED << ">> Exception caught: " << e.what() << COLOUR_FIN << '\n';
		}
	}
	{
		print_status("--- 10 elem ");
		unsigned int size = 10;
		Span A(size);

		for (unsigned int i = 0; i <= size; i++) {
			try {
				A.addNumber(std::rand());
			}
			catch(const std::exception& e) {
				std::cerr << COLOUR_RED << ">> Exception caught: " << e.what() << COLOUR_FIN << '\n';
			}
		}
		print_status("--- Shortest span ");
		try {
			int span = A.shortestSpan();
			std::cout << span << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << COLOUR_RED << ">> Exception caught: " << e.what() << COLOUR_FIN << '\n';
		}

		print_status("--- Longest span ");
		try {
			int span = A.longestSpan();
			std::cout << span << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << COLOUR_RED << ">> Exception caught: " << e.what() << COLOUR_FIN << '\n';
		}
	}
	{
		print_status("--- Test from the Subject ");
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		print_status("--- Test addRange() ");
		Span				sp = Span(5);
		std::vector<int>	vals;

		print_status("--- Add empty range ");
		try {
			sp.addRange(vals.begin(), vals.end());
		}
		catch(const std::exception& e) {
			std::cerr << COLOUR_RED << ">> Exception caught: " << e.what() << COLOUR_FIN << '\n';
		}
		std::cout << sp << std::endl;

		for (size_t i = 0; i < 5; i++) {
			vals.push_back(i * 10);
		}
		print_status("--- Add range of 5 ");
		try {
			sp.addRange(vals.begin(), vals.end());
		}
		catch(const std::exception& e) {
			std::cerr << COLOUR_RED << ">> Exception caught: " << e.what() << COLOUR_FIN << '\n';
		}
		std::cout << sp << std::endl;

		for (size_t i = 5; i > 0; i--) {
			vals.push_back(i * -10);
		}
		print_status("--- Add range of 10 ");
		try {
			sp.addRange(vals.begin(), vals.end());
		}
		catch(const std::exception& e) {
			std::cerr << COLOUR_RED << ">> Exception caught: " << e.what() << COLOUR_FIN << '\n';
		}
		std::cout << sp << std::endl;
	}
	return 0;
}
