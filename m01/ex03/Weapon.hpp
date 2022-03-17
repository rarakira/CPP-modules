#ifndef WEAPON_H
# define WEAPON_H

# include <iomanip>

# define COLOUR_FIRE	"\033[0;38;5;220m"
# define COLOUR_NEW		"\033[0;38;5;42m"
# define COLOUR_DELETE	"\033[0;38;5;203m"
# define COLOUR_FIN		"\033[0m"

class Weapon {
	private:
		std::string		_type;

	public:
		Weapon( std::string const type );
		~Weapon( void );

		std::string const getType( void ) const;
		void setType( std::string const type );
};

#endif
