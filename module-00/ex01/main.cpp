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


void	search(){

}
void	add(){

}
void	exit_phonebook(){
	std::cout << "doei\n";
	std::exit(0);
}

// int	main(int argc, char **argv){
// 	PhoneBook	Rad_Book;
// 	std::string	input;

// 	std::unordered_map<std::string, void (PhoneBook::*)()> input_map = {
// 		{"ADD", Rad_Book.add_contact()},
// 		{"SEARCH", Rad_Book.Search()},
// 		{"EXIT", exit_phonebook}
// 	};

// 	std::cout << "hoi, reading input\n";
// 	while (1)
// 	{
// 		std::cin >> input;
// 		// std::cout << "input =" << input;
// 		auto it = input_map.find(input);
// 		if (it == input_map.end())
// 		{
// 			std::cout << "Please give a valid command, only available commands"  //line break here
// 					<< "ADD, SEARCH and EXIT\n";
// 			continue;
// 		}
// 		it->second();
// 	}
// 	return (0);
// }

int	main(void){
	PhoneBook	Rad_Book;
	std::string	input;

	//welcome msg + available commands (mb load screen)

	while (1)
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
