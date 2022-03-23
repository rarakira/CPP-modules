#ifndef FIXED_H
# define FIXED_H

# define COLOUR_MAIN	"\033[0;38;5;220m"
# define COLOUR_NEW		"\033[0;38;5;42m"
# define COLOUR_DELETE	"\033[0;38;5;203m"
# define COLOUR_FIN		"\033[0m"

class Fixed {
	private:
		int					_num;
		static const int	_fractBits = 8;

	public:
		Fixed ( void );
		Fixed ( int const n );
		Fixed ( float const n );
		Fixed ( Fixed const & inst );
		~Fixed ( void );

		int getRawBits( void ) const;
		void setRawBits( int const raw );

		float toFloat( void ) const;
		int toInt( void ) const;

		Fixed & operator=( Fixed const & rhs );

		/* Comparison operator overload */
		bool operator>( Fixed const & rhs ) const;
		bool operator<( Fixed const & rhs ) const;
		bool operator>=( Fixed const & rhs ) const;
		bool operator<=( Fixed const & rhs ) const;
		bool operator==( Fixed const & rhs ) const;
		bool operator!=( Fixed const & rhs ) const;

		/* Arithmetic operator overload */
		Fixed operator+( Fixed const & rhs ) const;
		Fixed operator-( Fixed const & rhs ) const;
		Fixed operator*( Fixed const & rhs ) const;
		Fixed operator/( Fixed const & rhs ) const;

		/* increment/decrement operator overload */
		Fixed & operator++();			// ++a
		Fixed operator++(int); 			// a++
		Fixed & operator--();			// --b
		Fixed operator--(int);			// b--

		/* min/max member function */
		static Fixed & min( Fixed & first, Fixed & second );
		static Fixed const & min( Fixed const & first, Fixed const & second );
		static Fixed & max( Fixed & first, Fixed & second );
		static Fixed const & max( Fixed const & first, Fixed const & second );
};

std::ostream & operator<<( std::ostream & o, Fixed const & rhs );

#endif
