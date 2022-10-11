/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 02:40:20 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/11 05:02:38 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
	
	std::string name;

public:
	Zombie( std::string name );
	~Zombie( void );
	void	announce( void );
};

Zombie* newZombie( std::string name);
void	randomChump( std::string name );

#endif