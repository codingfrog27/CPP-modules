/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coding_frog <coding_frog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:35:17 by coding_frog       #+#    #+#             */
/*   Updated: 2025/01/24 18:07:11 by coding_frog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define C_YELLOW "\033[33m"
#define C_RESET "\033[0m"
#define C_CYAN "\033[36m"
#define LINE "-----------------------------------------"


void	promptEnter()
{	
	std::cout << C_YELLOW "\nPress Enter to continue..." C_RESET << std::endl;
	std::cin.get();
}

int main()
{
	std::cout << "making string Array and assigning w index operator" << std::endl;
	Array<std::string> strArray(3);
	strArray[0] = "Hello";
	strArray[1] = "World";
	strArray[2] = "!";
	Array<std::string> newStrArray(strArray);
	promptEnter();

	std::cout << "making int arrays and using assignment operator too" << std::endl;
	Array<int> numArray(5);
	Array<int> newNumArray;
	for (unsigned int i = 0; i < numArray.size(); ++i)
		numArray[i] = i + 1;
	if(newNumArray.size() == 0)
		newNumArray = numArray;

	promptEnter();
	std::cout << C_CYAN "printime time!" C_RESET << std::endl;
	std::cout << "Int array: " << newNumArray << std::endl;
	std::cout << "String array: " << newStrArray << std::endl;

	return 0;
}