#ifndef POINT_H
# define POINT_H

# include <iostream>
# include "Fixed.hpp"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;
	public:
		Point( void );
		Point( float const x, float const y );
		Point( Fixed const x, Fixed const y );
		Point( Point const & copy );
		~Point();

		Point & operator=( Point & rhs );

		Fixed getX( void ) const;
		Fixed getY( void ) const;
};

std::ostream & operator<<( std::ostream & o, Point const & rhs );
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif