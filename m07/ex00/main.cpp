#include <iostream>
#include <iomanip>
#include "whatever.hpp"

void print_status(std::string const msg) {
	std::cout	<< std::endl
				<< std::left << std::setw(40) << std::setfill('-')
				<< msg << std::endl;
}

int main(void) {
	{
		print_status("--- Subject ");
		int a = 2;
		int b = 3;

		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	{
		print_status("--- Ints ");
		int		a = 42;
		int		b = 21;

		std::cout	<< "a = " << a << ", b = " << b << std::endl;
		std::cout	<< "min( a, b ) = " << ::min(a, b) << std::endl;
		std::cout	<< "max( a, b ) = " << ::max(a, b) << std::endl;

		::swap<int>(a, b);
		std::cout	<< "After swap: " << std::endl;
		std::cout	<< "a = " << a << ", b = " << b << std::endl;

		std::cout	<< "max( a, b ) = " << ::max(a, b) << std::endl;
	}
	{
		print_status("--- Floats ");
		float		a = 21.42;
		float		b = 42.21;

		std::cout	<< "a = " << a << ", b = " << b << std::endl;
		std::cout	<< "Min: " << ::min(a, b) << std::endl;
		std::cout	<< "Max: " << ::max(a, b) << std::endl;

		::swap(a, b);
		std::cout	<< "After swap: " << std::endl;
		std::cout	<< "a = " << a << ", b = " << b << std::endl;

		std::cout	<< "Max: " << ::max(a, b) << std::endl;
	}
	return 0;
}
