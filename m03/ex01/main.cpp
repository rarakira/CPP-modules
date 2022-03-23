#include <iostream>
#include <iomanip>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void print_status( std::string const msg)
{
	std::cout	<< std::endl
				<< std::left << std::setw(40) << std::setfill('-')
				<< msg << std::endl;
}

int main( void )
{
	{
		print_status("--- TEST 1 ");
		ClapTrap	one( "Bob" );
		ScavTrap	two( "Jack" );

		one.attack("Jack");
		two.takeDamage(one.getDmg());
		two.beRepaired(5);
		two.attack("Bob");
		one.takeDamage(two.getDmg());
		one.beRepaired(5);
		two.takeDamage(one.getDmg());
	}
	{
		print_status("--- TEST 2 ");
		ScavTrap	one( "Bob" );
		ClapTrap	two( "Jack" );

		for (size_t i = 0; i < 15; i++)
		{
			std::cout << i << "." << std::endl;
			one.attack("Jack");
			two.takeDamage(one.getDmg());
			two.beRepaired(10);
		}
		two.attack("Bob");
		one.guardGate();
	}
	return 0;
}
