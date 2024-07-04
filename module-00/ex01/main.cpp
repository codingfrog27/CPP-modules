/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/05 17:06:45 by mde-cloe      #+#    #+#                 */
/*   Updated: 2023/12/05 17:06:45 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <unordered_map>


int	main(void)
{
	PhoneBook	Rad_Book;
	std::string	input;

	do
	{
		std::cout << C_GREEN << "\n\nEnter your action oh great Phonebook user: " << C_RESET;
		std::getline(std::cin, input);
		if (input == "ADD")
			Rad_Book.add_contact();
		else if (input == "SEARCH")
			Rad_Book.search();
		else if (input == "EXIT")
			break ;
		else
		{
			std::cout << C_RED << "\nPlease give a valid command, only available commands" \
					<< "ADD, SEARCH and EXIT\n\npress enter to continue" << C_RESET;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (!input.empty());
	return (0);
}
