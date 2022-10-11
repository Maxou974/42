/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 02:42:28 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/11 05:43:22 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name( std::string name)
{
	this->name = name;
}

Zombie::~Zombie( void )
{
	std::cout << this->name << " is dead\n";
}

Zombie::Zombie(){
	std::cout << "A zombie is borned\n";
}