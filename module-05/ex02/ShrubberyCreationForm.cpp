/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coding_frog <coding_frog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:02:34 by coding_frog       #+#    #+#             */
/*   Updated: 2024/11/02 00:59:49 by coding_frog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>


// ************************************************************************** //
//                        Constructors and Destructors                        //
// ************************************************************************** //

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("shrubby form", target, 145, 137){
	std::cout << GREEN << "ShrubberyCreationForm: Default constructor called" << RESET << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs) \
: AForm(rhs){
	std::cout << GREEN << "ShrubberyCreationForm: Copy constructor called" << RESET << std::endl;
}


ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << RED << "ShrubberyCreationForm: Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                                Public methods                              //
// ************************************************************************** //




void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	checkExecRights(executor);
	std::ofstream file(getTarget() + "_shrubbery");
	if (!file) //is open?
		throw (std::runtime_error("Couldn't open file"));
	file << ASCII_TREE;
	file.close(); //check?
}