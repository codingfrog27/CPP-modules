/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/07 18:01:14 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/08/07 18:01:14 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

#include "WrongAnimal.hpp"

// ************************************************************************** //
//                        Constructors and Destructors                        //
// ************************************************************************** //

WrongAnimal::WrongAnimal(void): type("generic animal")
{
	std::cout << GREEN << "WrongAnimal: Default constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &rhs)
{
	std::cout << GREEN << "WrongAnimal: Copy constructor called" << RESET << std::endl;

	*this = rhs;
}

WrongAnimal &
WrongAnimal::operator=(const WrongAnimal &rhs)
{
	std::cout << GREEN << "WrongAnimal: Assignment operator called" << RESET << std::endl;

	if (this != &rhs)
		type = rhs.type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << RED << "WrongAnimal: Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                                Public methods                              //
// ************************************************************************** //
void WrongAnimal::makeSound() const
{
	std::cout << "I am" CYN " an Animal" RESET " don't worry about it" << std::endl;
}

const std::string	&WrongAnimal::getType() const
{
	return (this->type);
}
