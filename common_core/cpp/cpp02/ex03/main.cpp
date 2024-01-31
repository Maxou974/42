/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:18:52 by mabriel           #+#    #+#             */
/*   Updated: 2022/11/18 02:38:19 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) {
{
	Point a(-1, -1);
	Point b(-2, -2);
	Point c(-1, -3);
	Point point(-0.99f, -2);
	if (bsp(a,b,c,point))
		std::cout << "1:inside\n\n";
	else
		std::cout << "1:outside\n\n";
}
{
	Point a(1, 1);
	Point b(2, 2);
	Point c(1, 3);
	Point point(0.99f, 2);
	if (bsp(a,b,c,point))
		std::cout << "2:inside\n\n";
	else
		std::cout << "2:outside\n\n";
}
{
	Point a(-1, 1);
	Point b(2, -2);
	Point c(-1, -3);
	Point point(0, -1);
	if (bsp(a,b,c,point))
		std::cout << "3:inside\n";
	else
		std::cout << "3:outside\n";
}

	return 0;
}
