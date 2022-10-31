/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:52:35 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/31 15:20:47 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	_type = "ice";
}

Ice::Ice(const Ice &ref) : AMateria(ref)
{
	_type = ref._type;
}

Ice&	Ice::operator=(const Ice &ref)
{
	_type = ref._type;
	return *this;
}

AMateria* Ice::clone()const
{
	return (new Ice);
}

Ice::~Ice()
{

}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}