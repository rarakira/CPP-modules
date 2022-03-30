#ifndef BRAIN_H
# define BRAIN_H

# include <iostream>

class Brain
{
	protected:
		std::string		_ideas[100];
	public:
		Brain( void );
		Brain( Brain const & src );
		Brain & operator=( Brain const & rhs );
		virtual ~Brain( void );

		std::string getThought( size_t n ) const;
		void setThought( size_t n, std::string thought );
};

#endif
