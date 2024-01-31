/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 20:11:50 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/05 23:09:35 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

static int check_empty(std::string string)
{
	if (string[0] == 0)
	{
		std::cout << "Can not be empty" << std::endl;
		return (1);
	}
	return (0);
}

static int	check_name(std::string string)
{
	int i = 0;

	while (string[i])
	{
		if ( !isalpha((int)string[i]) && string[i] != ' ')
		{
			std::cout << "Error: Invalid char in name\n"; 
			return (1);
		}
		i++;
	}
	return (0);
}

static int	check_phone_number(std::string string)
{
		int i = 0;

	while (string[i])
	{
		if ( !isdigit(string[i]) )
		{
			std::cout << "Error: Invalid char in number\n"; 
			return (1);
		}
		i++;
	}
	return (0);
}

void	Contact::set_firstname( void )
{
	do	{
		std::cout << "Enter Firstname: ";
		std::getline(std::cin, this->_firstname);
	} while (check_empty(this->_firstname) || check_name(this->_firstname));
	this->_trimfirstname = this->set_trim(_firstname);
}

void	Contact::set_lastname( void )
{
	do	{
		std::cout << "Enter Lastname: ";
		std::getline(std::cin, this->_lastname);
	} while (check_empty(this->_lastname) || check_name(this->_lastname));
	this->_trimlastname = this->set_trim(_lastname);
}

void	Contact::set_nickname( void )
{
	do	{
		std::cout << "Enter Nickname: ";
		std::getline(std::cin, this->_nickname);
	} while (check_empty(this->_nickname) || check_name(this->_nickname));
	this->_trimnickname = this->set_trim(_nickname);
}

void	Contact::set_phonenumber( void )
{
	do	{
		std::cout << "Enter Phonenumber: ";
		std::getline(std::cin, this->_phonenumber);
	} while (check_empty(this->_phonenumber) || check_phone_number(this->_phonenumber));
}

void	Contact::set_secret( void )
{
	do	{
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, this->_secret);
	} while (check_empty(this->_secret));
}

void	Contact::show( void )
{
	std::cout << "\n     Contact\nFirstname: "<< this->_firstname << std::endl;
	std::cout << "Lastname: " << this->_lastname << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phonenumber: " << this->_phonenumber << std::endl;
	std::cout << "Darkest secret: " << this->_secret << std::endl;
}

void	Contact::search_show(int index)
{
	std::cout << "|         " << index << "|";
	std::cout << this->_trimfirstname << "|" << this->_trimlastname << "|" << this->_trimnickname;
	std::cout << "|\n---------------------------------------------\n";
}

std::string	Contact::set_trim( std::string string )
{
	char str[11];
	std::string tmp;

	str[10] = 0;
	int	i = -1;
	if (string.size() > 10)
	{
		while (++i < 9)
			str[i] = string[i];
		str[i] = '.';
	}
	else
	{
		int	size = string.size() - 1;
		i = 9;
		while (size >= 0)
		{
			str[i] = string[size];
			size--;
			i--;
		}
		while (i >= 0)
		{
			str[i] = ' ';
			i--;
		}
	}
	return tmp = str;
}

Contact createContact( void )
{
	Contact	tmp;

 	tmp.set_firstname();
 	tmp.set_lastname();
 	tmp.set_nickname();
 	tmp.set_phonenumber();
 	tmp.set_secret();
	return (tmp);
}