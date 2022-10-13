/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:11:58 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/12 03:08:35 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include <iostream>
#include "Weapon.hpp"

class	HumanB{
	std::string _name;
	Weapon*	_weapon = NULL;

public:
	HumanB( std::string );
	void	attack( void );
	void	setWeapon( Weapon &weapon );
};

#endif