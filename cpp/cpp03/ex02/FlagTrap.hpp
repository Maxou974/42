#include "ClapTrap.hpp"

class FlagTrap : public ClapTrap
{
	public:
		FlagTrap(const std::string &);
		~FlagTrap();
		FlagTrap(const FlagTrap &);
		FlagTrap&	operator=(const FlagTrap &);
		void	attack(const std::string &);
		void	highFiveGuys( void );
};