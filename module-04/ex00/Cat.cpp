/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/07 18:14:29 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/08/07 18:14:29 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// ************************************************************************** //
//                        Constructors and Destructors                        //
// ************************************************************************** //

Cat::Cat(void) : Animal()
{
	std::cout << GREEN << "Cat: Default constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat &rhs)
{
	std::cout << GREEN << "Cat: Copy constructor called" << RESET << std::endl;

	*this = rhs;
}

Cat &Cat::operator=(const Cat &rhs)
{
	std::cout << GREEN << "Cat: Assignment operator called" << RESET << std::endl;

	if (this != &rhs)
	{
		type = rhs.type;
	}
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << RED << "Cat: Destructor called" << RESET << std::endl;
}


// ************************************************************************** //
//                                Public methods                              //
// ************************************************************************** //

void Cat::makeSound()
{
	std::cout << MAG "Miauw 🐱🐱🐱🐈🐈🐈" RESET << std::endl;
}
