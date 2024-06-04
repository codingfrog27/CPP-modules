#include "HumanB.hpp"

HumanB::HumanB (std::string setName)
: name(setName), _violence_tool(nullptr)
{
}

HumanB::~HumanB()
{
}

void	HumanB::attack()
{
	std::string	painbringer;
	if (!this->_violence_tool)
		painbringer = "their bare weaponless fists 😠";
	else
		painbringer = _violence_tool->getType();

	std::cout << this->name << " attacks with their " \
			<< painbringer << std::endl;
}


void	HumanB::setWeapon(Weapon &setWeapon)
{
	this->_violence_tool = &setWeapon;
}
