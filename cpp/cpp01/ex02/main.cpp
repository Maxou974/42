/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:04:26 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/11 18:15:03 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";

	std::string *stringPTR = &str;

	std::string &stringREF = str;

	std::cout << "adresse str      : " << &str << std::endl;
	std::cout << "adresse stringPTR: " << stringPTR << std::endl;
	std::cout << "adresse stringREF: " << &stringREF << std::endl;

	std::cout << str << std::endl << *stringPTR << std::endl << stringREF<< std::endl;
}