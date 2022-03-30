#include "WrongCat.hpp"
#include "AAnimal.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat")
{
	std::cout	<< COLOUR_NEW
				<< "WrongCat DEFAULT constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

WrongCat::WrongCat( WrongCat const & src )
{
	this->_type = src.getType();
	std::cout	<< COLOUR_NEW
				<< "WrongCat COPY constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

WrongCat & WrongCat::operator=( WrongCat const & rhs )
{
	this->_type = rhs.getType();
	return *this;
}

WrongCat::~WrongCat( void )
{
	std::cout	<< COLOUR_DELETE
				<< "WrongCat destructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

void WrongCat::makeSound( void ) const
{
	std::cout	<< COLOUR_YELL
				<< "** PURRRRRRRRRR **"
				<< COLOUR_FIN
				<< std::endl;
	return;
}
