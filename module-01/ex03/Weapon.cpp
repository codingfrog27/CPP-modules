#include "Weapon.hpp"

Weapon::Weapon()
: type("default")
{
}

Weapon::Weapon(std::string setType)
{
	type = setType;
}

Weapon::~Weapon()
{
}

std::string const &Weapon::getType()
{
	return (type);
}

void			 Weapon::setType(std::string newType)
{
	type = newType;
}
