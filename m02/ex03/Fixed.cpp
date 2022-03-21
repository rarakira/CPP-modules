#include <iostream>
#include <cmath>

#include "Fixed.hpp"

Fixed::Fixed ( void ) : _num( 0 )
{
	return;
}

Fixed::Fixed ( int const n ) : _num( n )
{
	this->setRawBits(n * (float)(1 << Fixed::_fractBits));
	return;
}

Fixed::Fixed ( float const n ) : _num( n )
{
	this->setRawBits(roundf(n * (float)(1 << Fixed::_fractBits)));
	return;
}

Fixed::Fixed ( Fixed const & inst )
{
	this->_num = inst.getRawBits();
	return;
}

Fixed::~Fixed ( void )
{
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

/* Comparison operator overload */

bool Fixed::operator>( Fixed const & rhs ) const
{
	return (this->toFloat() > rhs.toFloat());
}

bool Fixed::operator<( Fixed const & rhs ) const
{
	return (this->toFloat() < rhs.toFloat());
}

bool Fixed::operator>=( Fixed const & rhs ) const
{
	return (this->toFloat() >= rhs.toFloat());
}

bool Fixed::operator<=( Fixed const & rhs ) const
{
	return (this->toFloat() <= rhs.toFloat());
}

bool Fixed::operator==( Fixed const & rhs ) const
{
	return (this->toFloat() == rhs.toFloat());
}

bool Fixed::operator!=( Fixed const & rhs ) const
{
	return (this->toFloat() != rhs.toFloat());
}

/* Arithmetic operator overload */
Fixed Fixed::operator+( Fixed const & rhs ) const
{
	Fixed	res(*this);

	res.setRawBits(this->getRawBits() + rhs.getRawBits());
	return res;
}

Fixed Fixed::operator-( Fixed const & rhs ) const
{
	Fixed	res(*this);

	res.setRawBits(this->getRawBits() - rhs.getRawBits());
	return res;
}

Fixed Fixed::operator*( Fixed const & rhs ) const
{
	Fixed	res(*this);

	res.setRawBits((long)this->getRawBits() * (long)rhs.getRawBits() / (float)(1 << this->_fractBits));
	return res;
}

Fixed Fixed::operator/( Fixed const & rhs ) const
{
	Fixed	res(*this);

	res.setRawBits(((long)this->getRawBits() * (float)(1 << this->_fractBits)) / (long)rhs.getRawBits());
	return res;
}

/* increment/decrement operator overload */
Fixed & Fixed::operator++()			// ++a
{
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed Fixed::operator++(int)		// a++
{
	Fixed	copy(*this);
	++(*this);
	return copy;
}

Fixed & Fixed::operator--()			// --b
{
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed Fixed::operator--(int)		// b--
{
	Fixed	copy(*this);
	--(*this);
	return copy;
}

/* min/max member function */
Fixed & Fixed::min( Fixed & first, Fixed & second )
{
	if (first <= second)
		return first;
	return second;
}

Fixed const & Fixed::min( Fixed const & first, Fixed const & second )
{
	if (first <= second)
		return first;
	return second;
}

Fixed & Fixed::max( Fixed & first, Fixed & second )
{
	if (first >= second)
		return first;
	return second;
}

Fixed const & Fixed::max( Fixed const & first, Fixed const & second )
{
	if (first >= second)
		return first;
	return second;
}

