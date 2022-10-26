#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	_Name;
	public:
		DiamondTrap(const std::string &);
		~DiamondTrap();
		DiamondTrap(const DiamondTrap &);
		DiamondTrap&	operator=(const DiamondTrap &);
		void	attack(const std::string &ref);
		void	info();
		void	whoAmI();
};

#endif