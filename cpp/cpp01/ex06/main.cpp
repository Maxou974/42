/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:02:42 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/17 18:21:31 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

 int main(int argc, char **argv)
 {
	(void)argc;
	(void)argv;
	Harl test;
	if (argc == 2)
		test.complain(argv[1]);
	else
		std::cout << "pls enter one argument\n";
 }