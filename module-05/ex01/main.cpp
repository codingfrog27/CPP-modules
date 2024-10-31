/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coding_frog <coding_frog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:24:11 by mde-cloe          #+#    #+#             */
/*   Updated: 2024/10/30 19:21:23 by coding_frog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	//include niceprint from ex04 and make the start and end their own funcs
	try
	{
		Bureaucrat officeCoreEnjoyer("Bob", 200);
		std::cout << officeCoreEnjoyer << ": \"I love imagine dragons!!\"" << std::endl;
		// a lot more tests, icluding in and decrement
	}

	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << '\n'; 
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "too low exception!" << std::endl;
		std::cerr << e.what() << '\n'; 
	}

	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'; 
		//see how much work it'd be to pass the bureaucrats name to the exception
		// and mb catch toohigh and toolow instead of just generic exception (or all 3 for showing)
	}
	

	return (0);
}