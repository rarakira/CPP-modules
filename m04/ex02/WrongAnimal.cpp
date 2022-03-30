#include "WrongAnimal.hpp"
#include "AAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type("WrongAnimal")
{
	std::cout	<< COLOUR_NEW
				<< "WrongAnimal DEFAULT constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

WrongAnimal::WrongAnimal( std::string const & type ) : _type(type)
{
	std::cout	<< COLOUR_NEW
				<< "WrongAnimal constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

WrongAnimal::WrongAnimal( WrongAnimal const & src )
{
	this->_type = src.getType();
	std::cout	<< COLOUR_NEW
				<< "WrongAnimal COPY constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

WrongAnimal & WrongAnimal::operator=( WrongAnimal const & rhs )
{
	this->_type = rhs.getType();
	return *this;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout	<< COLOUR_DELETE
				<< "WrongAnimal destructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

void WrongAnimal::makeSound( void ) const
{
	std::cout	<< COLOUR_YELL
				<< "** WRONG ROAR! **"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

std::string const & WrongAnimal::getType( void ) const
{
	return this->_type;
}