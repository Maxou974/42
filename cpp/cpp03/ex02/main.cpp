#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap maxime("Maxime");
	FragTrap mathou("mathou");

	std::cout << "\n\n";

	maxime.attack("random guy in street");
	mathou.highFiveGuys();
	mathou.attack("random girl");
	mathou.beRepaired(10);
	mathou.highFiveGuys();
	mathou.takeDamage(1729);
	mathou.beRepaired(10);
	mathou.highFiveGuys();

	std::cout << "\n\n";
}