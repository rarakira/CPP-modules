#ifndef INTEGER_H
# define INTEGER_H

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
