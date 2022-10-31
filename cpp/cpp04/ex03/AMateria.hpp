/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:25:08 by mabriel           #+#    #+#             */
/*   Updated: 2022/10/31 19:44:10 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "Header.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string _type;
public:
AMateria(std::string const & type);
AMateria();
AMateria&	operator=(const AMateria &);
virtual ~AMateria();

std::string const & getType() const; //Returns the materia type
virtual AMateria* clone() const = 0;
virtual void use(ICharacter& target);
};

#endif