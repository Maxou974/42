/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:12:40 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/11 23:14:00 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"

void	HumanB::attack ( void )
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}

