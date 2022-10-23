#ifndef CLAPTRAP_HPP
#define	CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
private:
	std::string	_Name;
	int			_Hit_Points;
	int			_Energy_Points;
	int			_Attack_Damage;
public:
	ClapTrap(std::string);
	~ClapTrap();
	ClapTrap(const ClapTrap &);
	ClapTrap&	operator=(const ClapTrap &);
	std::string	get_name();
	void		attack(const std::string &);
	void		takeDamage(unsigned int);
	void		beRepaired(unsigned int);
	void		info( void );
};

#endif
