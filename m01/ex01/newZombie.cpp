#include "Zombie.hpp"

Zombie* Zombie::newZombie( std::string name )
{
	Zombie	*zPtr = new Zombie(name);
	zPtr->announce();
	return zPtr;
}
