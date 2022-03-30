#include "AAnimal.hpp"

AAnimal::AAnimal( void ) : _type("AAnimal")
{
	std::cout	<< COLOUR_NEW
				<< "AAnimal DEFAULT constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

AAnimal::AAnimal( std::string const & type ) : _type(type)
{
	std::cout	<< COLOUR_NEW
				<< "AAnimal constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

AAnimal::AAnimal( AAnimal const & src )
{
	this->_type = src.getType();
	std::cout	<< COLOUR_NEW
				<< "AAnimal COPY constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

AAnimal & AAnimal::operator=( AAnimal const & rhs )
{
	this->_type = rhs.getType();
	return *this;
}

AAnimal::~AAnimal( void )
{
	std::cout	<< COLOUR_DELETE
				<< "AAnimal destructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

void AAnimal::makeSound( void ) const
{
	std::cout	<< COLOUR_YELL
				<< "** NEUTRAL ROAR! **"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

std::string const & AAnimal::getType( void ) const
{
	return this->_type;
}

Brain* AAnimal::getBrain( void ) const
{
	return this->_brain;
}
