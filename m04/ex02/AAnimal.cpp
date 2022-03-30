#include "AAnimal.hpp"

AAnimal::~AAnimal( void )
{
	std::cout	<< COLOUR_DELETE
				<< "AAnimal destructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}

std::string const & AAnimal::getType( void ) const
{
	return this->_type;
}
