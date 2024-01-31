/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:17:06 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/25 21:05:46 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Class WrongAnimal: Default Constructor called\n";
	type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &ref)
{
	std::cout << "Class WrongAnimal: Copy Constructor called\n";
	type = ref.type;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal &ref)
{
	std::cout << "Class WrongAnimal: Operator = called\n";
	type = ref.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Class WrongAnimal: Default Destructor called\n";
}

void WrongAnimal::makeSound() const
{
	std::cout << "Class WrongAnimal: *WrongAnimal sound*\n";
}

const std::string&	WrongAnimal::getType() const
{
	return type;
}