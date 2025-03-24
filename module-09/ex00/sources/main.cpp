/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coding_frog <coding_frog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:36:32 by mde-cloe          #+#    #+#             */
/*   Updated: 2025/03/24 19:21:13 by coding_frog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <fstream>
#include <ctime>
#include <exception>
#include <sstream>
#include <regex>

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
void	isInputValid(std::string	path)
{
	std::ifstream input(path);
	if (!input.is_open())
		throw std::invalid_argument(std::string("Error: Could not open file: " + path));

	std::string line;
	// std::regex datePattern("^\\d{4}-\\d{2}-\\d{2}$");

	//^ ==match from start of string
	//  double \ cause 1 for regex one for string literal in C
	//so it says match anything that from the start of the string (^)
	//starts w 20, then 0, 1 or 2, then any digit and hopefully u get the picture
	//the last part is any digit + for at least one
	// //.?//d$ == optional . followed by any optional extra digits and the $ == end of string
	std::regex datePattern("^20[0-2]\\d-[01]\\d-[0-3]\\d | //d+//.?//d*$");
	std::getline(input, line);

	
	if (line != "data | value") 
		throw std::invalid_argument("Invalid file format. Expected 'date | value' in the first line.");
	while (std::getline(input, line)) {
		// Process each line here
		std::istringstream iss(line);
		std::string date, value;

		if (!(iss >> date) || !(iss >> value) || line.find('|') == std::string::npos) {
			throw std::invalid_argument("Invalid line format: " + line);
		}

		// Additional validation for date and value can be added here
	}
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