#include <iostream>

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

void print_status( std::string const msg)
{
	std::cout	<< std::endl
				<< std::left << std::setw(40) << std::setfill('-')
				<< msg << std::endl;
}

int main( void ) {
	{
		print_status("--- Create weapon ");
		Weapon club = Weapon("crude spiked club");

		print_status("--- Create HumanA ");
		HumanA bob("Bob", club);
		bob.attack();

		print_status("--- Change weapon ");
		club.setType("some other type of club");
		bob.attack();
	}
	{
		print_status("--- Create weapon ");
		Weapon club = Weapon("crude spiked club");

		print_status("--- Create HumanB ");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();

		print_status("--- Change weapon ");
		club.setType("some other type of club");
		jim.attack();
	}

return (0);
}
