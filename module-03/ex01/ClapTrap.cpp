#include "ClapTrap.hpp"

// ************************************************************************** //
//                        Constructors and Destructors                        //
// ************************************************************************** //

ClapTrap::ClapTrap() : _name("Unnamed ClapTrap"), _health(10), _energy(10), _attack_damage(0)
{
	std::cout << GREEN << "ClapTrap " << MAG << _name << GREEN  << " LIVES" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string Name) : _name(Name), _health(10), _energy(10), _attack_damage(0)
{
	std::cout << GREEN << "ClapTrap " << MAG << _name << GREEN  << " LIVES" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &rhs)
{
	std::cout << GREEN << "ClapTrap Copy constructor called" << RESET << std::endl;

	*this = rhs;
}

ClapTrap &
ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << GREEN << "ClapTrap Assignment operator called" << RESET << std::endl;

	if (this != &rhs)
	{
		_name = rhs._name;
		_health = rhs._health;
		_energy = rhs._energy;
		_attack_damage = rhs._attack_damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << RED << "ClapTrap " << MAG <<  _name << RED << \
	" bids you adieu" << RESET << std::endl;
}

// ************************************************************************** //
//                                Public methods                              //
// ************************************************************************** //

	void	ClapTrap::attack(const std::string& target)
	{
		if (!hasEnergy() || !isAlive())
			return;
		_energy--;
		std::cout << MAG <<  _name << RESET << " attacks " << target \
		<< " causing " << _attack_damage << " points of damage!" << std::endl;

	}
	void	ClapTrap::takeDamage(unsigned int amount)
	{
		std::cout << MAG <<  _name << RESET << " gets hurt for " \
		<< amount << " points of damage!" << std::endl;
		if (amount > _health)
		{
			_health = 0;
			std::cout << "\t\t\n..and DIES 😭💔\n" << std::endl;
		}
		else
			_health += amount;
	}
	void	ClapTrap::beRepaired(unsigned int amount)
	{
		if (!hasEnergy() || !isAlive())
			return;
		_energy--;
		std::cout << MAG <<  _name << RESET << " heals " << amount \
		<< " of health back! ⚡" << std::endl;
		if (_health + amount >= 10)
		{
			_health = 10;
			std::cout << "...and is fully repaired! B)" << std::endl;
		}
		else
			_health += amount;
	}

bool	ClapTrap::hasEnergy(void)
{
	if (_energy == 0)
	{
		std::cout << MAG <<  _name << RESET << \
		" does not have enough juice to attack or replair itself 😔" << std::endl;
		return (false);
	}
	return (true);
}

bool	ClapTrap::isAlive(void)
{
	if (_health == 0)
	{
		std::cout << MAG <<  _name << RESET << \
		" can't do anything cause they died 💀" << std::endl;
		return (false);
	}
	return (true);
}
