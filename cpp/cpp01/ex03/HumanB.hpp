/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:11:58 by mabriel           #+#    #+#             */
/*   Updated: 2022/11/17 18:45:55 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include <iostream>
#include <string>
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