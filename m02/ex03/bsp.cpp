#include "Point.hpp"

float findArea( Point const & a, Point const & b, Point const & c )
{
	float area = (a.getX() * (b.getY() - c.getY())
					+ b.getX() * (c.getY() - a.getY())
					+ c.getX() * (a.getY() - b.getY())).toFloat();
	if (area < 0)
		return ( area * -1);
	return ( area );
}

bool bsp( Point const a, Point const b, Point const c, Point const p)
{
	return ( findArea(a, b, c) == (findArea(a, b, p) + findArea(a, p, c) + findArea(p, b, c)) );
}