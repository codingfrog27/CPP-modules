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
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <random>

Base * generate(void)
{
	std::random_device rd;
	int i = rd() % 3;
	switch (i) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			throw std::runtime_error("random number generator failed");
	}
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p))
		std::cout << "this is an A class" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "this is an B class" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "this is an C class" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}



void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (const std::bad_cast&) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (const std::bad_cast&) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (const std::bad_cast&) {}

	std::cout << "Unknown type" << std::endl;
}


//since I can only use one cast type per exercise and I need to cast refs
// dynamic cast is the only option (also most suited for this case (just results in ugly try catch))
int main() {

	std::cout << '\n' << "testing identify with Base *p function" << '\n' << std::endl;
	try
	{
		for (int i = 0; i < 10; i++)
		{
			Base * object = generate();
			identify(*object);
			delete object;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
	
}