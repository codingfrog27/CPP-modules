/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-cloe <mde-cloe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:02:34 by coding_frog       #+#    #+#             */
/*   Updated: 2024/11/25 15:21:54 by mde-cloe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// ************************************************************************** //
//                        Constructors and Destructors                        //
// ************************************************************************** //

RobotomyRequestForm::RobotomyRequestForm(std::string target)\
 : AForm("at least it's not straight up lobotomy form", target, 72, 5)
{
	std::cout << GREEN << "RobotomyRequestForm: Default constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs) \
: AForm(rhs){
	std::cout << GREEN << "RobotomyRequestForm: Copy constructor called" << RESET << std::endl;
}


RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << RED << "RobotomyRequestForm: Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                                Public methods                              //
// ************************************************************************** //




void	RobotomyRequestForm::executeAction() const
{
	//random 50% then print one or other	
}