/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:36:21 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/30 16:05:59 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

#define SIZE 10

int main()
{
	Cat miaou;
	Dog woof;

	std::cout << '\n';
	woof.makeSound();
	miaou.makeSound();
	std::cout << '\n';
	//Animal oiseau;
	
	std::cout << woof.get_ideas(0) << '\n';
	std::string t="Booooooooonne";
	woof.set_brain(t);
	std::cout << woof.get_ideas(0) << '\n';
	std::cout << woof.get_ideas(99) << '\n';
	std::cout << '\n';

	Dog woof2 = woof;

	std::cout << '\n';

	Dog woof3;
	woof3 = woof;
	std::cout << '\n';
	std::cout << woof2.get_ideas(0) << '\n';
	std::cout << woof3.get_ideas(0) << "\n\n";

}