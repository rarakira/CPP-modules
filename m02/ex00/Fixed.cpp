#include <iostream>

#include "Fixed.hpp"

const int Fixed::_fractBits = 8;

Fixed::Fixed ( void ) : _num( 0 )
{
	std::cout	<< COLOUR_NEW
				<< "Fixed default constructor called num = " << this->_num
				<< COLOUR_FIN
				<< std::endl;
	return;
}

Fixed::Fixed ( int const n ) : _num( n )
{
	this->setRawBits(n * (float)(1 << Fixed::_fractBits));
	std::cout	<< COLOUR_NEW
				<< "Fixed constructor called num = " << this->_num
				<< COLOUR_FIN
				<< std::endl;
	return;
}

Fixed::Fixed ( Fixed const & inst )
{
	this->_num = inst.getRawBits();
	std::cout	<< COLOUR_NEW
				<< "Fixed copy constructor called num = " << this->_num
				<< COLOUR_FIN
				<< std::endl;
	return;
}

Fixed::~Fixed ( void )
{
	std::cout	<< COLOUR_DELETE
				<< "Fixed destructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

Fixed & Fixed::operator=( Fixed const & rhs )
{
	std::cout	<< COLOUR_MAIN
				<< "Assignation operator called"
				<< COLOUR_FIN
				<< std::endl;

	this->_num = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const
{
	std::cout	<< COLOUR_MAIN
				<< "getRawBits member function called"
				<< COLOUR_FIN
				<< std::endl;
	return this->_num;
}

void Fixed::setRawBits( int const raw )
{
	this->_num = raw;
}
