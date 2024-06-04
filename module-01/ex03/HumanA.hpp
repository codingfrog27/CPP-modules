#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"



class Weapon;

class HumanA
{
	private:
		std::string	name;
		Weapon _violence_tool;
	public:
				HumanA(std::string setName, Weapon &set_violence_tool);
				~HumanA();
		void	attack();
};

#endif // !
