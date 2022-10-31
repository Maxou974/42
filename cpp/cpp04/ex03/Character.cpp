/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:41:36 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/31 20:51:57 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "Character.hpp"

Character::Character()
{
	_Name = "Random";
	for (int i = 0; i < 4; i++)
		power[i] = NULL;
}

Character::Character(std::string ref)
{
	_Name = ref;
	for (int i = 0; i < 4; i++)
		power[i] = NULL;
}

Character::Character(const Character &ref)
{
	_Name = ref._Name;
	for (int i = 0; i < 4; i++)
	{
		if (ref.power[i])
			this->power[i] = ref.power[i]->clone();
		else
			this->power[i] = NULL;
	}
}

Character& Character::operator=(const Character &ref)
{
	std::cout << "Character: Operator =\n";
	_Name = ref._Name;
	for (int i = 0; i < 4; i++)
	{
		if (ref.power[i])
			this->power[i] = ref.power[i]->clone();
		else
			this->power[i] = NULL;
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (power[i])
			delete power[i];
	}
}

const std::string& Character::getName()const
{
	return (_Name);
}

void	Character::equip(AMateria *m)
{
	int _powerindex = 0;
	int i = 0;
	int ok = 1;

	if (!m)
	 	return ;
	while (_powerindex < 4 && power[_powerindex])
		_powerindex++;
	while (i < 4)
	{
		if (m == power[i])
			ok = 0;
		i++;
	}
	if (_powerindex < 4 && ok == 1)
		power[_powerindex] = m;
	if (_powerindex < 4 && ok == 0)
		power[_powerindex] = m->clone();
}

void	Character::unequip(int idx)
{
	if (power[idx])
		power[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	(void)idx;
	(void)target;
	if (power[idx])
		power[idx]->use(target);
}

AMateria*	Character::get_Materia_ptr(int idx)
{
	return (power[idx]);
}