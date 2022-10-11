/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:10:18 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/11 20:50:30 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"

int main()
{
	Weapon gun("Calibre 12");

	HumanA Maxime("Maxime", gun);
	Maxime.attack();
	gun.setType("Savate");
	std::cout << gun.getType() << std::endl;
	Maxime.attack();
}