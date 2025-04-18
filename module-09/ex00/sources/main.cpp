/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 13:36:32 by mde-cloe      #+#    #+#                 */
/*   Updated: 2025/03/31 17:27:25 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <random>
#include <ctime>

#include "CoinRate.hpp"
#include "BadInput.hpp"

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


int main(int argc, char **argv) {
		
	if (argc != 2) {
		std::cerr << C_RED \
		"Error: Please give one and only one argument to the tbc program" C_RESET << std::endl;
	}
	try
	{
		CoinRate	Exchanger(argv[1]);
		// promptEnter();
		Exchanger.ShowAllRates();
	}
	catch(BadInput& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(std::exception &e)
	{
		std::cerr << "std except whoopsie" << e.what() << '\n';
	}
	
	
	return 0;
}