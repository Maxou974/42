/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:24:48 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/25 20:43:53 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Class Dog: Default Constructor called\n";
	type = "Dog";
}

Dog::Dog(const Dog &ref) : Animal()
{
	std::cout << "Class Dog: Copy Constructor called\n";
	type = ref.type;
}

Dog&	Dog::operator=(const Dog &ref)
{
	std::cout << "Class Dog: Operator = called\n";
	type = ref.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Class Dog: Default Destructor called\n";
}

void	Dog::makeSound()const
{
	std::cout << "Class Dog: Woof Woof\n";
}