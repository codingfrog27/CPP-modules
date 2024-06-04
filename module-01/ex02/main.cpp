/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/04 13:53:11 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/06/04 13:53:11 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


int	main(void)
{
	std::string		msg = "HI THIS IS BRAIN";
	std::string		*stringPTR = &msg;
	std::string		&stringREF = msg;

	std::cout << "adress of our: \nstring: \t\t" << &msg << std::endl \
	<< "pointer:\t\t" << &stringPTR << std::endl << "and Reference:\t\t" \
	<< &stringREF << std::endl;

	std::cout << "\nand now: \n\nvalue of our string: \t" << msg << std::endl \
	<< "pointer:\t\t" << stringPTR << std::endl << "and Reference: \t\t" \
	<< stringREF;
	std::cout << "\n\nAs you can see, a reference is not a seperate variable\
	 as much as just an alias of the string, sharing the same adress and value:)\n";
	return (0);
}
