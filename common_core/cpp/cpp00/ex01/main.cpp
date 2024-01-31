/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:48:33 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/05 23:20:48 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
	PhoneBook repertory;

	std::cout << "    WELCOME IN YOUR PHONEBOOK\n\n     You can use three command\n\n";
	std::cout << "    ADD to add a contact to your phonebook\n";
	std::cout << "    SEARCH to search a contact in your phonebook\n";
	std::cout << "    EXIT to exit the program\n\n";
	
	while (1)
	{
		std::cout << "> ";
		std::string	string;
		std::getline(std::cin, string);

		if (string == "ADD")
			repertory.add_contact();
		else if (string == "SEARCH")
			repertory.search_contact();
		else if (string == "EXIT")
			break;
		else
			std::cout << "Error: Wrong command\n";
	}
	return (0);
}
