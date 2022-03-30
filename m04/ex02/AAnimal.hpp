#ifndef AANIMAL_H
# define AANIMAL_H

# include <iostream>
# include "Brain.hpp"

# define COLOUR_BBLUE	"\033[0;38;5;80m"
# define COLOUR_YELL	"\033[0;38;5;220m"
# define COLOUR_VIOL	"\033[0;38;5;135m"
# define COLOUR_ORG		"\033[0;38;5;209m"
# define COLOUR_NEW		"\033[0;38;5;42m"
# define COLOUR_DELETE	"\033[0;38;5;203m"
# define COLOUR_FIN		"\033[0m"

class AAnimal
{
	protected:
		std::string		_type;
		Brain*			_brain;
	public:
		virtual AAnimal & operator=( AAnimal const & rhs ) = 0;
		virtual ~AAnimal( void );

		std::string const & getType( void ) const;
		virtual Brain * getBrain( void ) const = 0;
		virtual void makeSound( void ) const = 0;
};

#endif
