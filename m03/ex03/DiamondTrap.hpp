#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include <iostream>
#include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
	private:
		std::string		_name;
	public:
		DiamondTrap ( void );
		DiamondTrap ( std::string const name );
		DiamondTrap ( DiamondTrap const & inst );
		DiamondTrap & operator=( DiamondTrap const & rhs );
		~DiamondTrap ( void );

		void whoAmI( void );
		void attack(const std::string& target);
};

#endif
