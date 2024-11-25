/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   RobotomyRequestForm.cpp							:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mde-cloe <mde-cloe@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/01 22:02:34 by coding_frog	   #+#	#+#			 */
/*   Updated: 2024/11/25 16:58:50 by mde-cloe		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <random>

// ************************************************************************** //
//						Constructors and Destructors						//
// ************************************************************************** //

RobotomyRequestForm::RobotomyRequestForm(std::string target)\
 : AForm("Robotomy Form", target, 72, 45)
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
//								Public methods							  //
// ************************************************************************** //

void RobotomyRequestForm::executeAction() const
{
	std::random_device rd;

	if (rd() % 2)
		std::cout << RED "Robotomy failed! aAAAAAahHHhHH"  RESET << std::endl;
	else
		std::cout << GREEN "Robotomy successful! coolbeans" RESET << std::endl;
}