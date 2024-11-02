/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coding_frog <coding_frog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:24:11 by mde-cloe          #+#    #+#             */
/*   Updated: 2024/11/02 01:08:20 by coding_frog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "NicePrint.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{

	//make 3 classes
	//ah maybe Aform needs a default constructor now?
	//impliment execute Form in bureacrat
	//make a form not signed excep class in form or bureau
	
	ShrubberyCreationForm shrubForm("test.txt");
	Bureaucrat bigBoss("obamna", 1);
	bigBoss.signForm(shrubForm);
	bigBoss.executeForm(shrubForm); //test ranks too low/ not signed and file not found exceptions




	// so.. I concidered the best way for execute form err printing, making execute form a friend function of AForm
	// seems like it would work the best, but that being forbidden, execute is now not fully exception safe if execute gets called by itself 
	//cause i want the bureacrat the catch the exceptions for specific error messages, i could return an enum for every possible err
	// but seems against spirit of exercise

	//maybe give the exceptions a constructor with a name to pass in the what() function

	
	return (0);
}
// abstract classes = class with at least 1 PURE VIRTUAL function (only decleration no definition, defined by declaration = 0)
// can not be instantiated, only inherited from
// if all member functions pure virtual and no nonstatic data members it is an ✨Interface✨