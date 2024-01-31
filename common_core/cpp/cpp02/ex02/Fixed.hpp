/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:18:49 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/20 13:46:35 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <ostream>
#include <cmath>

class Fixed{
	private:
		int	_value;
		const static int _nbits;
	public:
		Fixed( void );
		Fixed( const int );
		Fixed( const float );
		Fixed( const Fixed & );
		~Fixed( void );
		Fixed&	operator=(const Fixed &);
		bool	operator<(const Fixed &)const;
		bool	operator>(const Fixed &)const;
		bool	operator>=(const Fixed &)const;
		bool	operator<=(const Fixed &)const;
		bool	operator==(const Fixed &)const;
		bool	operator!=(const Fixed &)const;
		Fixed	operator+(const Fixed &);
		Fixed	operator-(const Fixed &);
		Fixed	operator*(const Fixed &);
		Fixed	operator/(const Fixed &);
		Fixed	operator++();
		Fixed	operator++(int);
		Fixed	operator--();
		Fixed	operator--(int);
		int		getRawBits( void )const;
		void	setRawBits( const int );
		int		toInt( void ) const;
		float	toFloat( void ) const;
		static Fixed&	min(Fixed &, Fixed &);
		static const Fixed&	min(const Fixed &, const Fixed &);
		static Fixed&	max(Fixed &, Fixed &);
		static const Fixed&	max(const Fixed &, const Fixed &);
};

std::ostream&	operator<<(std::ostream& out, const Fixed &ref);


#endif