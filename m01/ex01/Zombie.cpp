#include "Zombie.hpp"

Zombie::Zombie( void ) : _name("default")
{
	std::cout	<< COLOUR_NEW
				<< "Zombie constructed: " << this->_name
				<< COLOUR_FIN
				<< std::endl;
	return;
}

Zombie::Zombie(  std::string const name  ) : _name(name)
{
	std::cout	<< COLOUR_NEW
				<< "Zombie constructed: " << this->_name
				<< COLOUR_FIN
				<< std::endl;
	return;
}

Zombie::~Zombie( void )
{
	std::cout	<< COLOUR_DELETE
				<< "Zombie dectructor called: " << this->_name
				<< COLOUR_FIN
				<< std::endl;
	return;
}

std::string Zombie::getName( void ) const
{
	return this->_name;
}

void Zombie::setName( std::string const name )
{
	this->_name = name;
}

void Zombie::announce( void )
{
	std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
