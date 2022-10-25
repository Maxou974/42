#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap maxime("Maxime");
	FragTrap mathou("Mathou");

	maxime.attack("random guy in street");

	mathou.highFiveGuys();
	mathou.attack("BITCH");
	mathou.beRepaired(-101);
	mathou.beRepaired(10);
	mathou.highFiveGuys();
}