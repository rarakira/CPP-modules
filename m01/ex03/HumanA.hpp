#ifndef HUMANA_H
# define HUMANA_H

# include "Weapon.hpp"

class HumanA {
	private:
		std::string		_name;
		Weapon			_weapon;


	public:
		HumanA( std::string const name, Weapon weapontype );
		~HumanA( void );

		void attack( void );
};

#endif
