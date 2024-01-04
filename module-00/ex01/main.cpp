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



void	exit_phonebook(){
	std::cout << PURPLE BOLD << "\n\n  ✨✨✨✨✨✨✨✨✨\n✨B Y E   C U T I E✨\n  ✨✨✨✨✨✨✨✨✨" << std::endl;
	std::exit(0);
}


void	greeting()
{
	std::cout << BOLD PURPLE << "\n\tW E L C O M E   T O\n" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "✨M Y" << std::flush;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "    C U T E" << std::flush;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "    P H O N E B O O K✨\n" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "you have 3 possible actions:	" << C_YELLOW "ADD	SEARCH	EXIT" << std::endl;
	 std::this_thread::sleep_for(std::chrono::seconds(1));
}

int	main(void){
	PhoneBook	Rad_Book;
	std::string	input;

	greeting();
	while (true)
	{
		std::cout << C_GREEN << "\n\nEnter your action oh great Phonebook user: " << C_RESET;
		std::getline(std::cin, input);
		if (input == "ADD")
			Rad_Book.add_contact();
		else if (input == "SEARCH")
			Rad_Book.search();
		else if (input == "EXIT")
			exit_phonebook();
		else
		{
			std::cout << C_RED << "\nPlease give a valid command, only available commands" \
					<< "ADD, SEARCH and EXIT\n\npress enter to continue" << C_RESET;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return (0);
}
// cin << ignores empty newlines, getline doesnt
// std::setw(10) << input;
		// std::right()
