/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:47:49 by mabriel           #+#    #+#             */
/*   Updated: 2022/12/19 15:05:39 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Constructor called\n";
	_Name = name;
	_Hit_Points = 10;
	_Energy_Points = 10;
	_Attack_Damage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &ref)
{
	if (this == &ref)
	std::cout << "Copy constructor called\n";
	_Name = ref._Name;
	_Hit_Points = ref._Hit_Points;
	_Energy_Points = ref._Energy_Points;
	_Attack_Damage = ref._Attack_Damage;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &ref)
{
	
	_Name = ref._Name;
	_Hit_Points = ref._Hit_Points;
	_Energy_Points = ref._Energy_Points;
	_Attack_Damage = ref._Attack_Damage;
	return *this;
}

std::string	ClapTrap::get_name()
{
	return (this->_Name);
}

void	ClapTrap::attack(const std::string &target)
{
	std::cout << "Attack call: ";
	if (_Energy_Points > 0 && _Hit_Points > 0)
	{
		std::cout << "ClapTrap " << _Name << " attacks " << target;
		std::cout << ", causing " << _Attack_Damage << " points of damage\n";
		_Energy_Points--;
	}
	else
		std::cout << "ClapTrap " << _Name << " can not execute attack\n";
	//this->info();
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "takeDamage call: ";
	if (_Hit_Points > 0)
	{
		std::cout << "ClapTrap " << _Name << " take " << amount << " damage in his face\n";
		_Hit_Points -= (int)amount;
	}
	else
		std::cout << "ClapTrap " << _Name << " can not take more damage, he is dead ;(\n";
	//this->info();
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "beRepaired call: ";
	if (_Energy_Points > 0 && _Hit_Points > 0)
	{
		std::cout << "ClapTrap " << _Name << " repair his self of " << amount;
		std::cout << " Hit_Points\n";
		_Hit_Points += amount;
		_Energy_Points--;
	}
	else
		std::cout << "ClapTrap " << _Name << " can not execute beRepaired\n";
	//this->info();
}

void	ClapTrap::info()
{
	std::cout << "INFO: ClapTrap " << _Name << ": " << _Hit_Points << " Hp   ";
	std::cout << _Energy_Points << " Ep   " << _Attack_Damage << " Ad\n\n";
}