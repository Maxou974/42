/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:32:00 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/25 17:54:46 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &ref) : ClapTrap(ref + "_clap_name")
{
	std::cout << "Constructor called for DiamondTrap\n";
	_Name = ref;
	set_HP(100);
	set_AD(30);
	set_EP(50);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor called for DiamondTrap\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &ref) : ClapTrap(ref), FragTrap(ref), ScavTrap(ref)
{
	std::cout << "Copy Constructor called for DiamondTrap\n";
	_Name = ref._Name;
	set_HP(ref.get_HP());
	set_AD(ref.get_AD());
	set_EP(ref.get_EP());
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap &ref)
{
	_Name = ref._Name;
	set_HP(ref.get_HP());
	set_AD(ref.get_AD());
	set_EP(ref.get_EP());
	return *this;
}

void	DiamondTrap::attack(const std::string &ref)
{
	ScavTrap::attack(ref);
}

void	DiamondTrap::info()
{
	std::cout << "INFO: DiamondTrap " << _Name << ": " << get_HP() << " Hp   ";
	std::cout << get_EP() << " Ep   " << get_AD() << " Ad\n\n";
}

void	DiamondTrap::whoAmI()
{
	std::cout << "Hello Im a DiamondTrap, here is my DiamondTrap name: " << _Name;
	std::cout << "\nAnd here is my ClapTrap name: " << get_name() << "\n\n";
}