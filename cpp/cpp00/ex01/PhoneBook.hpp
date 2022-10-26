/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:27:39 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/25 19:11:36 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#define MAX_CONTACT 8

class PhoneBook {
	
	Contact	_contact[MAX_CONTACT];
	int		_contact_nbr;

	public:

		PhoneBook();
		void	init_contact_nbr( void );
		void	add_contact ( void );
		void	search_contact( void );
		void	show_all( void );
		void	show_one(int index);
};

#endif