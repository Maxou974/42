#include "ClapTrap.hpp"
#include "FlagTrap.hpp"

int main()
{
	ClapTrap maxime("Maxime");
	FlagTrap mathou("Mathou");

	maxime.attack("random guy in street");

	mathou.highFiveGuys();
	mathou.attack("BITCH");
	mathou.beRepaired(-101);
	mathou.beRepaired(10);
	mathou.highFiveGuys();
}