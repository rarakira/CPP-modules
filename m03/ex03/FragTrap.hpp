#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : virtual ClapTrap {
	private:
		bool	_highFives;
	public:
		FragTrap ( void );
		FragTrap ( std::string const name );
		FragTrap ( FragTrap const & inst );
		FragTrap & operator=( FragTrap const & rhs );
		~FragTrap ( void );

		void highFivesGuys( void );
		void attack(const std::string& target);
};

#endif
