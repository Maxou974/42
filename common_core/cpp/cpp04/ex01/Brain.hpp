/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:04:15 by mabriel           #+#    #+#             */
/*   Updated: 2022/12/07 17:21:31 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"
#include <string>

class Brain{
	private:
		std::string _ideas[100];
	public:
		Brain();
		Brain(const Brain &);
		~Brain();
		Brain&	operator=(const Brain &);
		std::string&	get_ideas(int);
		void	set_ideas(int, const std::string);
};


#endif