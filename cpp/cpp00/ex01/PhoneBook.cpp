/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:56:45 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/05 23:16:18 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"



void	PhoneBook::show_all( void )
{
	std::cout << "Showing all contact\n";
}

void	PhoneBook::show_one(int index)
{
	(void)index;
	std::cout << "Showing one contact\n";
}

void	PhoneBook::add_contact( void )
{
	static int nbr = 0;

	if (_contact_nbr == MAX_CONTACT && nbr == MAX_CONTACT)
		nbr = 0;
	if (_contact_nbr == MAX_CONTACT)
		this->_contact_nbr--;
	if (_contact_nbr < MAX_CONTACT)
	{
		this->_contact[nbr] = createContact();
		this->_contact_nbr++;
		nbr++;
	}
}

void	head( void )
{
	std::cout << "|     index| firstname|  lastname|  nickname|\n";
	std::cout << "---------------------------------------------\n";
}

void	PhoneBook::search_contact( void )
{
	int	i = 0;
	head();
	while (i < this->_contact_nbr)
	{
		_contact[i].search_show(i+1);
		i++;
	}
	std::cout << "Enter the index of a contact to show its details\nSEARCH> ";
	while (1)
	{
		std::string	string;
		std::getline(std::cin, string);
		int	index = atoi(string.c_str());
		if (index <= 0 || index > this->_contact_nbr)
		{
			std::cout << "Wrong index Try again\nSEARCH> ";
		}
		else
		{
			_contact[index - 1].show();
			break;
		}
	}
	
}

PhoneBook::PhoneBook()
{
	this->_contact_nbr = 0;
}
