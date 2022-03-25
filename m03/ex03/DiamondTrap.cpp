#include <iostream>

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap ( void )

{
	std::cout	<< COLOUR_NEW
				<< "DiamondTrap default constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}


DiamondTrap::DiamondTrap ( std::string const name ) : _name(name)
{
	ClapTrap::_name = name + "_clap_name";
	this->_hitPts = FragTrap::_hitPtsPreset;
	this->_energyPts = ScavTrap::_energyPtsPreset;
	this->_attackDmg = FragTrap::_attackDmgPreset;
	std::cout	<< COLOUR_NEW
				<< "DiamondTrap constructor called for " << this->_name
				<< COLOUR_FIN
				<< std::endl;
	return;
}

DiamondTrap::DiamondTrap ( DiamondTrap const & inst )
{
	this->_name = inst.getName();
	this->_hitPts = inst.getHitPts();
	this->_energyPts = inst.getEnergyPts();
	this->_attackDmg = inst.getDmg();
	std::cout	<< COLOUR_NEW
				<< "DiamondTrap copy constructor called for " << this->_name
				<< COLOUR_FIN
				<< std::endl;
	return;
}

DiamondTrap::~DiamondTrap ( void )
{
	std::cout	<< COLOUR_DELETE
				<< "DiamondTrap destructor called for " << this->_name
				<< COLOUR_FIN
				<< std::endl;
	return;
}

void DiamondTrap::whoAmI( void )
{
	std::cout	<< COLOUR_GATE
				<< "I am the [" << this->_name
				<< "] aka "
				<< this->ClapTrap::_name
				<< std::endl;
	std::cout	<< "Hit points: " << this->_hitPts << std::endl
				<< "Energy points: " << this->_energyPts << std::endl
				<< "Attack damage: " << this->_attackDmg
				<< COLOUR_FIN
				<< std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}
