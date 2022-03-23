#include <iostream>
#include <iomanip>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
		FragTrap	three( "George" );

		one.attack("Jack");
		two.takeDamage(one.getDmg());
		two.beRepaired(5);
		two.attack("Bob");
		one.takeDamage(two.getDmg());
		one.beRepaired(5);
		two.takeDamage(one.getDmg());
		two.attack("George");
		three.takeDamage(two.getDmg());
	}
	{
		print_status("--- TEST 2 ");
		ScavTrap	one( "Bob" );
		FragTrap	two( "George" );

		for (size_t i = 0; i < 15; i++)
		{
			std::cout << i << "." << std::endl;
			one.attack("George");
			two.takeDamage(one.getDmg());
			two.beRepaired(10);
		}
		two.attack("Bob");
		two.highFivesGuys();
		one.guardGate();
	}
	return 0;
}
