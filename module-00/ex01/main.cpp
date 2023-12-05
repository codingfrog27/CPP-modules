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

void	search(){}
void	add(){}
void	exit_phonebook(){
	std::cout << "doei";
	std::exit(0);
}

int	main(int argc, char **argv){
	PhoneBook	hoi;
	std::string	input;

	std::unordered_map<std::string, void(*)()> input_map = {
		{"ADD", search},
		{"SEARCH", add},
		{"EXIT", exit_phonebook}
	};

	while (1)
	{
		std::cout << "hoi, reading input\n";
		std::cin >> input;
		// std::cout << "input =" << input;
		auto it = input_map.find(input);
		if (it ==input_map.end())
			continue;
		it->second();
	}
	return (0);
}
