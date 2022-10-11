/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 02:40:20 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/11 05:40:23 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
	
	std::string name;

public:
	Zombie ( void );
	~Zombie( void );
	void	set_name( std::string name );
	void	announce( void );
};

Zombie*	zombieHorde( int N, std::string name );

#endif