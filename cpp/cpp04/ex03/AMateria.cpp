/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:34:01 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/31 19:46:52 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	return;
}

AMateria::~AMateria()
{
	
}

AMateria::AMateria(std::string const & type){
	_type = type;
}

std::string const & AMateria::getType() const
{
	return _type;
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
}

AMateria&	AMateria::operator=(const AMateria &ref)
{
	_type = ref._type;
	return *this;
}