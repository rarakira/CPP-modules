#ifndef Dog_H
# define CAT_H

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	public:
		Dog( void );
		Dog( Dog const & src );
		Dog & operator=( Dog const & rhs );
		virtual AAnimal & operator=( AAnimal const & rhs );
		~Dog( void );

		virtual void makeSound( void ) const;
		Brain* getBrain( void ) const;
};

#endif