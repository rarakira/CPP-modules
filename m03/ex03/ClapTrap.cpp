#include <iostream>

#include "ClapTrap.hpp"

ClapTrap::ClapTrap ( void ) : _name("Default"), _hitPts(10), _energyPts(10), _attackDmg(0)
{
	std::cout	<< COLOUR_NEW
				<< "ClapTrap default constructor called"
				<< COLOUR_FIN
				<< std::endl;
	return;
}


ClapTrap::ClapTrap ( std::string const name ) : _name(name), _hitPts(10), _energyPts(10), _attackDmg(0)
{
	std::cout	<< COLOUR_NEW
				<< "ClapTrap constructor called for " << this->_name
				<< COLOUR_FIN
				<< std::endl;
	return;
}

ClapTrap::ClapTrap ( ClapTrap const & inst )
	: _name(inst.getName()), _hitPts(inst.getHitPts()), _energyPts(inst.getEnergyPts()), _attackDmg(inst.getDmg())
{
	std::cout	<< COLOUR_NEW
				<< "ClapTrap copy constructor called for " << this->_name
				<< COLOUR_FIN
				<< std::endl;
	return;
}

ClapTrap::~ClapTrap ( void )
{
	std::cout	<< COLOUR_DELETE
				<< "ClapTrap destructor called for " << this->_name
				<< COLOUR_FIN
				<< std::endl;
	return;
}

int ClapTrap::getEnergyPts( void ) const
{
	return this->_energyPts;
}

int ClapTrap::getHitPts( void ) const
{
	return this->_hitPts;
}

int ClapTrap::getDmg( void ) const
{
	return this->_attackDmg;
}

std::string const & ClapTrap::getName( void ) const
{
	return this->_name;
}

void ClapTrap::cantAttack( const std::string& target )
{
	std::cout	<< COLOUR_ATTACK
				<< "ClapTrap ["
				<< this->_name
				<< "] does not have any hit points left so he can't attack ["
				<< target
				<< "]!"
				<< COLOUR_FIN
				<< std::endl;
}

void ClapTrap::attack( const std::string& target )
{
	if (this->getHitPts() == 0)
		return this->cantAttack( target );
	this->_hitPts--;
	std::cout	<< COLOUR_ATTACK
				<< "ClapTrap ["
				<< this->_name
				<< "] attacks ["
				<< target
				<< "], causing "
				<< this->_attackDmg
				<< " points of damage!"
				<< COLOUR_FIN
				<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{

	this->_hitPts -= amount;
	if (this->_hitPts < 0)
		this->_hitPts = 0;
	if (this->getEnergyPts())
		this->_energyPts--;
	std::cout	<< COLOUR_DAMAGE
				<< "ClapTrap ["
				<< this->_name
				<< "] is being damaged with "
				<< amount
				<< " points." << std::endl
				<< this->_hitPts
				<< " hit points left."
				<< COLOUR_FIN
				<< std::endl;
}

void ClapTrap::cantRepair( void )
{
	std::cout	<< COLOUR_REPAIR
				<< "ClapTrap ["
				<< this->_name
				<< "] can not be repaired as he has no energy points left!"
				<< COLOUR_FIN
				<< std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getEnergyPts() == 0)
		return this->cantRepair();
	this->_energyPts--;
	this->_hitPts += amount;
	std::cout	<< COLOUR_REPAIR
				<< "ClapTrap ["
				<< this->_name
				<< "] is being repaired with "
				<< amount
				<< " points." << std::endl
				<< this->_hitPts
				<< " hit points left."
				<< COLOUR_FIN
				<< std::endl;
}
