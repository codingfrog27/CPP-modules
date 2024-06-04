#include "HumanA.hpp"

HumanA::HumanA(std::string setName, Weapon &set_violence_tool)
: name(setName), _violence_tool(set_violence_tool)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack()
{
	std::cout << name << " attacks with their " \
	<< this->_violence_tool.getType() << std::endl;
}
