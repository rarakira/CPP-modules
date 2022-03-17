#include "Harl.hpp"

int main( int argc, char **argv )
{
	std::string		mood;

	if ( argc != 2 )
	{
		std::cerr << "Wrong number of parameters" << std::endl;
		return (1);
	}
	else
	{
		Harl	harl = Harl();

		mood = std::string(argv[1]);
		harl.explain(mood);
	}
	return 0;
}
