#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << name << ": NoOoOo I'm being destroyed 🧟👎 :(\n";
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...🧟👍 :)\n";
}

void	Zombie::setname(std::string name)
{
	this->name = name;
}
