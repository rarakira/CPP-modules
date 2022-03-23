#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

# define COLOUR_ATTACK	"\033[0;38;5;220m"
# define COLOUR_REPAIR	"\033[0;38;5;135m"
# define COLOUR_DAMAGE	"\033[0;38;5;209m"
# define COLOUR_NEW		"\033[0;38;5;42m"
# define COLOUR_DELETE	"\033[0;38;5;203m"
# define COLOUR_FIN		"\033[0m"

class ClapTrap {
	private:
		std::string			_name;
		int					_hitPts;
		int					_energyPts;
		int					_attackDmg;
	public:
		ClapTrap ( void );
		ClapTrap ( std::string const name );
		ClapTrap ( ClapTrap const & inst );
		ClapTrap & operator=( ClapTrap const & rhs );
		~ClapTrap ( void );

		int getEnergyPts( void ) const;
		int getHitPts( void ) const;
		int getDmg( void ) const;
		std::string const & getName( void ) const;

		void attack(const std::string& target);
		void cantAttack( const std::string& target );
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void cantRepair( void );
};

#endif
