/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:04:13 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/26 20:29:36 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Class Brain: Constructor called\n";
	for (int i = 0; i < 100; i++)
		_ideas[i] = "EAT\n";
}

Brain::Brain(const Brain &ref)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = ref._ideas[i];
}

Brain& Brain::operator=(const Brain &ref)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = ref._ideas[i];
	return *this;
}

Brain::~Brain()
{
	std::cout << "Class Brain: Destructor called\n";
}

std::string&	Brain::get_ideas(int index)
{
	return (_ideas[index]);
}

void	Brain::set_ideas(int index, const std::string ref)
{
	_ideas[index] = ref;
}