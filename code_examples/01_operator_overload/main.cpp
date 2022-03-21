#include <iostream>

#include "Integer.hpp"

int main( void )
{
	Integer		a( 1 );
	Integer		b( 21 );
	Integer		c( 42 );

	std::cout << "a = " << a.getValue() << std::endl;
	std::cout << "b = " << b.getValue() << std::endl;
	std::cout << "c = " << c.getValue() << std::endl;

	a = Integer ( 12 );
	std::cout << "a = " << a.getValue() << std::endl;

	a = b + b;
	std::cout << "a = " << a.getValue() << std::endl;

	return 0;
}
