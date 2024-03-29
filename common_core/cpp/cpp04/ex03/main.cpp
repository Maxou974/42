/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabriel <mabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:58:31 by mabriel           #+#    #+#             */
/*   Updated: 2022/12/18 23:42:37 by mabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "MateriaSource.hpp"

int main()
{
	{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;
	}
	std::cout << '\n';
	{
	IMateriaSource* src = new MateriaSource();
	AMateria*	ice = new Ice();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(ice);
	src->learnMateria(ice);
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->equip(tmp);
	me->equip(tmp);
	me->equip(tmp);
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	
	delete bob;
	delete me;
	delete src;
	}
	std::cout << '\n';
	{
		MateriaSource src;
		MateriaSource copysrc;
		Character me = Character("me");
		src.learnMateria(new Cure());
		copysrc = src;
		AMateria* cure = copysrc.createMateria("cure");
		me.equip(copysrc.createMateria("ice"));
		me.equip(cure);
		std::cout << "me.use\n";
		me.use(0, me);
		Character copy;
		copy = me;
		std::cout << "copy.use(0)\n";
		copy.use(0, me);
		std::cout << "copy.use(1)\n";
		copy.use(1, me);
		delete cure;
		me.unequip(0);
		delete copy.get_Materia_ptr(0);
		copy.unequip(0);
		me.use(0, me);
		copy.use(0, me);
	}

	return 0;
}