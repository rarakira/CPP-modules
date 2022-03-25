#include <iostream>
#include <iomanip>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

void print_status( std::string const msg)
{
	std::cout	<< std::endl
				<< std::left << std::setw(40) << std::setfill('-')
				<< msg << std::endl;
}

int main( void )
{
	{
		print_status("--- FIGHT ");
		FragTrap	bob( "Bob" );
		DiamondTrap	xman( "Xman" );

		xman.whoAmI();
		bob.attack(xman.getName());
		xman.takeDamage(bob.getDmg());
		xman.beRepaired(5);
		xman.attack(bob.getName());
		bob.takeDamage(xman.getDmg());
		bob.beRepaired(5);
		xman.whoAmI();
		bob.attack(xman.getName());
		xman.takeDamage(bob.getDmg());
		xman.whoAmI();
		bob.attack(xman.getName());
		xman.takeDamage(bob.getDmg());
		xman.whoAmI();
		bob.attack(xman.getName());
		xman.takeDamage(bob.getDmg());
		xman.whoAmI();
		xman.attack(bob.getName());
		bob.takeDamage(xman.getDmg());
		xman.whoAmI();
	}
	return 0;
}
