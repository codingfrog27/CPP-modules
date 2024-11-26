/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-cloe <mde-cloe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:24:11 by mde-cloe          #+#    #+#             */
/*   Updated: 2024/11/26 13:46:39 by mde-cloe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NicePrint.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"


//decided to use another exception case rather then checking for nullpointers in spirit of exercise
// using unique pointers to avoid leaks :)
int main(void)
{
	try
	{
		NicePrint printOBJ;
		Bureaucrat 				junior("steve", 130);
		Bureaucrat 				manager("janine", 45);
		Bureaucrat 				bigBoss("obamna", 1);
		Intern 					poorSoul;
		std::unique_ptr<AForm>	shrubby(poorSoul.makeForm("Shrubby form", "shrubfile"));
		junior.signForm(*shrubby);
		junior.executeForm(*shrubby);
		printOBJ.promptEnter();

		
		std::unique_ptr<AForm>	surgery(poorSoul.makeForm("Robot form", "preem choom"));

		
		std::unique_ptr<AForm>	pardon(poorSoul.makeForm("Presidential pardon form" ,\
														"man freed from consequences"));
		std::unique_ptr<AForm>	fakeForm(poorSoul.makeForm("blabla", "whatever"));

		junior.signForm(*fakeForm);
	}
	catch(const Intern::NonexistingForm& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
	return (0);
}