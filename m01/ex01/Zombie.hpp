#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <iostream>

# define COLOUR_MAIN	"\033[0;38;5;220m"
# define COLOUR_NEW		"\033[0;38;5;42m"
# define COLOUR_DELETE	"\033[0;38;5;203m"
# define COLOUR_FIN		"\033[0m"

class Zombie {
	std::string		_name;

public:
	Zombie( void );
	~Zombie( void );

	Zombie( std::string const name );
	void announce( void );
	std::string getName( void ) const;
	void setName( std::string const name );
	static Zombie* newZombie( std::string name );
	static Zombie* zombieHorde( int N, std::string name );
};

#endif
