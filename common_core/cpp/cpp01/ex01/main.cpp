/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 04:57:30 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/11 05:31:19 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#define N 5

int	main()
{
	Zombie *tab;

	tab = zombieHorde( N, "Maxime" );

	for (int i = 0; i < N; i++)
	{
		std::cout << i << " "; 
		tab[i].announce();
	}

	delete [] tab;
}