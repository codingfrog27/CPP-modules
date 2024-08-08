
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/07 18:14:29 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/08/07 18:14:29 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// ************************************************************************** //
//                        Constructors and Destructors                        //
// ************************************************************************** //

WrongCat::WrongCat(void) : WrongAnimal()
{
	type = "Kitty (but something seems off)";
	std::cout << GREEN << "🐱: Default constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &rhs)
{
	std::cout << GREEN << "🐱: Copy constructor called" << RESET << std::endl;

	*this = rhs;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
	std::cout << GREEN << "🐱: Assignment operator called" << RESET << std::endl;

	if (this != &rhs)
	{
		type = rhs.type;
	}
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << RED << "🐱: Destructor called" << RESET << std::endl;
}


// ************************************************************************** //
//                                Public methods                              //
// ************************************************************************** //

void WrongCat::makeSound() const
{
	std::cout << MAG "Miauw 🐱🐱🐱🐈🐈🐈" RESET << std::endl;
}
