#ifndef FIXED_H
# define FIXED_H

# define COLOUR_MAIN	"\033[0;38;5;220m"
# define COLOUR_NEW		"\033[0;38;5;42m"
# define COLOUR_DELETE	"\033[0;38;5;203m"
# define COLOUR_FIN		"\033[0m"

class Fixed {
	private:
		int					_num;
		static const int	_fractBits;
	public:
		Fixed ( void );
		Fixed ( int const n );
		Fixed ( Fixed const & inst );
		~Fixed ( void );
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif
