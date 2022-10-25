#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(const std::string &);
		~ScavTrap();
		ScavTrap(const ScavTrap &);
		ScavTrap&	operator=(const ScavTrap &);
		void	attack(const std::string &);
		void	guardGate();
};