/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-cloe <mde-cloe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:24:11 by mde-cloe          #+#    #+#             */
/*   Updated: 2024/10/31 19:32:05 by mde-cloe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "NicePrint.hpp"

int main(void)
{
	//form not signed excep class in form or bureau

	




	// NicePrint printer;
	// printer.greeter();

	// try
	// {
	// 	Form	tooLow("random recycling paper", 200);
	// 	std::cout << "I shall never be printed" << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	//  //can change to Bureaucrat to show program crash if not caught b4 next try
	// 	std::cerr << e.what() << '\n';
	// }
	// printer.promptEnter();
	// try{
	// 	Bureaucrat officeCoreEnjoyer("Bob", 150); //151
	// 	Bureaucrat coolguy("Icarus", 5);
	// 	Form	lowForm("random paperwork", 150);
	// 	Form	highForm("important documents", 5);

	// 	officeCoreEnjoyer.signForm(lowForm);
	// 	officeCoreEnjoyer.signForm(highForm);
		
	// 	coolguy.signForm(highForm);
	// }
	// catch (Form::GradeTooLowException &e)	{
	// 	std::cerr << "too low exception!" << e.what() << '\n'; 
	// }
	// catch (Bureaucrat::GradeTooHighException &e) {
	// 	std::cerr << e.what() << '\n'; 
	// }
	// catch(const std::exception& e) {
	// 	std::cerr << e.what() << '\n'; 
	// }
	
	// return (0);
}
// abstract classes = class with at least 1 PURE VIRTUAL function (only decleration no definition, defined by declaration = 0)
// can not be instantiated, only inherited from
// if all member functions pure virtual and no nonstatic data members it is an ✨Interface✨