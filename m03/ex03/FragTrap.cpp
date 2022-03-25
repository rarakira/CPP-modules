#include <iostream>

#include "FragTrap.hpp"

FragTrap::FragTrap ( void )
{
	std::cout	<< COLOUR_NEW
				<< "FragTrap default constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}


FragTrap::FragTrap ( std::string const name ) : ClapTrap(name)
{
	this->_hitPts = 100;
	this->_energyPts = 100;
	this->_attackDmg = 30;
	std::cout	<< COLOUR_NEW
				<< "FragTrap constructor called for " << this->_name
				<< COLOUR_FIN
				<< std::endl;
	return;
}

FragTrap::FragTrap ( FragTrap const & inst )
{
	this->_name = inst.getName();
	this->_hitPts = inst.getHitPts();
	this->_energyPts = inst.getEnergyPts();
	this->_attackDmg = inst.getDmg();
	std::cout	<< COLOUR_NEW
				<< "FragTrap copy constructor called for " << this->_name
				<< COLOUR_FIN
				<< std::endl;
	return;
}

FragTrap::~FragTrap ( void )
{
	std::cout	<< COLOUR_DELETE
				<< "FragTrap destructor called for " << this->_name
				<< COLOUR_FIN
				<< std::endl;
	return;
}

void FragTrap:: highFivesGuys( void )
{
	std::cout	<< COLOUR_GATE
				<< "FragTrap ["
				<< this->_name
				<< "] gave a High Five!"
				<< COLOUR_FIN
				<< std::endl;
}

void FragTrap::attack( const std::string& target )
{
	if (this->getHitPts() == 0)
		return this->cantAttack( target );
	this->_hitPts--;
	std::cout	<< COLOUR_ATTACK
				<< "FragTrap ["
				<< this->_name
				<< "] attacks ["
				<< target
				<< "], causing "
				<< this->_attackDmg
				<< " points of damage!"
				<< COLOUR_FIN
				<< std::endl;
}
