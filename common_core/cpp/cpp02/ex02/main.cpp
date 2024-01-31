/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:18:52 by mabriel           #+#    #+#             */
/*   Updated: 2022/11/18 01:40:06 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include "Fixed.hpp"

int main( void ) {

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "a  : " << a << std::endl;
	std::cout << "b  : " << b << std::endl;
	std::cout << "max: " << Fixed::max( a, b ) << std::endl;
	std::cout << "min: " << Fixed::min( a, b ) << std::endl;

	std::cout << "a = b\n";
	a = b;
	//  a--;
	// a++;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;


	std::cout << "\noperator < called\n";
	if (a < b)
		std::cout << "a < b\n";
	else if ( a > b )
		std::cout << "a > b\n";
	else
		std::cout << "a = b\n";

	std::cout << "\noperator > called\n";
	if (a > b)
		std::cout << "a > b\n";
	else if ( a < b )
		std::cout << "a < b\n";
	else
		std::cout << "a = b\n";

	std::cout << "\noperator == called\n";
	if (a == b)
		std::cout << "a == b\n";
	else
		std::cout << "a != b\n";
	
	std::cout << "\noperator >= called\n";
	if (a >= b)
		std::cout << "a >= b\n";
	else
		std::cout << "a < b\n";

	std::cout << "\noperator <= called\n";
	if (a <= b)
		std::cout << "a <= b\n";
	else
		std::cout << "a > b\n";

	std::cout << "\noperator != called\n";
	if (a != b)
		std::cout << "a != b\n";
	else
		std::cout << "a == b\n";

	std::cout << '\n';
	
	a.setRawBits(pow(2, 9));
	std::cout << a << " + " << b << " = " << a+b << '\n';
	std::cout << a << " - " << b << " = " << a-b << '\n';
	std::cout << a << " * " << b << " = " << a*b << '\n';
	std::cout << a << " / " << b << " = " << a/b << '\n';

	a.setRawBits(0);
	std::cout << "a  : " << a << std::endl; 
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a  : " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a  : " <<  a << std::endl;
	std::cout << "--a: " << --a << std::endl;
	std::cout << "a  : " << a << std::endl;
	std::cout << "a--: " << a-- << std::endl;
	std::cout << "a  : " <<  a << std::endl;

	return 0;
}
