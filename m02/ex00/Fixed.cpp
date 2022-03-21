#include "Fixed.hpp"

const int Fixed::_fractBits = 8;

Fixed::Fixed ( void ) : _num( 0 )
{}

Fixed::Fixed ( int const n ) : _num( n )
{}

Fixed::Fixed ( Fixed const & inst )
{}

Fixed::~Fixed ( void )
{}

int Fixed::getRawBits( void ) const
{}

void Fixed::setRawBits( int const raw )
{}
