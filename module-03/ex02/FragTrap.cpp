/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/05 18:29:49 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/08/05 18:29:49 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <thread>
#include <chrono>

// ************************************************************************** //
//                        Constructors and Destructors                        //
// ************************************************************************** //

FragTrap::FragTrap(void) : ClapTrap("unnamed FragTrap")
{
	std::cout << CYN << " And they're a cool high fiving FragTrap" << RESET << std::endl;
	_health = 100;
	_energy = 100;
	_attack_damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << CYN << " And they're a cool high fiving FragTrap" << RESET << std::endl;
	_health = 100;
	_energy = 100;
	_attack_damage = 30;
}
FragTrap::FragTrap(const FragTrap &rhs)
{
	std::cout << GREEN << "FragTrap: Copy constructor called" << RESET << std::endl;

	*this = rhs;
}

FragTrap &
FragTrap::operator=(const FragTrap &rhs)
{
	std::cout << GREEN << "FragTrap: Assignment operator called" << RESET << std::endl;

	if (this != &rhs)
	{
		_name = rhs._name;
		_health = rhs._health;
		_energy = rhs._energy;
		_attack_damage = rhs._attack_damage;
	}

	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << RED << "FragTrap: Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                                Public methods                              //
// ************************************************************************** //

void	FragTrap::high_five_loop()
{
	std::string me = "<(▼▽▼)っ";
	std::string you = "୧(^ ᵕ ^   )っ";
	std::string epic = "E P I C";
	int distance = 20;
	while (distance > 0)
	{
		system("clear");
		std::cout << me;
		for (int i = 0; i < distance; ++i) std::cout << " ";
		std::cout << you << std::endl;
		if (distance % 2)
			me.insert(0, 1, ' ');
		std::this_thread::sleep_for(std::chrono::milliseconds(20));
		distance--;
	}
}

void	FragTrap::stagger_print(std::string msg)
{
	for (size_t i = 0; msg[i]; i++)
	{
		std::cout << msg[i] << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(20));
	}
}

void	FragTrap::highFivesGuys(void)
{

	std::string response;
	std::cout << CYN << _name << RESET << " asks you for a high five"\
	"do you accept?\n (say anything but no)" << std::endl;
	std::cin >> response;
	if (response == "no")
	{
		std::cout << "What the heck bro :(" << std::endl;
		return;
	}
	high_five_loop();
	stagger_print("\t    ✨✨✨✨✨✨\n");
	stagger_print(YEL "\t    ✨E P I C ✨\n");
	stagger_print("\t    ✨✨✨✨✨✨\n\n\n");
	std::this_thread::sleep_for(std::chrono::seconds(1));


}
