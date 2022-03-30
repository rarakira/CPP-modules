#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>
# include "Brain.hpp"

# define COLOUR_BBLUE	"\033[0;38;5;80m"
# define COLOUR_YELL	"\033[0;38;5;220m"
# define COLOUR_VIOL	"\033[0;38;5;135m"
# define COLOUR_ORG		"\033[0;38;5;209m"
# define COLOUR_NEW		"\033[0;38;5;42m"
# define COLOUR_DELETE	"\033[0;38;5;203m"
# define COLOUR_FIN		"\033[0m"

class Animal
{
	protected:
		std::string		_type;
		Brain*			_brain;
	public:
		Animal( void );
		Animal( std::string const & type );
		Animal( Animal const & src );
		Animal & operator=( Animal const & rhs );
		virtual ~Animal( void );

		std::string const & getType( void ) const;
		Brain & getBrain( void ) const;
		Brain * copyBrain( Brain & src ) const;
		virtual void makeSound( void ) const;
};

#endif
