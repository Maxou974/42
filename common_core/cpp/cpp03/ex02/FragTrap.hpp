#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(const std::string &);
		FragTrap();
		~FragTrap();
		FragTrap(const FragTrap &);
		FragTrap&	operator=(const FragTrap &);
		void	attack(const std::string &);
		void	highFiveGuys( void );
		void	info();
};

#endif