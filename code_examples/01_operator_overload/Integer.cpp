#include "Integer.hpp"

Integer::Integer( int const n ) : _n(n)
{
		std::cout << "Integer created"<< std::endl;
}

Integer::~Integer( void )
{
		std::cout << "Integer destroyed"<< std::endl;
}

int Integer::getValue( void ) const
{
		return this->_n;
}

Integer & Integer::operator=( Integer const & rhs )
{
		std::cout << "Assignation operator called from " << this->_n;
		std::cout << " to " << rhs.getValue() << std::endl;

		this->_n = rhs.getValue();
		return *this;
}

Integer   Integer::operator+( Integer const & rhs ) const
{
		std::cout << "Assignation operator called from " << this->_n;
		std::cout << " and " << rhs.getValue() << std::endl;

		return Integer( this->_n + rhs.getValue() );
}

std::ostream & operator<<( std::ostream & o, Integer const & rhs )
{
		o << rhs.getValue();return o;
}
