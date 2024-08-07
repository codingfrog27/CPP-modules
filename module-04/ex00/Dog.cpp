/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/07 18:17:09 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/08/07 18:17:09 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// ************************************************************************** //
//                        Constructors and Destructors                        //
// ************************************************************************** //

Dog::Dog(void) : Animal()
{
	std::cout << GREEN << "Dog: Default constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog &rhs)
{
	std::cout << GREEN << "Dog: Copy constructor called" << RESET << std::endl;

	*this = rhs;
}

Dog &Dog::operator=(const Dog &rhs)
{
	std::cout << GREEN << "Dog: Assignment operator called" << RESET << std::endl;

	if (this != &rhs)
	{
		type = rhs.type;
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << RED << "Dog: Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                                Public methods                              //
// ************************************************************************** //

void Dog::makeSound()
{
	std::cout << YEL "Woof Woof! 🐶🐶🐶 I aint just got that dog in me" \
	"I AM THAT DOG I AM HIM WOOF WOOF" RESET << std::endl;
}
