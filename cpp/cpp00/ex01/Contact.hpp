/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:27:33 by mabriel           #+#    #+#             */
/*   Updated: 2022/12/07 15:19:21 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

class Contact {
	
	std::string _firstname;
	std::string	_trimfirstname;
	std::string _lastname;
	std::string	_trimlastname;
	std::string _nickname;
	std::string	_trimnickname;
	std::string _phonenumber;
	std::string _secret;
		
public:

	void	set_firstname( void );
	void	set_lastname(void );
	void	set_nickname( void );
	void	set_phonenumber( void );
	std::string	set_trim( std::string );
	void	set_secret( void );
	void	show( void );
	void	search_show(int);
};

Contact createContact(void);

#endif