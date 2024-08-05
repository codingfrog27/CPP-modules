/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/05 14:42:13 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/08/05 14:42:13 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// ************************************************************************** //
//                        Constructors and Destructors                        //
// ************************************************************************** //

//you can't use init lists to change inherited values!
// but you can specify which constructor of the base class you want to call
ScavTrap::ScavTrap() : ClapTrap("unnamed ScavTrap")
{
	std::cout << CYN << "and they're an extra beefy" << YEL << " ScavTrap"\
	<< RESET << std::endl;
	_health = 100;
	_energy = 50;
	_attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << CYN << "and they're an extra beefy" << YEL << " ScavTrap"\
	<< RESET << std::endl;
	_health = 100;
	_energy = 50;
	_attack_damage = 20;
}


ScavTrap::ScavTrap(const ScavTrap &rhs) : ClapTrap(rhs)
{
	std::cout << GREEN << "ScavTrap: Copy constructor called" << RESET << std::endl;

	*this = rhs;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	std::cout << GREEN << "ScavTrap: Assignment operator called" << RESET << std::endl;

	if (this != &rhs)
	{
		_name = rhs._name;
		_health = rhs._health;
		_energy = rhs._energy;
		_attack_damage = rhs._attack_damage;
	}

	return (*this);
}



ScavTrap::~ScavTrap(void)
{
	std::cout << RED << "ScavTrap: Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                                Public methods                              //
// ************************************************************************** //

void	ScavTrap::attack(const std::string& target)
	{
		if (!hasEnergy() || !isAlive())
			return;
		_energy--;
		std::cout << "ScavTrap " << MAG <<  _name << RESET \
		<< " uses it's strong form for violence and attacks " << YEL << target \
		<< RESET << " causing " << _attack_damage << " points of damage!" << std::endl;

	}

void	ScavTrap::guardGate()
{
	std::cout << MAG << _name << CYN << ": Aint nobody getting past this gate!! 😈"\
	<< RESET << std::endl;
}
