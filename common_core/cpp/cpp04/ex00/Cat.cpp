/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:28:14 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/26 20:46:02 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Class Cat: Default Constructor called\n";
	type = "Cat";
}

Cat::Cat(const Cat &ref) : Animal()
{
	std::cout << "Class Cat: Copy Constructor called\n";
	type = ref.type;
}

Cat&	Cat::operator=(const Cat &ref)
{
	std::cout << "Class Cat: Operator = called\n";
	type = ref.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Class Cat: Default Destructor called\n";
}

void	Cat::makeSound() const
{
	std::cout << "Class Cat: Miaaouu\n";
}