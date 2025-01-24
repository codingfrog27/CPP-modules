/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coding_frog <coding_frog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:11:25 by coding_frog       #+#    #+#             */
/*   Updated: 2025/01/24 15:13:49 by coding_frog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <random>
#include <iostream>
#include <exception>

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
//invalid dynamic cast for ptr will return nullptr
void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "this is an A class ptr" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "this is an B class ptr" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "this is an C class ptr" << std::endl;
	else
		std::cout << "Unknown type ptr" << std::endl;
}


// invalid dynamic cast for ref will throw bad cast
//was mb better b4 refactor with just 4 prints and no nested trys but gotta be quirky
void identify(Base& p)
{
	char type = 0;
	try
	{
		(void)dynamic_cast<A&>(p); //void cast to suppress warning (not a real cast)
		type = 'A';
	}
	catch (const std::bad_cast&)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			type = 'B';
		}
		catch (const std::bad_cast&) 
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				type = 'C';
			}
			catch (const std::bad_cast&)
			{
				std::cout << "Unknown type ref" << std::endl;
				return;
			}	
		}
	}
	std::cout << "this is a "<< type << " class ref" << std::endl;
}
