/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:02:36 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/17 17:44:04 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void )
{
	this->fct_names[0] = "DEBUG";
	this->fct_names[1] = "INFO";
	this->fct_names[2] = "WARNING";
	this->fct_names[3] = "ERROR";

	this->fct_ptrs[0] = &Harl::debug;
	this->fct_ptrs[1] = &Harl::info;
	this->fct_ptrs[2] = &Harl::warning;
	this->fct_ptrs[3] = &Harl::error;
}

void	Harl::debug( void )
{
	std::cout << "Debug message\n";
}

void	Harl::info( void )
{
	std::cout << "Info message\n";
}

void	Harl::error( void )
{
	std::cout << "error message\n";
}

void	Harl::warning( void )
{
	std::cout << "Warning message\n";
}

void	Harl::complain(std::string level)
{
	int	i = 0;

	while (i < 4)
	{
		if (level == fct_names[i])
		{
			(this->*fct_ptrs[i])();
			return;
		}
		i++;
	}
	std::cout << "level doesn't match any message\n";
}