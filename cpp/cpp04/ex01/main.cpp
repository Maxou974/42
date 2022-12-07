/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:36:21 by mabriel           #+#    #+#             */
/*   Updated: 2022/12/07 17:23:35 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

#define SIZE 10

void fct(Animal dog)
{
	std::cout << "Call fct Animal\n";
	(void)dog;
	dog.makeSound();
}

void	fct(Dog dog)
{
	std::cout << "Call fct Dog\n";
	std::cout << dog.get_ideas(0);
}

int main()
{
	{
	Animal* tab[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		if (i % 2 == 0)
			tab[i] = new Dog();
		else
			tab[i] = new Cat();
	}
	std::cout << "\n\n";

	tab[1]->makeSound();
	tab[4]->makeSound();
	fct(*tab[4]);
	fct(*tab[5]);
	
	std::cout << "\n\n";
	for (int i = 0; i < SIZE; i++)
		delete tab[i];
	}
	std::cout << "\n\n";
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;
		delete i;
	}
	std::cout << "\n\n";
	{
		Dog one;
		Dog two;

		std::cout << one.get_ideas(0) << two.get_ideas(0);
		
		std::string	ref = "GRRRRRR\n";
		two.set_brain(ref);
		std::cout << '\n';
		std::cout << one.get_ideas(0) << two.get_ideas(0);
		one = two;
		std::cout << one.get_ideas(0) << two.get_ideas(0);
		std::cout <<'\n';
		fct(one);
		std::cout << "\n\n";
	}
}