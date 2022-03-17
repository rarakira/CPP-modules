#ifndef HARL_H
# define HARL_H

# include <iostream>

# define COLOUR_DEBUG		"\033[0;38;5;42m"
# define COLOUR_INFO		"\033[0;38;5;220m"
# define COLOUR_WARNING		"\033[0;38;5;202m"
# define COLOUR_ERROR		"\033[0;38;5;196m"
# define COLOUR_FIN			"\033[0m"

class Harl
{
	private:
		void debug( void );
		void info( void );
		void warning( void );
 		void error( void );

		void (Harl:: *_mood[4]) (void);
		std::string _levels[4];

	public:
		Harl( void );
		~Harl( void );

		void complain( std::string level );
		void explain( std::string level );
};

#endif
