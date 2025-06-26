/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 13:36:32 by mde-cloe      #+#    #+#                 */
/*   Updated: 2025/06/26 17:04:11 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <random>
#include <ctime>
#include <iostream>
#include <sstream>
#include <regex>
#include <exception>

#define C_YELLOW "\033[33m"
#define C_RESET "\033[0m"
#define C_CYAN "\033[36m"
#define C_RED "\033[31m"
#define LINE "-----------------------------------------"




int main(int argc, char **argv)
{
	std::vector<int> nbrVec;
		
	try
	{
		if (argc < 3)
			throw(std::invalid_argument("Can't sort without at least 2 numbers"));
	
		parseInput(argv, nbrVec);
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



void	parseInput(char **argv, std::vector<int> &nbrVec)
{
	std::vector<std::pair<int, int>> pairs;
	std::pair<int, int> curPair;
	int					curNbr;
	size_t 				i = 0;
	for (; argv[i]; i++)
	{
		curNbr = std::stoi(argv[i]); //should throw if out of range
		if (curNbr < 0)
			throw (std::invalid_argument("no negative ints allowed"));
		if (i % 2 == 0)
			curPair.first = nbrVec[i];
		else
		{
			curPair.second = nbrVec[i];
			pairs.push_back(curPair);
		}	
	}
	if (i % 2 == 1) //should work cause i is 
	
	//make em sets already?


	// std::unordered_set<int> seenSet; Use this for sets i guess???


	//check every arg for being digit and in range AND no duplicates
	//check empty strings too maybe?
}

void	makePairs(std::vector<int> &nbrVec)
{
	
	std::vector<std::pair<int, int>> pairs;
	size_t i = 0;
	std::pair<int, int> current;
	for (; i < nbrVec.size(); i++)
	{
		if (i % 2 == 0)
			current.first = nbrVec[i];
		else
		{
			current.second = nbrVec[i];
			pairs.push_back(current);
		}
	}
	if (current.second 
}

//OOHH WE CAN MAKE VECTOR OR DEQUE OF PAIRS?


void	sortVector()
{
	std::vector<std::pair<int, int>> pairs;
	
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