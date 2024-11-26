/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-cloe <mde-cloe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:51:01 by mde-cloe          #+#    #+#             */
/*   Updated: 2024/11/26 13:47:36 by mde-cloe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// ************************************************************************** //
//                        Constructors and Destructors                        //
// ************************************************************************** //

Intern::Intern(void)
{
	std::cout << GREEN << "Intern: Default constructor called" << RESET << std::endl;
}

Intern::Intern(const Intern &rhs)
{
	std::cout << GREEN << "Intern: Copy constructor called" << RESET << std::endl;

	*this = rhs;
}

Intern &
Intern::operator=(const Intern &rhs)
{
	std::cout << GREEN << "Intern: Assignment operator called" << RESET << std::endl;

	if (this != &rhs)
	{
		// no data members xd
	}

	return (*this);
}

Intern::~Intern(void)
{
	std::cout << RED << "Intern: Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                                Public methods                              //
// ************************************************************************** //


AForm *Intern::makeForm(std::string formName, std::string target) const
{
	std::string formOptions[3] = {"Shrubby form", "Robotomy Form", "Presidential pardon form"};
	for (size_t i = 0; i < 3; i++)
	{
		if (formName == formOptions[i])
		{
			std::cout << "the intern is creating a " << formOptions[i] << std::endl;
			switch (i)
			{
			case 0:
				return new ShrubberyCreationForm(target);
			case 1:
				return new RobotomyRequestForm(target);
			case 2:
				return new PresidentialPardonForm(target);
			}
		}
	}
	throw Intern::NonexistingForm();
}

const char	*Intern::NonexistingForm::what() const noexcept
{
	return ("Im just an intern, please give me an existing form.\nMy " \
	"life is hard enough as it is. 😔");
}