/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:27:32 by mabriel           #+#    #+#             */
/*   Updated: 2022/12/07 17:21:46 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	private:
		Brain*	_Brain;
	public:
		Cat();
		Cat(const Cat &);
		Cat& operator=(const Cat &);
		~Cat();
		void	makeSound()const;
		void	set_brain(std::string&);
		std::string	get_ideas(int);
};

#endif