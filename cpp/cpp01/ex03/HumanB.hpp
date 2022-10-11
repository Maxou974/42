/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:11:58 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/11 23:12:30 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include <iostream>
#include "Weapon.hpp"

class	HumanB{
	std::string _name;
	Weapon*	_weapon;

public:
	HumanB(std::string, Weapon*);
	void	attack( void );
};

#endif