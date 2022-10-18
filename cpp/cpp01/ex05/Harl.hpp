/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:02:39 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/17 17:44:53 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl{
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
	typedef void (Harl::*fct_ptr)( void );
	fct_ptr	fct_ptrs[4];
	std::string fct_names[4];

public:
	Harl( void );
	void	complain( std::string level);
};

#endif