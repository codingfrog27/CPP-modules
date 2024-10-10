/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-cloe <mde-cloe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:17:09 by mde-cloe          #+#    #+#             */
/*   Updated: 2024/08/30 17:27:38 by mde-cloe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// ************************************************************************** //
//                        Constructors and Destructors                        //
// ************************************************************************** //

Dog::Dog(void) : Animal()
{
	std::cout << GREEN << "🐶: Default constructor called" << RESET << std::endl;
	type = "Doggo"; //can't init list cause its part of animal
	_brain = new Brain;
}

Dog::Dog(const Dog &rhs)
{
	std::cout << GREEN << "🐶: Copy constructor called" << RESET << std::endl;
	type = rhs.type;
	_brain = new Brain;
	_brain = rhs._brain;
}

Dog &Dog::operator=(const Dog &rhs)
{
	std::cout << GREEN << "🐶: Assignment operator called" << RESET << std::endl;

	if (this != &rhs)
	{
		type = rhs.type;
		_brain = rhs._brain;
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << RED << "🐶: Destructor called" << RESET << std::endl;
	delete _brain;
}

// ************************************************************************** //
//                                Public methods                              //
// ************************************************************************** //

void Dog::makeSound() const
{
	std::cout << YEL "🐶🐶🐶 Woof Woof! 🐶🐶🐶" RESET " I aint just got that dog in me" \
	YEL" I AM THE DOG WOOF WOOF" RESET << std::endl;
}

void Dog::useBrain(int i) const
{
	std::cout << _brain->getIdea(i) << std::endl;
}

void	Dog::printBrainAdress() const
{
	std::cout << "Brain adress == " << &_brain << std::endl;
}
