#include <iostream>

#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA( std::string const name, Weapon& weapontype ) : _name(name), _weapon(weapontype)
{
	std::cout	<< COLOUR_NEW
				<< "HumanA constructor called: " << this->_name
				<< COLOUR_FIN
				<< std::endl;
	return;
}

HumanA::~HumanA( void )
{
	std::cout	<< COLOUR_DELETE
				<< "HumanA dectructor called: " << this->_name
				<< COLOUR_FIN
				<< std::endl;
	return;
}

void HumanA::attack( void )
{
	std::cout	<< COLOUR_FIRE
				<< this->_name
				<< " attacks with their "
				<< this->_weapon.getType()
				<< COLOUR_FIN
				<< std::endl;
}
