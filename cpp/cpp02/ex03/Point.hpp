#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point{
	private:
		const Fixed _x;
		const Fixed _y;
	public:
	Point();
	~Point();
	Point(const float, const float);
	Point(const Point &);
	Point&	operator=(const Point &);
	float	get_x();
	float	get_y();
};

#endif