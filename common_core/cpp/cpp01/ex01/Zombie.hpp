/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 02:40:20 by mabriel           #+#    #+#             */
/*   Updated: 2022/11/17 19:03:40 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

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