#include <iostream>

#include "Weapon.hpp"

Weapon::Weapon( std::string const type ) : _type(type)
{
	std::cout	<< COLOUR_NEW
				<< "Weapon constructor called: " << this->_type
				<< COLOUR_FIN
				<< std::endl;
	return;
}

Weapon::~Weapon( void )
{
	std::cout	<< COLOUR_DELETE
				<< "Weapon dectructor called: " << this->_type
				<< COLOUR_FIN
				<< std::endl;
	return;
}

std::string const Weapon::getType( void ) const
{
	return this->_type;
}

void Weapon::setType( std::string const type )
{
	this->_type = type;
}
