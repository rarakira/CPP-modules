#ifndef HUMANB_H
# define HUMANB_H

# include "Weapon.hpp"

class HumanB {
	private:
		std::string		_name;
		Weapon*			_weapon;


	public:
		HumanB( std::string const name );
		~HumanB( void );

		void setWeapon( Weapon& type );
		void attack( void );
};

#endif
