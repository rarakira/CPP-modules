#ifndef HUMANB_H
# define HUMANB_H

class HumanB {
	private:
		std::string		_name;
		Weapon*			_weapon;


	public:
		HumanB( std::string const name );
		~HumanB( void );

		void setWeapon( Weapon const type );
		void attack( void );
};

#endif
