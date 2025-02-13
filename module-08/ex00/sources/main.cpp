/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-cloe <mde-cloe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:05:44 by mde-cloe          #+#    #+#             */
/*   Updated: 2025/02/13 19:30:14 by mde-cloe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

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
	std::vector<int> vec = {1, 2, 3, 4, 5};
	std::list<int> lst = {10, 20, 30, 40, 50};

	// Test with vector
	std::vector<int>::iterator vecIt = easyfind(vec, 42);
	if (vecIt == vec.end())
		std::cout << C_YELLOW "Element not found!" C_RESET << std::endl;
	else
		std::cout << C_CYAN "Found element: " << *vecIt << \
		" in vector :)" C_RESET << std::endl;


	// Test with list
	std::list<int>::iterator listIt = easyfind(lst, 40);
	if (listIt == lst.end())
		std::cout <<  C_YELLOW "Element not found!" << std::endl;
	else
		std::cout << C_CYAN "Found element: " << *listIt << \
		" in list :)" C_RESET << std::endl;


	return 0;
}