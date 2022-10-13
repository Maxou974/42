/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 02:47:50 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/12 04:28:51 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack( void )
{
	if (this->_weapon == NULL)
	{
		std::cout << this->_name << " attacks with void " << std::endl;
		return ;
	}
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}
