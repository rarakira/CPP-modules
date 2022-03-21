#include <iostream>
#include <cmath>

#include "Fixed.hpp"

// const int Fixed::_fractBits = 8;

Fixed::Fixed ( void ) : _num( 0 )
{
	std::cout	<< COLOUR_NEW
				<< "Default constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

Fixed::Fixed ( int const n ) : _num( n )
{
	this->setRawBits(n * (float)(1 << Fixed::_fractBits));
	std::cout	<< COLOUR_NEW
				<< "Int constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

Fixed::Fixed ( float const n ) : _num( n )
{
	this->setRawBits(roundf(n * (float)(1 << Fixed::_fractBits)));
	std::cout	<< COLOUR_NEW
				<< "Float constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

Fixed::Fixed ( Fixed const & inst )
{
	this->_num = inst.getRawBits();
	std::cout	<< COLOUR_NEW
				<< "Copy constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

Fixed::~Fixed ( void )
{
	std::cout	<< COLOUR_DELETE
				<< "Destructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

int Fixed::getRawBits( void ) const
{
	return this->_num;
}

void Fixed::setRawBits( int const raw )
{
	this->_num = raw;
}

std::ostream & operator<<( std::ostream & o, Fixed const & rhs )
{
	o << rhs.toFloat();
	return o;
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

float Fixed::toFloat( void ) const
{
	return (this->getRawBits() / (float)(1 << Fixed::_fractBits));
}

int Fixed::toInt( void ) const
{
	return (this->getRawBits() >> Fixed::_fractBits);
}