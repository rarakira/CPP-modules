#include <iostream>
#include <iomanip>
#include "iter.hpp"

void print_status(std::string const msg) {
	std::cout	<< std::endl
				<< std::left << std::setw(40) << std::setfill('-')
				<< msg << std::endl;
}

int main(void) {
	{
		print_status("--- String ");
		std::string	cities[] = {"London", "Liverpool", "Manchester", "Sheffield", "Bristol"};
		unsigned int n = 5;
		iter(cities, n, &print);
	}
	{
		print_status("--- Float ");
		float	nums[] = {21, 42.21, +0.0, -0.0, -10000};
		unsigned int n = 5;
		iter(nums, n, &print);
	}
	return 0;
}
