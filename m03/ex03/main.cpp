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

		print_status("--- ATTACK 1 ");
		xman.whoAmI();
		bob.attack(xman.getName());
		xman.takeDamage(bob.getDmg());
		xman.whoAmI();
		print_status("--- REPAIR ");
		xman.beRepaired(5);
		xman.whoAmI();
		print_status("--- ATTACK 2 ");
		xman.attack(bob.getName());
		bob.takeDamage(xman.getDmg());
		xman.whoAmI();
		print_status("--- ATTACK 3 ");
		bob.attack(xman.getName());
		xman.takeDamage(bob.getDmg());
		print_status("--- ATTACK 4 ");
		xman.whoAmI();
		bob.attack(xman.getName());
		xman.takeDamage(bob.getDmg());
		print_status("--- ATTACK 5 ");
		xman.whoAmI();
		bob.attack(xman.getName());
		xman.takeDamage(bob.getDmg());
		print_status("--- ATTACK 6 ");
		xman.whoAmI();
		xman.attack(bob.getName());
		bob.takeDamage(xman.getDmg());
		xman.whoAmI();
		print_status("--- FIGHT ENDED ");
	}
	return 0;
}
