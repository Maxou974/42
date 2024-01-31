#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "constructor called for ScavTrap\n";
	_Hit_Points = 100;
	_Energy_Points = 50;
	_Attack_Damage = 20;
}

ScavTrap::ScavTrap()
{
	std::cout << "Default constructor called for ScavTrap\n";
	_Name = "random";
	_Hit_Points = 100;
	_Energy_Points = 50;
	_Attack_Damage = 20;
}

ScavTrap::~ScavTrap(){
	std::cout << "Destructor called fo ScavTrap\n";
}

ScavTrap::ScavTrap(const ScavTrap &ref) : ClapTrap(ref)
{
	std::cout << "Copy constructor called for ScavTrap\n";
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &ref)
{
	_Name = ref._Name;
	_Hit_Points = ref._Hit_Points;
	_Energy_Points = ref._Energy_Points;
	_Attack_Damage = ref._Attack_Damage;
	return *this;
}

void	ScavTrap::attack(const std::string &ref)
{
		std::cout << "Attack call: ";
	if (this->get_EP() > 0 && this->get_HP() > 0)
	{
		std::cout << "ScavTrap " << get_name() << " attacks " << ref;
		std::cout << ", causing " << get_AD() << " points of damage\n";
		_Energy_Points--;
	}
	else
		std::cout << "ScavTrap " << get_name() << " can not execute attack\n";
	//info();
}

void	ScavTrap::guardGate()
{
	if (get_HP() > 0)
		std::cout << "ScavTrap " << get_name() << " is now in mode Gate Keeper\n";
	else
		std::cout << "How can " << get_name() << " enter in mode gatekeeper if he is dead\n";
}