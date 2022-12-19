/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:17:11 by mabriel           #+#    #+#             */
/*   Updated: 2022/12/19 15:27:19 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <cstring>
#include "Brain.hpp"

class Animal
{
protected:
	std::string type;

public:
	Animal();
	Animal(std::string type);
	Animal(const Animal &);
	Animal&	operator=(const Animal &);
	~Animal();
	virtual void		makeSound() = 0;
	virtual std::string	get_ideas(int) = 0;
	virtual void	set_brain(std::string&) = 0;
	const std::string&	getType()const;
};

#endif