/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:36:21 by mabriel           #+#    #+#             */
/*   Updated: 2023/01/05 00:25:58 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int main()
{
{
	const Animal* ani = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	
	std::cout << "\n";

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;

	std::cout << "\n";

	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	ani->makeSound();

	std::cout << "\n";

	delete ani;
	delete cat;
	delete dog;
}
{
	std::cout << "\n";

	WrongAnimal* ani = new WrongAnimal();
	WrongAnimal* cat = new WrongCat();
	
	std::cout << "\n";
	
	std::cout << ani->getType() << '\n';
	ani->makeSound();
	std::cout << cat->getType() << '\n';
	cat->makeSound();

	std::cout << "\n";

	delete ani;
	delete cat;
}

	return 0;

}