#ifndef CLAPTRAP_HPP
#define	CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
protected:
	std::string	_Name;
	int			_Hit_Points;
	int			_Energy_Points;
	int			_Attack_Damage;
public:
	ClapTrap(std::string);
	ClapTrap();
	~ClapTrap();
	ClapTrap(const ClapTrap &);
	ClapTrap&	operator=(const ClapTrap &);
	void		attack(const std::string &);
	void		takeDamage(unsigned int);
	void		beRepaired(unsigned int);
	void		info( void );
	std::string	get_name() const;
	int			get_HP() const;
	int			get_AD() const;
	int			get_EP() const;
};

#endif
