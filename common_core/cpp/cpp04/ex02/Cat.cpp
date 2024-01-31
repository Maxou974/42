/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:28:14 by mabriel           #+#    #+#             */
/*   Updated: 2023/01/05 00:48:50 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat()
{
	std::cout << "Class Cat: Default Constructor called\n";
	type = "Cat";
	_Brain = new Brain();
}

Cat::Cat(const Cat &ref) : Animal()
{
	std::cout << "Class Cat: Copy Constructor called\n";
	type = ref.type;
	_Brain = new Brain();
	for (int i = 0; i < 100; i++)
		_Brain->set_ideas(i, ref._Brain->get_ideas(i));
}

Cat&	Cat::operator=(const Cat &ref)
{
	std::cout << "Class Cat: Operator = called\n";
	type = ref.type;
	if (_Brain)
		delete _Brain;
	_Brain = new Brain();
	for (int i = 0; i < 100; i++)
		_Brain->set_ideas(i, ref._Brain->get_ideas(i));
	return *this;
}

Cat::~Cat()
{
	std::cout << "Class Cat: Default Destructor called\n";
	delete _Brain;
}

void	Cat::makeSound()
{
	std::cout << "Class Cat: Miaaouu\n";
}

void	Cat::set_brain(std::string &ref)
{
	for (int i = 0; i<100; i++)
		_Brain->set_ideas(i, ref);
}

std::string	Cat::get_ideas(int index)
{
	return _Brain->get_ideas(index);
}