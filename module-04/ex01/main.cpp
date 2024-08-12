/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/07 18:23:13 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/08/07 18:23:13 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "NicePrint.hpp"

int main()
{
	NicePrint	msgs;
	msgs.stagger_print(YEL LINE_S "---\n|starting program|\n---"\
						 LINE_S RESET "\n", 15);
	msgs.stagger_print(LINE "\n", 10);

	const Animal* doggo = new Dog();
	const Animal* kitty = new Cat();
	msgs.stagger_print(LINE "\n", 10);

	delete doggo;//should not create a leak
	delete kitty;

	msgs.stagger_print(LINE "\n", 10);

	Animal *Pet_palace[100];
	for (size_t i = 0; i < sizeof(Pet_palace) / sizeof(*Pet_palace); i++)
	{
		if (i % 2)
			Pet_palace[i] = new Dog();
		else
			Pet_palace[i] = new Cat();
	}
	//print some random thoughts
	msgs.stagger_print("About to delete all\n", 10);
	msgs.count_down(5);

	for (size_t i = 0; i < sizeof(Pet_palace) / sizeof(*Pet_palace); i++)
		delete Pet_palace[i];


	return 0;
}
