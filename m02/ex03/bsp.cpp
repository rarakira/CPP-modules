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

bool onLine( Point const & a, Point const & b, Point const & p)
{
	if ( a.getX() == p.getX() )
		return ( b.getX() == p.getX() );
	if ( a.getY() == p.getY() )
		return ( b.getY() == p.getY()) ;
	return ( a.getX() - p.getX()) * (a.getY() - p.getY()) == (p.getX() - b.getX()) * (p.getY() - b.getY() );
}

bool bsp( Point const & a, Point const & b, Point const & c, Point const & p)
{
	if (findArea(a, b, c) == (findArea(a, b, p) + findArea(a, p, c) + findArea(p, b, c)))
	{
		if (onLine(a, b, p) || onLine(a, c, p) || onLine(b, c, p))
			return false;
		return true;
	}
	return false;
}
