#include <iostream>

#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB( std::string const name ) : _name(name), _weapon(NULL)
{
	std::cout	<< COLOUR_NEW
				<< "HumanB constructor called: " << this->_name
				<< COLOUR_FIN
				<< std::endl;
	return;
}

HumanB::~HumanB( void )
{
	std::cout	<< COLOUR_DELETE
				<< "HumanB dectructor called: " << this->_name
				<< COLOUR_FIN
				<< std::endl;
	return;
}

void HumanB::attack( void )
{
	if (this->_weapon == NULL)
		return ;
	std::cout	<< COLOUR_FIRE
				<< this->_name
				<< " attacks with their "
				<< this->_weapon->getType()
				<< COLOUR_FIN
				<< std::endl;
}

void HumanB::setWeapon( Weapon& type )
{
	this->_weapon = &type;
}
