/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:17:06 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/25 21:05:46 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Class Animal: Default Constructor called\n";
	type = "Animal";
}

Animal::Animal(const Animal &ref)
{
	std::cout << "Class Animal: Copy Constructor called\n";
	type = ref.type;
}

Animal&	Animal::operator=(const Animal &ref)
{
	std::cout << "Class Animal: Operator = called\n";
	type = ref.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Class Animal: Default Destructor called\n";
}

void Animal::makeSound() const
{
	std::cout << "Class Animal: *Animal sound*\n";
}

const std::string&	Animal::getType() const
{
	return type;
}