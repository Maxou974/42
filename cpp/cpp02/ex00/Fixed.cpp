/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:18:46 by mabriel           #+#    #+#             */
/*   Updated: 2022/12/19 14:43:57 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_nbits = 8;

Fixed::Fixed( void )
{
	std::cout << "Default constructor called\n";
	_value = 0;
}

Fixed::~Fixed( void ){
	std::cout << "Destructor called\n";
	return ;
}

Fixed::Fixed(const Fixed &ref)
{
	std::cout << "Copy constructor called\n";
	_value = ref.getRawBits();
}

Fixed & Fixed::operator=(const Fixed &ref)
{
	std::cout << "Copy assignment operator called\n";
	_value = ref.getRawBits();
	return *this;
}

int		Fixed::getRawBits() const
{
	std::cout << "getRawbits member function called\n";
	return _value;
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "setRawbits member function called\n";
	this->_value = raw;
}