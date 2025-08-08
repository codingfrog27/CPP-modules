/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 13:36:32 by mde-cloe      #+#    #+#                 */
/*   Updated: 2025/08/08 18:00:32 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <random>
#include <ctime>
#include <iostream>
#include <sstream>
#include <regex>
#include "VecMerge.hpp"
#include "QueMerge.hpp"


#define C_YELLOW "\033[33m"
#define C_RESET "\033[0m"
#define C_CYAN "\033[36m"
#define C_RED "\033[31m"
#define LINE "-----------------------------------------"


// The Ford–Johnson sort (a.k.a. merge‑insertion) works by:

//     Pairing up elements and comparing within each pair.

//     Sorting the winners by recursively applying the same strategy.

//     Inserting the losers back into the sorted sequence of winners in a carefully chosen order to minimize comparisons.

int main(int argc, char **argv)
{
	try
	{
		VecMerge	vecSort(argv, argc);
		vecSort.sort();

		std::cout << LINE << std::endl;

		QueMerge	queSort(argv, argc);
		queSort.sort();
	}
	catch (const std::out_of_range &e)
	{
		std::cerr << C_RED "Error: " C_RESET "Number too large to be contained as int" << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << C_RED "Error: " C_RESET << e.what() << '\n';
	}
	return 0;
}



//dont forget to add djoyke eval notes to ex01

//all ints must be positive?

//use at least 2 containers
//strongly advised to iplement algo for both containers seperetaely?


//first print b4 sorty + input on first line

//after sort + sorted input on second

//3rd line: time to sort with container 1
//4th: time to sort container 2 (use precies times to show difference)
//  && time is sorting + data management

//no stack or map

//i can decide how to manage duplicate errors?

//vector
//list
//deque