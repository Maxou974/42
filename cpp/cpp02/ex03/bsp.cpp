#include "Point.hpp"

float	air(Point v1, Point v2, Point point)
{
	float tmp;
	tmp = (v2.get_x() - point.get_x()) * (v1.get_y() - point.get_y());
	tmp -= (v2.get_y() - point.get_y()) * (v1.get_x() - point.get_x());
	return (tmp);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (air(a, c, point) > 0 && air(b, a, point) > 0 && air(c, b, point) > 0)
		return (true);
	else if (air(a, c, point) < 0 && air(b, a, point) < 0 && air(c, b, point) < 0)
		return (true);
	else
		return(false);
}