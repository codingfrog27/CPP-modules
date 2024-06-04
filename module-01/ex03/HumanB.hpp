#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"


class HumanB
{
	private:
		std::string	name;
		Weapon *_violence_tool;
	public:
				HumanB (std::string setName);
				~HumanB ();
		void	setWeapon(Weapon &setWeapon);
		void	attack();
};

#endif // !
