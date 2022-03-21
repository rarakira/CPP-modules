#include <iostream>
#include <iomanip>

#include "Fixed.hpp"
#include "Point.hpp"

void print_status( std::string const msg)
{
	std::cout	<< std::endl
				<< std::left << std::setw(40) << std::setfill('-')
				<< msg << std::endl;
}

int main( void )
{
	{
		print_status("--- TEST 1 :: INSIDE ");
		Point			a(Fixed(0), Fixed(5));
		Point 			b(Fixed(-5), Fixed(-5));
		Point			c(Fixed(5), Fixed(-5));
		Point			d;

		std::cout	<< "A is " << a << std::endl
					<< "B is " << b << std::endl
					<< "C is " << c << std::endl
					<< "D is " << d << std::endl;

		if (bsp(a, b, c, d))
			std::cout	<< COLOUR_MAIN
				<< "D is in the area of ABC"
				<< COLOUR_FIN
				<< std::endl;
		else
			std::cout	<< COLOUR_MAIN
				<< "D is outside the area of ABC"
				<< COLOUR_FIN
				<< std::endl;
	}
	{
		print_status("--- TEST 2 :: OUTSIDE ");
		Point			a(Fixed(0), Fixed(5));
		Point 			b(Fixed(-5), Fixed(-5));
		Point			c(Fixed(5), Fixed(-5));
		Point			d(Fixed(0), Fixed(7));

		std::cout	<< "A is " << a << std::endl
					<< "B is " << b << std::endl
					<< "C is " << c << std::endl
					<< "D is " << d << std::endl;

		if (bsp(a, b, c, d))
			std::cout	<< COLOUR_MAIN
				<< "D is in the area of ABC"
				<< COLOUR_FIN
				<< std::endl;
		else
			std::cout	<< COLOUR_MAIN
				<< "D is outside the area of ABC"
				<< COLOUR_FIN
				<< std::endl;
	}
	{
		print_status("--- TEST 3 :: D = C ");
		Point			a(Fixed(0), Fixed(5));
		Point 			b(Fixed(-5), Fixed(-5));
		Point			c(Fixed(5), Fixed(-5));
		Point			d = c;

		std::cout	<< "A is " << a << std::endl
					<< "B is " << b << std::endl
					<< "C is " << c << std::endl
					<< "D is " << d << std::endl;

		if (bsp(a, b, c, d))
			std::cout	<< COLOUR_MAIN
				<< "D is in the area of ABC"
				<< COLOUR_FIN
				<< std::endl;
		else
			std::cout	<< COLOUR_MAIN
				<< "D is outside the area of ABC"
				<< COLOUR_FIN
				<< std::endl;
	}
	return 0;
}