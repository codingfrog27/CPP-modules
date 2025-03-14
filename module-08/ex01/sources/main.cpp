/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-cloe <mde-cloe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:05:44 by mde-cloe          #+#    #+#             */
/*   Updated: 2025/03/14 17:18:48 by mde-cloe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <random>

#define C_YELLOW "\033[33m"
#define C_RESET "\033[0m"
#define C_CYAN "\033[36m"
#define LINE "-----------------------------------------"
#define	BEEGSIZE 50000

void	promptEnter()
{	
	std::cout << C_YELLOW "\nPress Enter to continue..." C_RESET << std::endl;
	std::cin.get();
}

int RandomNbr()
{
	static std::mt19937 generator(std::time(nullptr));
	static std::uniform_int_distribution<int> distribution(-100000, 100000);
		
	return distribution(generator);
}



int main() 
{
	std::vector<int> vec = {-100, 2, 3, 4, 5000, 70, -5, 20};
	Span	beeg(BEEGSIZE);
	Span	smal(vec.size());

	try
	{
		smal.addRange(vec.begin(), vec.end());
		for (size_t i = 0; i < BEEGSIZE; i++)
			beeg.addNumber(RandomNbr());

		promptEnter();

		//either will throw since no space
		smal.addRange(vec.begin(), vec.end());
		beeg.addNumber(RandomNbr());
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	promptEnter();

	std::cout << C_YELLOW "Smallest Span:\t" C_CYAN "in small == " << smal.shortestSpan() << \
	"\tin big == " << beeg.shortestSpan() << C_RESET << std::endl;

	std::cout << C_YELLOW "longest Span:\t" C_CYAN "in small == " << smal.longestSpan() << \
	"\tin big == " << beeg.longestSpan() << C_RESET << std::endl;

	return 0;
}