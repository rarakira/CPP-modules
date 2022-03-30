#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat")
{
	this->_brain = new Brain();
	std::cout	<< COLOUR_NEW
				<< "Cat DEFAULT constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

Cat::Cat( Cat const & src )
{
	this->_type = src.getType();
	this->_brain = new Brain(src.getBrain());
	std::cout	<< COLOUR_NEW
				<< "Cat COPY constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

Cat & Cat::operator=( Cat const & rhs )
{
	this->_type = rhs.getType();
	this->_brain = rhs.getBrain();
	return *this;
}

Cat::~Cat( void )
{
	std::cout	<< COLOUR_DELETE
				<< "Cat destructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

void Cat::makeSound( void ) const
{
	std::cout	<< COLOUR_YELL
				<< "** PURRRRRRRRRR **"
				<< COLOUR_FIN
				<< std::endl;
	return;
}
