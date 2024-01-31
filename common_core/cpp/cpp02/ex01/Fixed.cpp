/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:18:46 by mabriel           #+#    #+#             */
/*   Updated: 2022/12/19 14:44:03 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_nbits = 8;

Fixed::Fixed( void )
{
	std::cout << "Default constructor called\n";
	_value = 0;
}

Fixed::Fixed( const int value)
{
	std::cout << "Int constructor called\n";
	this->_value = value << this->_nbits;
}

Fixed::Fixed( const float fvalue )
{
	std::cout << "Float constructor called\n";
	this->_value = (int)roundf(fvalue * pow(2, this->_nbits));
}

Fixed::~Fixed( void ){
	std::cout << "Destructor called\n";
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

std::ostream&	operator<<(std::ostream& out, const Fixed &ref)
{
	out << ref.toFloat();
	return out;
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

int	Fixed::toInt(void) const
{
	return this->_value >> this->_nbits;
}

float	Fixed::toFloat(void) const
{
	// return (float)this->_value / pow(2, this->_nbits);
	return (float)this->_value / pow(2, this->_nbits);
}