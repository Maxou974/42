#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "constructor called for ScavTrap\n";
	this->set_HP(100);
	this->set_EP(50);
	this->set_AD(20);
}

ScavTrap::ScavTrap()
{
	std::cout << "Constructor called for Random ScavTrap\n";
	this->set_HP(100);
	this->set_EP(50);
	this->set_AD(20);
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
	this->set_name(ref.get_name());
	this->set_HP(ref.get_HP());
	this->set_EP(ref.get_EP());
	this->set_AD(ref.get_AD());
	return *this;
}

void	ScavTrap::attack(const std::string &ref)
{
		std::cout << "Attack call: ";
	if (this->get_EP() > 0 && this->get_HP() > 0)
	{
		std::cout << "ScavTrap " << get_name() << " attacks " << ref;
		std::cout << ", causing " << get_AD() << " points of damage\n";
		set_EP(get_EP() - 1);
	}
	else
		std::cout << "ClapTrap " << get_name() << " can not execute attack\n";
	info();
}

void	ScavTrap::guardGate()
{
	if (get_HP() > 0)
		std::cout << "ScavTrap " << get_name() << " is now in mode Gate Keeper\n";
	else
		std::cout << "How can " << get_name() << " enter in mode gatekeeper if he is dead\n";
}