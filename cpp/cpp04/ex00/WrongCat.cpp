/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:28:14 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/25 20:44:10 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "Class WrongCat: Default Constructor called\n";
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &ref) : WrongAnimal()
{
	std::cout << "Class WrongCat: Copy Constructor called\n";
	type = ref.type;
}

WrongCat&	WrongCat::operator=(const WrongCat &ref)
{
	std::cout << "Class WrongCat: Operator = called\n";
	type = ref.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "Class WrongCat: Default Destructor called\n";
}

void	WrongCat::makeSound() const
{
	std::cout << "Class WrongCat: Miaaouu\n";
}