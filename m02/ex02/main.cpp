#include <iostream>
#include <iomanip>

#include "Fixed.hpp"

void print_status( std::string const msg)
{
	std::cout	<< std::endl
				<< std::left << std::setw(40) << std::setfill('-')
				<< msg << std::endl;
}

int main( void )
{
	{
		print_status("--- TEST 1 :: MAIN ");
		Fixed			a;
		Fixed const		b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	{
		print_status("--- TEST 2 :: CMPR ");
		Fixed		a( 42.21f );
		Fixed		b( 42.42f );
		Fixed		c = b;
		if (a < b)
			std::cout << "a is smaller than b" << std::endl;
		if (a > b)
			std::cout << "a is larger than b" << std::endl;
		if (a <= b)
			std::cout << "a is smaller or equal to b" << std::endl;
		if (a >= b)
			std::cout << "a is larger or equal to b" << std::endl;
		if (a == b)
			std::cout << "a is equal to b" << std::endl;
		if (a != b)
			std::cout << "a is not equal to b" << std::endl;
		if (c < b)
			std::cout << "c is smaller than b" << std::endl;
		if (c > b)
			std::cout << "c is larger than b" << std::endl;
		if (c <= b)
			std::cout << "c is smaller or equal to b" << std::endl;
		if (c >= b)
			std::cout << "c is larger or equal to b" << std::endl;
		if (c == b)
			std::cout << "c is equal to b" << std::endl;
		if (c != b)
			std::cout << "c is not equal to b" << std::endl;

	}
	{
		print_status("--- TEST 3 :: MATHS ");
		Fixed	a( 21.21f );
		Fixed	b( 2 );
		Fixed	c = a + b;
		std::cout << "a + b = " << c << std::endl;
		c = a - b;
		std::cout << "a - b = " << c << std::endl;
		c = a * b;
		std::cout << "a * b = " << c << std::endl;
		c = a / b;
		std::cout << "a / b = " << c << std::endl;
	}
	{
		print_status("--- TEST 4 :: MIN MAX ");
		Fixed	a( 21.21f );
		Fixed	b( 21 );
		std::cout << "Max: " << Fixed::max( a, b ) << std::endl;
		std::cout << "Min: " << Fixed::min( a, b ) << std::endl;
		Fixed const	aa( 42.42f );
		Fixed const	bb( 42 );
		std::cout << "Max: " << Fixed::max( aa, bb ) << std::endl;
		std::cout << "Min: " << Fixed::min( aa, bb ) << std::endl;
	}
	return 0;
}