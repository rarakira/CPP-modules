#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	private:
		bool				_highFives;
	protected:
		static int const	_hitPtsPreset = 100;
		static int const	_energyPtsPreset = 100;
		static int const	_attackDmgPreset = 30;
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
