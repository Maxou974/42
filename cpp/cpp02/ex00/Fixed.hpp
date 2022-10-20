/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:18:49 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/20 12:43:53 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
	private:
		int	_value;
		const static int _nbits;
	public:
		Fixed( void );
		Fixed(const Fixed &);
		~Fixed( void );
		Fixed&	operator=(const Fixed &ref);
		int		getRawBits( void )const;
		void	setRawBits( const int raw);
};

#endif