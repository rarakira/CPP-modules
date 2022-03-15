#include "Zombie.hpp"

int main( void )
{
	std::string names[5] = {"One", "Two", "Three", "Four", "Five"};
	Zombie*		fiveZombies = Zombie::zombieHorde(5, "Hey");
	std::cout << std::endl;

	for (size_t i = 0; i < 5; i++)
	{
		std::cout << "Zombie " << i + 1 << " of 5:" << std::endl;
		fiveZombies[i].announce();
		std::cout << COLOUR_MAIN;
		fiveZombies[i].setName(names[i]);
		fiveZombies[i].announce();
		std::cout << COLOUR_FIN;
		std::cout << std::endl;
	}
	
	delete [] fiveZombies;
	std::cout << std::endl;

	return 0;
}
