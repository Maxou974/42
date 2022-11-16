/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:11:40 by mabriel           #+#    #+#             */
/*   Updated: 2022/11/16 18:37:54 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ar, char **av)
{
	if (ar == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		int i = 0, j;
		while (av[++i])
		{
			j = -1;
			while (av[i][++j])
			{
				if (av[i][j] <= 'z' && av[i][j] >= 'a')
					std::cout << static_cast<char>(std::toupper(av[i][j]));
				else
					std::cout << av[i][j];
			}
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	return (0);
}