/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:21:56 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/26 21:28:08 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	private:
		Brain* _Brain;
	public:
		Dog();
		Dog(const Dog &);
		Dog& operator=(const Dog &);
		~Dog();
		void	makeSound()const;
		void	set_brain(std::string&);
		std::string	get_ideas(int);
};

#endif