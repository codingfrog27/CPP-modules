/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coding_frog <coding_frog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   */
/*   Created: 2025/01/23 22:42:11 by coding_frog       #+#    #+#             */
/*   Updated: 2025/01/24 13:47:51 by coding_frog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "NicePrint.hpp"
#include <iostream>




//since I can only use one cast type per exercise and I need to cast refs
// dynamic cast is the only option (also most suited for this case (just results in ugly try catch))
int main() {

	try
	{
		for (int i = 0; i < 5; i++)
		{
			Base * object = generate();
			identify(object);
			delete object;
		}
		NicePrint::promptEnter();
		for (int i = 0; i < 5; i++)
		{
			Base * object = generate();
			identify(*object); //dereference object to pass by reference
			delete object;
		}
		identify(nullptr);
		NicePrint::promptEnter();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
	
}