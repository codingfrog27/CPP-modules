/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 13:36:32 by mde-cloe      #+#    #+#                 */
/*   Updated: 2025/03/19 18:20:45 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <ctime>

#define C_YELLOW "\033[33m"
#define C_RESET "\033[0m"
#define C_CYAN "\033[36m"
#define C_RED "\033[31m"
#define LINE "-----------------------------------------"


void	promptEnter()
{	
	std::cout << C_YELLOW "\nPress Enter to continue..." C_RESET << std::endl;
	std::cin.get();
}

int RandomNbr()
{
	static std::mt19937 generator(std::time(nullptr));
	static std::uniform_int_distribution<int> distribution(0, 100);
		
	return distribution(generator);
}





//1 validate text
//2 store csv into map with the date being the key
//3 cycle through the input lines and print the value on each line



//concidered making it throw error instead of returning false but in case of only 1 stack jump 
// error return might be more readable (its all kinda whatevs tho)
bool	isInputValid()
{
	//check date | value format
	// check Year-month-day-format && for valid dates
	// check if every value is float or pos int between 0 and 1000

}

void	printConversion()
{
	// 2011-01-03 => 3 = 0.9
}

//exchange goes from 2009-01-02 to 2022-03-29,47115.93
//if date doesnt exist in DB use closest lower one
int main(int argc, char **argv) {
		
	if (argc != 2) {
		std::cerr << C_RED \
		"Error: Please give one and only one argument to the tbc program" C_RESET << std::endl;
	}

		
	return 0;
}