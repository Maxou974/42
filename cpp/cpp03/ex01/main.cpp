#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap maxime("Maxime");
	ScavTrap mathou("mathou");

	std::cout << "\n\n";

	maxime.attack("random guy in street");

	mathou.attack("random girl");
	mathou.beRepaired(10);
	mathou.guardGate();
	mathou.takeDamage(23324);
	mathou.beRepaired(10);
	mathou.guardGate();

	std::cout << "\n\n";
}