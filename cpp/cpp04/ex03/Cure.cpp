/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:54:28 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/31 16:55:17 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	_type = "cure";
}

Cure::Cure(const Cure &ref) : AMateria(ref)
{
	_type = ref._type;
}

Cure&	Cure::operator=(const Cure &ref)
{
	_type = ref._type;
	return *this;
}

AMateria* Cure::clone()const
{
	return (new Cure);
}

Cure::~Cure()
{

}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}