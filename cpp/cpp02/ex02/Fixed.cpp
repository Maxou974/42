/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:18:46 by mabriel           #+#    #+#             */
/*   Updated: 2022/12/19 14:44:13 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_nbits = 8;

Fixed::Fixed( void )
{
	_value = 0;
}

Fixed::Fixed( const int value)
{
	this->_value = value << this->_nbits;
}

Fixed::Fixed( const float fvalue )
{
	this->_value = (int)roundf(fvalue * pow(2, this->_nbits));
}

Fixed::~Fixed( void ){
}

Fixed::Fixed(const Fixed &ref)
{
	_value = ref.getRawBits();
}

Fixed & Fixed::operator=(const Fixed &ref)
{
	_value = ref.getRawBits();
	return *this;
}

bool	Fixed::operator<(const Fixed &ref1) const
{
	if (this->_value < ref1._value)
		return (true);
	else
		return (false);
}

bool	Fixed::operator>(const Fixed &ref) const 
{
	if (this->_value > ref._value)
		return (true);
	else
		return (false);
}

bool	Fixed::operator>=(const Fixed &ref) const
{
	if (this->_value >= ref._value)
		return (true);
	else
		return (false);
}

bool	Fixed::operator<=(const Fixed &ref) const 
{
	if (this->_value <= ref._value)
		return (true);
	else
		return (false);
}

bool	Fixed::operator==(const Fixed &ref) const 
{
	if (this->_value == ref._value)
		return (true);
	else
		return (false);
}

bool	Fixed::operator!=(const Fixed &ref) const 
{
	if (this->_value != ref._value)
		return (true);
	else
		return (false);
}

Fixed	Fixed::operator+(const Fixed &ref)
{
	return (Fixed(this->toFloat() + ref.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &ref)
{
	return (Fixed(this->toFloat() - ref.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &ref)
{
	return (Fixed(this->toFloat() * ref.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &ref)
{
	return (Fixed(this->toFloat() / ref.toFloat()));
}

Fixed	Fixed::operator++()
{
	this->_value += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_value += 1;
	return tmp;
}

Fixed	Fixed::operator--()
{
	this->_value -= 1;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	this->_value -= 1;
	return (tmp);
}

std::ostream&	operator<<(std::ostream& out, const Fixed &ref)
{
	out << ref.toFloat();
	return out;
}

int		Fixed::getRawBits() const
{
	return _value;
}

void	Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}

int	Fixed::toInt(void) const
{
	return this->_value >> this->_nbits;
}

float	Fixed::toFloat(void) const
{
	return (float)this->_value / pow(2, this->_nbits);
}

Fixed&	Fixed::min(Fixed& a, Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}