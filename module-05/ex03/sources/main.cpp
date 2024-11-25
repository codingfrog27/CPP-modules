/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-cloe <mde-cloe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:24:11 by mde-cloe          #+#    #+#             */
/*   Updated: 2024/11/25 18:27:28 by mde-cloe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NicePrint.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(void)
{

	Intern poorSoul;

	AForm *shrubby = poorSoul.makeForm("shrubby form", "shrubfile");


		Bureaucrat 				junior("steve", 130);
		junior.signForm(*shrubby);
		junior.executeForm(*shrubby);

	delete (shrubby);
	// NicePrint printOBJ;
	// try
	// {


	// 	Bureaucrat 				manager("janine", 45);
	// 	Bureaucrat 				bigBoss("obamna", 1);
	// 	ShrubberyCreationForm	shrubForm("forest");
	// 	RobotomyRequestForm		cyborgForm("Elon musk fanboy");
	// 	PresidentialPardonForm	PardonForm("your mom (haHA)");

		
	// 	printOBJ.promptEnter();
	// 	bigBoss.executeForm(shrubForm);
	// 	junior.executeForm(shrubForm);

	// 	printOBJ.promptEnter();
	// 	manager.signForm(cyborgForm);
	// 	manager.executeForm(cyborgForm);


	// 	printOBJ.promptEnter();
	// 	manager.signForm(PardonForm);
	// 	bigBoss.signForm(PardonForm);
	// 	bigBoss.executeForm(PardonForm);
	// 	printOBJ.promptEnter();	


	// }
	// catch (Bureaucrat::GradeTooLowException &e)	{
	// 	std::cerr << "Bureacrat exception: " << e.what() << '\n';
	// }
	// catch (Bureaucrat::GradeTooHighException &e) {
	// 	std::cerr << "Bureacrat exception: " << e.what() << '\n';
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	





	
	return (0);
}
// so.. I concidered the best way for execute form err printing, making execute form a friend function of AForm
// seems like it would work the best, but that being forbidden, execute is now not fully exception safe if execute gets called by itself 
//cause i want the bureacrat the catch the exceptions for specific error messages, i could return an enum for every possible err
// but seems against spirit of exercise

//maybe give the exceptions a constructor with a name to pass in the what() function



// abstract classes = class with at least 1 PURE VIRTUAL function (only decleration no definition, defined by declaration = 0)
// can not be instantiated, only inherited from
// if all member functions pure virtual and no nonstatic data members it is an ✨Interface✨