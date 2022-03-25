#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	private:
		bool	_gateKeeper;
	protected:
		static int const	_hitPtsPreset = 100;
		static int const	_energyPtsPreset = 50;
		static int const	_attackDmgPreset = 20;
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
