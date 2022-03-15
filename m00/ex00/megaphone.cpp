#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	char	*current;
	int		i = 1;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (i < argc)
	{
		current = argv[i];
		while (*current)
		{
			if (std::islower(*current))
				std::cout << (char) std::toupper(*current);
			else
				std::cout << *current;
			current++;
		}
		i++;
	}
	std::cout << std::endl;
	return 0;
}
