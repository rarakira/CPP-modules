#include <iomanip>

#include "Harl.hpp"

void print_status( std::string const msg)
{
	std::cout	<< std::endl
				<< std::left << std::setw(40) << std::setfill('-')
				<< msg << std::endl;
}

int main( void )
{
	Harl	harl = Harl();

	print_status("--- DEBUG mode ");
	harl.complain("DEBUG");
	print_status("--- info mode ");
	harl.complain("info");
	print_status("--- WARNING mode ");
	harl.complain("WARNING");
	print_status("--- error mode ");
	harl.complain("error");
	return 0;
}
