/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:16:01 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/11 22:12:08 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string name) : _type(name)
{
	return;
}

std::string& Weapon::getType( void )
{
	return (this->_type);
}

void	Weapon::setType ( std::string name )
{
	this->_type = name;
}

Weapon::Weapon()
{
	return ;
}