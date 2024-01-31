/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:47:59 by mabriel           #+#    #+#             */
/*   Updated: 2022/12/19 15:08:03 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap maxime("Maxime");
	ClapTrap ren("ren");

	maxime.attack("SISTER");
	maxime.beRepaired(34);
	maxime.takeDamage(45);
	maxime.attack("SISTER");
	maxime.beRepaired(34);
	maxime.takeDamage(45);

	//ren = maxime;

	ren.attack("random guy in street");
	ren.attack("random guy in street");
	ren.attack("random guy in street");
	ren.attack("random guy in street");
	ren.attack("random guy in street");
	ren.attack("random guy in street");
	ren.attack("random guy in street");
	ren.attack("random guy in street");
	ren.attack("random guy in street");
	ren.attack("random guy in street");
	ren.attack("random guy in street");
	ren.attack("random guy in street");
	ren.attack("random guy in street");
	ren.beRepaired(10);
	ren.takeDamage(5);

}