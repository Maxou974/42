/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 04:57:30 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/11 05:01:56 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie *Maxime;

	Maxime = newZombie("Maxime");
	Maxime->announce();
	delete Maxime;

	randomChump("Samuel");
}