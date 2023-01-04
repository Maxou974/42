#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap zaz("zaz");
	std::cout << '\n';
	//zaz.info();
	zaz.attack("random");
	zaz.beRepaired(100);
	zaz.takeDamage(1);
	zaz.guardGate();
	zaz.highFiveGuys();
	//zaz.info();
	zaz.whoAmI();
}