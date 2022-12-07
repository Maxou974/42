/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:08:50 by mabriel           #+#    #+#             */
/*   Updated: 2022/12/07 17:38:51 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>
#include <string>

class AMateria;

class ICharacter
{
public:
virtual ~ICharacter() {}
virtual std::string const & getName() const = 0;
virtual void equip(AMateria* m) = 0;
virtual void unequip(int idx) = 0;
virtual void use(int idx, ICharacter& target) = 0;
};

#endif