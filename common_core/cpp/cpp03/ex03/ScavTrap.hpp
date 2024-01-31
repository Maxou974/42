#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(const std::string &);
		ScavTrap();
		~ScavTrap();
		ScavTrap(const ScavTrap &);
		ScavTrap&	operator=(const ScavTrap &);
		void	attack(const std::string &);
		void	guardGate();
};

#endif