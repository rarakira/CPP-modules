#include "Animal.hpp"

Animal::Animal( void ) : _type("Animal")
{
	std::cout	<< COLOUR_NEW
				<< "Animal DEFAULT constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

Animal::Animal( std::string const & type ) : _type(type)
{
	std::cout	<< COLOUR_NEW
				<< "Animal constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

Animal::Animal( Animal const & src )
{
	this->_type = src.getType();
	std::cout	<< COLOUR_NEW
				<< "Animal COPY constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

Animal & Animal::operator=( Animal const & rhs )
{
	this->_type = rhs.getType();
	return *this;
}

Animal::~Animal( void )
{
	std::cout	<< COLOUR_DELETE
				<< "Animal destructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

void Animal::makeSound( void ) const
{
	std::cout	<< COLOUR_YELL
				<< "** NEUTRAL ROAR! **"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

std::string const & Animal::getType( void ) const
{
	return this->_type;
}

Brain& Animal::getBrain( void ) const
{
	return this->_brain;
}
