/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-cloe <mde-cloe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:24:11 by mde-cloe          #+#    #+#             */
/*   Updated: 2024/10/31 16:48:10 by mde-cloe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "NicePrint.hpp"

int main(void)
{
	NicePrint printer;
	printer.greeter();
	try{
		Bureaucrat officeCoreEnjoyer("Bob", 150); //151
		std::cout << officeCoreEnjoyer << ": \"I love imagine dragons!!\"" << std::endl;
		
		Bureaucrat coolguy("Icarus", 5);
		std::cout << coolguy << std::endl;
		for (size_t i = 0; i < 5; i++)
			coolguy.Increment();
	}
	catch (Bureaucrat::GradeTooLowException &e)	{
		std::cerr << "too low exception!\n" << e.what() << '\n'; 
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << "too high exception\n" << e.what() << '\n'; 
	}
	catch(const std::exception& e) {
		std::cerr << "generic exception\n" << e.what() << '\n'; 
	}
	

	return (0);
}