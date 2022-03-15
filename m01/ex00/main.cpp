#include "Zombie.hpp"

int main( void )
{
	/* Create new Zombie on stack */
	Zombie		z = Zombie("First");
	std::cout << std::endl;

	/* Create new Zombie on heap */
	Zombie*		zPtr;

	zPtr = Zombie::newZombie("Second");
	std::cout << std::endl;

	/* Make both announce etheir names */
	std::cout << COLOUR_MAIN;
	z.announce();
	zPtr->announce();
	std::cout << std::endl;

	/* Make a random chump */
	Zombie::randomChump("Third");
	std::cout << COLOUR_FIN;
	std::cout << std::endl;

	/* Delete from heap */
	delete zPtr;
	std::cout << std::endl;

	/* Make a random chump */
	Zombie::randomChump("Fourth");
	std::cout << std::endl;

	return 0;
}
