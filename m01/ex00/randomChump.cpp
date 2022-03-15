#include "Zombie.hpp"

void Zombie::randomChump( std::string name )
{
	Zombie	z = Zombie(name);
	z.announce();
}
