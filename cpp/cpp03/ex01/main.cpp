#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap maxime("Maxime");
	ScavTrap mathou("Mathou");

	maxime.attack("random guy in street");

	mathou.attack("BITCH");
	mathou.beRepaired(-101);
	mathou.beRepaired(10);
	mathou.guardGate();
}