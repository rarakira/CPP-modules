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


DiamondTrap::DiamondTrap ( std::string const name ) : _name(name), ClapTrap::_name(name + "_clap_name")
{
	// this->_hitPts = 100;
	// this->_energyPts = 50;
	// this->_attackDmg = 20;
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

void DiamondTrap::attack( const std::string& target )
{
	if (this->getHitPts() == 0)
		return this->cantAttack( target );
	this->_hitPts--;
	std::cout	<< COLOUR_ATTACK
				<< "DiamondTrap ["
				<< this->_name
				<< "] attacks ["
				<< target
				<< "], causing "
				<< this->_attackDmg
				<< " points of damage!"
				<< COLOUR_FIN
				<< std::endl;
}