/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-cloe <mde-cloe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:24:11 by mde-cloe          #+#    #+#             */
/*   Updated: 2024/10/31 17:39:38 by mde-cloe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "NicePrint.hpp"

int main(void)
{
	NicePrint printer;
	printer.greeter();

	try
	{
		Form	tooLow("random recycling paper", 200);
		std::cout << "I shall never be printed" << std::endl;
	}
	catch(const std::exception& e)
	{
	 //can change to Bureaucrat to show program crash if not caught b4 next try
		std::cerr << e.what() << '\n';
	}
	printer.promptEnter();
	try{
		Bureaucrat officeCoreEnjoyer("Bob", 150); //151
		Bureaucrat coolguy("Icarus", 5);
		Form	lowForm("random paperwork", 150);
		Form	highForm("important documents", 5);

		officeCoreEnjoyer.signForm(lowForm);
		officeCoreEnjoyer.signForm(highForm);
		
		coolguy.signForm(highForm);
	}
	catch (Form::GradeTooLowException &e)	{
		std::cerr << "too low exception!" << e.what() << '\n'; 
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << '\n'; 
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n'; 
	}
	
	return (0);
}
	//fun fact, try has it's own scope (like an i made in a for loop)

//(mini rant) bad subject design for signForm cause can only be 1 reason and cant even
// specify that it's the the bureaucrat that's too low 
//cause i need to throw form::toolow which also needs to be used for faulty form construction 