#include <iostream>

#include "ScavTrap.hpp"

ScavTrap::ScavTrap ( void ) : _gateKeeper(false)
{
	std::cout	<< COLOUR_NEW
				<< "ScavTrap default constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}


ScavTrap::ScavTrap ( std::string const name ) : ClapTrap(name), _gateKeeper(false)
{
	this->_hitPts = this->_hitPtsPreset;
	this->_energyPts = this->_energyPtsPreset;
	this->_attackDmg = this->_attackDmgPreset;
	std::cout	<< COLOUR_NEW
				<< "ScavTrap constructor called for " << this->_name
				<< COLOUR_FIN
				<< std::endl;
	return;
}

ScavTrap::ScavTrap ( ScavTrap const & inst )
{
	this->_name = inst.getName();
	this->_hitPts = inst.getHitPts();
	this->_energyPts = inst.getEnergyPts();
	this->_attackDmg = inst.getDmg();
	this->_gateKeeper = inst.isGateKeeper();
	std::cout	<< COLOUR_NEW
				<< "ScavTrap copy constructor called for " << this->_name
				<< COLOUR_FIN
				<< std::endl;
	return;
}

ScavTrap::~ScavTrap ( void )
{
	std::cout	<< COLOUR_DELETE
				<< "ScavTrap destructor called for " << this->_name
				<< COLOUR_FIN
				<< std::endl;
	return;
}

void ScavTrap::guardGate( void )
{
	this->_gateKeeper = true;
	std::cout	<< COLOUR_GATE
				<< "ScavTrap ["
				<< this->_name
				<< "] is in GateKeeper mode!"
				<< COLOUR_FIN
				<< std::endl;
}

void ScavTrap::attack( const std::string& target )
{
	if (this->getHitPts() == 0)
		return this->cantAttack( target );
	this->_hitPts--;
	std::cout	<< COLOUR_ATTACK
				<< "ScavTrap ["
				<< this->_name
				<< "] attacks ["
				<< target
				<< "], causing "
				<< this->_attackDmg
				<< " points of damage!"
				<< COLOUR_FIN
				<< std::endl;
}

bool ScavTrap::isGateKeeper( void ) const
{
	return this->_gateKeeper;
}
