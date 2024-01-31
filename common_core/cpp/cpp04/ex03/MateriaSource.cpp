/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:38:16 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/31 20:52:24 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		source[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &ref)
{
	for (int i = 0; i < 4; i++)
	{
		if (ref.source[i])
			source[i] = ref.source[i]->clone();
		else
			source[i] = NULL;
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource &ref)
{
	std::cout << "MateriaSource: Operator =\n";
	for (int i = 0; i < 4; i++)
	{
		if (ref.source[i])
			source[i] = ref.source[i]->clone();
		else
			source[i] = NULL;
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (source[i])
			delete source[i];
	}
}

void	MateriaSource::learnMateria(AMateria *ptr)
{
	int idx = 0;
	int ok = 1;
	int i = 0;

	while (idx < 4 && source[idx])
		idx++;
	while (i < 4)
	{
		if (ptr == source[i])
			ok = 0;
		i++;
	}
	if (idx < 4 && ok == 1)
		source[idx] = ptr;
	if (idx < 4 && ok == 0)
		source[idx] = ptr->clone();
}

AMateria*	MateriaSource::createMateria(std::string const &ref)
{
	for (int i=0; i < 4; i++)
	{
		if (source[i] && ref == source[i]->getType())
			return source[i]->clone();
	}
	return NULL;
}