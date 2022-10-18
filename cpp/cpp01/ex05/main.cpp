/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:02:42 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/17 17:43:31 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

 int main()
 {
	Harl test;

	test.complain("DEBUG");
	test.complain("Debug");
	test.complain("WARNING");
	test.complain("warning");
	test.complain("INFO");
	test.complain("qekwfj");
	test.complain("ERROR");
	test.complain("ERRORR");
 }