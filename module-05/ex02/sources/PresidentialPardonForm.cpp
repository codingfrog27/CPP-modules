/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-cloe <mde-cloe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:02:34 by coding_frog       #+#    #+#             */
/*   Updated: 2024/11/25 15:24:22 by mde-cloe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// ************************************************************************** //
//                        Constructors and Destructors                        //
// ************************************************************************** //

PresidentialPardonForm::PresidentialPardonForm(std::string target)\
: AForm("Hitchhiker reference form", target, 25, 5)
{
	std::cout << GREEN << "PresidentialPardonForm: Default constructor called" << RESET << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs) \
: AForm(rhs){
	std::cout << GREEN << "PresidentialPardonForm: Copy constructor called" << RESET << std::endl;
}


PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << RED << "PresidentialPardonForm: Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                                Public methods                              //
// ************************************************************************** //




void	PresidentialPardonForm::executeAction() const
{
	std::cout << getTarget() << " has been pardoned by " CYN "Zaphod Beeblebrox" RESET << std::endl;
}