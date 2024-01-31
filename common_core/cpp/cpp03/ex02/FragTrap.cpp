#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "constructor called for FragTrap\n";
	_Hit_Points = 100;
	_Energy_Points = 100;
	_Attack_Damage = 30;
}

FragTrap::FragTrap()
{
	std::cout << "default constructor called for FragTrap\n";
	_Name = "Random FragTrap";
	_Hit_Points = 100;
	_Energy_Points = 100;
	_Attack_Damage = 30;
}

FragTrap::~FragTrap(){
	std::cout << "Destructor called for FragTrap\n";
}

FragTrap::FragTrap(const FragTrap &ref) : ClapTrap(ref)
{
	std::cout << "Copy constructor called for FragTrap\n";
}

FragTrap&	FragTrap::operator=(const FragTrap &ref)
{
	_Hit_Points = ref._Hit_Points;
	_Energy_Points = ref._Energy_Points;
	_Attack_Damage = ref._Attack_Damage;
	_Name = ref._Name;
	return *this;
}

void	FragTrap::attack(const std::string &ref)
{
		std::cout << "Attack call: ";
	if (this->get_EP() > 0 && this->get_HP() > 0)
	{
		std::cout << "FragTrap " << get_name() << " attacks " << ref;
		std::cout << ", causing " << get_AD() << " points of damage\n";
		_Energy_Points--;
	}
	else
		std::cout << "FragTrap " << get_name() << " can not execute attack\n";
	//info();
}

void	FragTrap::highFiveGuys( void )
{
	if (get_HP() > 0)
		std::cout << "FragTrap " << get_name() << " wants a high five with u\n";
	else
		std::cout << "How can " << get_name() << " high five if he is dead\n";
}

void	FragTrap::info()
{
	std::cout << "INFO: FragTrap " << get_name() << ": " << get_HP() << " Hp   ";
	std::cout << get_EP() << " Ep   " << get_AD() << " Ad\n\n";
}