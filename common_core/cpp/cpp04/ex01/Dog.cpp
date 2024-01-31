/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:24:48 by mabriel           #+#    #+#             */
/*   Updated: 2023/01/05 00:44:57 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog()
{
	std::cout << "Class Dog: Default Constructor called\n";
	type = "Dog";
	_Brain = new Brain();
}

Dog::Dog(const Dog &ref) : Animal()
{
	std::cout << "Class Dog: Copy Constructor called\n";
	type = ref.type;
	_Brain = new Brain();
	for (int i = 0; i < 100; i++)
		_Brain->set_ideas(i, ref._Brain->get_ideas(i));
}

Dog&	Dog::operator=(const Dog &ref)
{
	std::cout << "Class Dog: Operator = called\n";
	if (_Brain)
		delete _Brain;
	_Brain = new Brain();
	type = ref.type;
	for (int i = 0; i < 100; i++)
		_Brain->set_ideas(i, ref._Brain->get_ideas(i));
	return *this;
}

Dog::~Dog()
{
	std::cout << "Class Dog: Default Destructor called\n";
	delete _Brain;
}

void	Dog::makeSound()const
{
	std::cout << "Class Dog: Woof Woof\n";
}

void	Dog::set_brain(std::string &ref)
{
	for (int i = 0; i<100; i++)
		_Brain->set_ideas(i, ref);
}

std::string	Dog::get_ideas(int index)
{
	return _Brain->get_ideas(index);
}