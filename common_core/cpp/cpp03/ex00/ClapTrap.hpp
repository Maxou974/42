/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:47:54 by mabriel           #+#    #+#             */
/*   Updated: 2023/01/04 23:41:54 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define	CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
private:
	std::string	_Name;
	int			_Hit_Points;
	int			_Energy_Points;
	int			_Attack_Damage;
public:
	ClapTrap(std::string);
	ClapTrap();
	~ClapTrap();
	ClapTrap(const ClapTrap &);
	ClapTrap&	operator=(const ClapTrap &);
	std::string	get_name();
	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	void		info( void );
};

#endif
