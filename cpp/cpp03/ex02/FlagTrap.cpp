#include "FlagTrap.hpp"

FlagTrap::FlagTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "constructor called for FlagTrap\n";
	this->set_HP(100);
	this->set_EP(100);
	this->set_AD(30);
}

FlagTrap::~FlagTrap(){
	std::cout << "Destructor called fo FlagTrap\n";
}

FlagTrap::FlagTrap(const FlagTrap &ref) : ClapTrap(ref)
{
	std::cout << "Copy constructor called for FlagTrap\n";
}

FlagTrap&	FlagTrap::operator=(const FlagTrap &ref)
{
	this->set_name(ref.get_name());
	this->set_HP(ref.get_HP());
	this->set_EP(ref.get_EP());
	this->set_AD(ref.get_AD());
	return *this;
}

void	FlagTrap::attack(const std::string &ref)
{
		std::cout << "Attack call: ";
	if (this->get_EP() > 0 && this->get_HP() > 0)
	{
		std::cout << "FlagTrap " << get_name() << " attacks " << ref;
		std::cout << ", causing " << get_AD() << " points of damage\n";
		set_EP(get_EP() - 1);
	}
	else
		std::cout << "FlagTrap " << get_name() << " can not execute attack\n";
	info();
}

void	FlagTrap::highFiveGuys( void )
{
	if (get_HP() > 0)
		std::cout << "FlagTrap " << get_name() << " wants a high five with u\n";
	else
		std::cout << "How can " << get_name() << " high five if he is dead\n";
}