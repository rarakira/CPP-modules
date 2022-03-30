#ifndef CAT_H
# define CAT_H

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
	public:
		Cat( void );
		Cat( Cat const & src );
		Cat & operator=( Cat const & rhs );
		virtual AAnimal & operator=( AAnimal const & rhs );
		~Cat( void );

		virtual void makeSound( void ) const;
		Brain* getBrain( void ) const;
};

#endif