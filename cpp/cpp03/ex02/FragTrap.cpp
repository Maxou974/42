#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "constructor called for FragTrap\n";
	this->set_HP(100);
	this->set_EP(100);
	this->set_AD(30);
}

FragTrap::~FragTrap(){
	std::cout << "Destructor called fo FragTrap\n";
}

FragTrap::FragTrap(const FragTrap &ref) : ClapTrap(ref)
{
	std::cout << "Copy constructor called for FragTrap\n";
}

FragTrap&	FragTrap::operator=(const FragTrap &ref)
{
	this->set_name(ref.get_name());
	this->set_HP(ref.get_HP());
	this->set_EP(ref.get_EP());
	this->set_AD(ref.get_AD());
	return *this;
}

void	FragTrap::attack(const std::string &ref)
{
		std::cout << "Attack call: ";
	if (this->get_EP() > 0 && this->get_HP() > 0)
	{
		std::cout << "FragTrap " << get_name() << " attacks " << ref;
		std::cout << ", causing " << get_AD() << " points of damage\n";
		set_EP(get_EP() - 1);
	}
	else
		std::cout << "FragTrap " << get_name() << " can not execute attack\n";
	info();
}

void	FragTrap::highFiveGuys( void )
{
	if (get_HP() > 0)
		std::cout << "FragTrap " << get_name() << " wants a high five with u\n\n";
	else
		std::cout << "How can " << get_name() << " high five if he is dead\n\n";
}

void	FragTrap::info()
{
	std::cout << "INFO: FragTrap " << get_name() << ": " << get_HP() << " Hp   ";
	std::cout << get_EP() << " Ep   " << get_AD() << " Ad\n\n";
}