/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:45:09 by mabriel           #+#    #+#             */
/*   Updated: 2022/12/07 15:45:11 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{}

Point::Point(const float x, const float y) : _x(x), _y(y)
{}

Point::Point(const Point &ref) : _x(ref._x), _y(ref._y)
{}

Point::~Point()
{}

Point&	Point::operator=(const Point &ref)
{
	(Fixed)_x = ref._x;
	(Fixed)_y = ref._y;
	return (*this);
}

float	Point::get_x()
{
	return(this->_x.toFloat());
}

float	Point::get_y()
{
	return(this->_y.toFloat());
}