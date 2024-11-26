/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-cloe <mde-cloe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:02:34 by coding_frog       #+#    #+#             */
/*   Updated: 2024/11/26 13:44:14 by mde-cloe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>


// ************************************************************************** //
//                        Constructors and Destructors                        //
// ************************************************************************** //

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubby form", target, 145, 137){
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




void	ShrubberyCreationForm::executeAction() const
{
	try
	{
		std::ofstream file(getTarget() + "_shrubbery");
		if (!file)
			throw (std::runtime_error("Couldn't open file"));
		file << ASCII_TREE << ASCII_TREE << ASCII_TREE;
		file.close(); //check?
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception when writing shrubs: " << e.what() << '\n';
	}
	
}