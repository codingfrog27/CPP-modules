/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coding_frog <coding_frog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:35:17 by coding_frog       #+#    #+#             */
/*   Updated: 2025/01/24 16:02:31 by coding_frog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "template.hpp"
#include <iostream>

#define C_YELLOW "\033[33m"
#define C_RESET "\033[0m"
#define C_CYAN "\033[36m"
#define LINE "-----------------------------------------"


void	promptEnter()
{	
	std::cout << C_YELLOW "\nPress Enter to continue..." C_RESET << std::endl;
	std::cin.get();
}

int	main(void)
{
	int a = 2, b = 3;
	std::string beeg = "me beegg and longg string letsgoooooo", smol = "ME SMOL";
	//length actually doesn't matter, it's just for clarity

	std::cout << C_CYAN "Showing min and max" C_RESET << std::endl;
	std::cout << "Smallest num = " << ::min(a, b) << std::endl;
	std::cout << "Biggest num = " << ::max(a, b) << std::endl;
	std::cout << "Smallest string = " << ::min(beeg, smol) << std::endl;
	std::cout << "Biggest string = " << ::max(beeg, smol) << std::endl;
	promptEnter();
	std::cout << C_CYAN "Swapping values" C_RESET << std::endl;
	std::cout <<  C_YELLOW "Before swap: " C_RESET  "a = " << a << ", b = " << b \
	<< "\nbeeg == " << beeg << "and smol == " << smol << std::endl;
	swap(a, b);
	swap(beeg, smol);
	std::cout <<  C_YELLOW "After swap: " C_RESET  "a = " << a << ", b = " << b \
	<< "\nbeeg == " << beeg << " smol == " << smol << std::endl;
	return (0);
}