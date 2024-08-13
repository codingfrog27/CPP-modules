/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/07 18:01:14 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/08/07 18:01:14 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#include "Animal.hpp"

// ************************************************************************** //
//                        Constructors and Destructors                        //
// ************************************************************************** //

Animal::Animal(void): type("generic animal")
{
	std::cout << GREEN << "Animal: Default constructor called" << RESET << std::endl;
}

Animal::Animal(const Animal &rhs)
{
	std::cout << GREEN << "Animal: Copy constructor called" << RESET << std::endl;

	*this = rhs;
}

Animal &
Animal::operator=(const Animal &rhs)
{
	std::cout << GREEN << "Animal: Assignment operator called" << RESET << std::endl;

	if (this != &rhs)
		type = rhs.type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << RED << "Animal: Destructor called" << RESET << std::endl;
}
// ************************************************************************** //
//                                Public methods                              //
// ************************************************************************** //

void Animal::makeSound() const
{
	std::cout << "I am" CYN " an animal" RESET " don't worry about it" << std::endl;
}

const std::string	&Animal::getType() const
{
	return (this->type);
}
