/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:18:52 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/20 14:25:11 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include "Fixed.hpp"

int main( void ) {

Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "\noperator < called\n";
	if (a < b)
		std::cout << "a < b\n";
	else
		std::cout << "a > b\n";

	std::cout << "\noperator > called\n";
	if (a > b)
		std::cout << "a > b\n";
	else
		std::cout << "a < b\n";

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

	std::cout << "a + b = "<< a+b << '\n';
	std::cout << "a - b = "<< a-b << '\n';
	std::cout << "a * b = "<< a*b << '\n';
	std::cout << "a / b = "<< a/b << '\n';

	a.setRawBits(0);
	std::cout << a++ << " " << a << '\n';
	std::cout << ++a << " " << a << '\n';
	std::cout << --a << " " << a << '\n';
	std::cout << a-- << " " << a << '\n';

	return 0;
}
