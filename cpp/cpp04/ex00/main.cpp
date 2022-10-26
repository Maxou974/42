/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:36:21 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/26 16:50:24 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << "\n";

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << "\n";

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << "\n";

	delete meta;
	delete i;
	delete j;

	std::cout << "\n";

	WrongAnimal* ani = new WrongAnimal();
	WrongAnimal* cat = new WrongCat();
	
	std::cout << "\n";
	
	ani->makeSound();
	cat->makeSound();

	std::cout << "\n";

	delete ani;
	delete cat;

	return 0;
}