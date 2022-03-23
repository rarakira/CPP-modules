#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	private:
		bool	_gateKeeper;
	public:
		ScavTrap ( void );
		ScavTrap ( std::string const name );
		ScavTrap ( ScavTrap const & inst );
		ScavTrap & operator=( ScavTrap const & rhs );
		~ScavTrap ( void );

		void guardGate( void );
		void attack(const std::string& target);
		bool isGateKeeper( void ) const;
};

#endif
