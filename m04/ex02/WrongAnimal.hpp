#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

# include <iostream>

class WrongAnimal
{
	protected:
		std::string		_type;
	public:
		WrongAnimal( void );
		WrongAnimal( std::string const & type );
		WrongAnimal( WrongAnimal const & src );
		WrongAnimal & operator=( WrongAnimal const & rhs );
		~WrongAnimal( void );

		std::string const & getType( void ) const;
		void makeSound( void ) const;
};
#endif