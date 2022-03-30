#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog")
{
	this->_brain = new Brain();
	std::cout	<< COLOUR_NEW
				<< "Dog DEFAULT constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

Dog::Dog( Dog const & src )
{
	this->_type = src.getType();
	this->_brain = new Brain(*src.getBrain());
	std::cout	<< COLOUR_NEW
				<< "Dog COPY constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

Dog & Dog::operator=( Dog const & rhs )
{
	this->_type = rhs.getType();
	this->_brain = new Brain(*rhs.getBrain());
	return *this;
}

Dog::~Dog( void )
{
	delete this->_brain;
	std::cout	<< COLOUR_DELETE
				<< "Dog destructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

void Dog::makeSound( void ) const
{
	std::cout	<< COLOUR_YELL
				<< "** WOOF WOOF **"
				<< COLOUR_FIN
				<< std::endl;
	return;
}
