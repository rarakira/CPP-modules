#include <iostream>

#include "Point.hpp"

Point::Point ( void ) : _x(0), _y(0)
{
	std::cout	<< COLOUR_NEW
				<< "Default constructor called " << *this
				<< COLOUR_FIN
				<< std::endl;
	return;
}

Point::Point ( float const x, float const y ) : _x(x), _y(y)
{
	
	std::cout	<< COLOUR_NEW
				<< "Float constructor called " << *this
				<< COLOUR_FIN
				<< std::endl;
	return;
}

Point::Point ( Fixed const x, Fixed const y ) : _x(x), _y(y)
{
	
	std::cout	<< COLOUR_NEW
				<< "Fixed constructor called " << *this
				<< COLOUR_FIN
				<< std::endl;
	return;
}

Point::Point ( Point const & copy ) : _x(copy.getX()), _y(copy.getY())
{
	std::cout	<< COLOUR_NEW
				<< "Copy constructor called " << *this
				<< COLOUR_FIN
				<< std::endl;
	return;
}

Point::~Point ( void )
{
	std::cout	<< COLOUR_DELETE
				<< "Destructor called " << *this
				<< COLOUR_FIN
				<< std::endl;
	return;
}

std::ostream & operator<<( std::ostream & o, Point const & rhs )
{
	o << "P(" << rhs.getX() << "," << rhs.getY() << ")";
	return o;
}

Point & Point::operator=( Point & src )
{
	std::cout	<< COLOUR_MAIN
				<< "Assignation operator called"
				<< COLOUR_FIN
				<< std::endl;
	return ( src );
}

Fixed Point::getX( void ) const
{
	return (this->_x);
}

Fixed Point::getY( void ) const
{
	return (this->_y);
}
