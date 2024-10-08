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
#include "WrongCat.hpp"
#include "NicePrint.hpp"

int main()
{
	NicePrint	msgs;
	msgs.stagger_print(YEL LINE_S "---\n|starting program|\n---"\
						 LINE_S RESET "\n", 15);
	msgs.stagger_print(LINE "\n", 10);

	const Animal* 		meta = new Animal();
	const Animal* 		pupper = new Dog();
	const Animal* 		kitty = new Cat();
	const WrongAnimal* 	sus_kitty = new WrongCat();
	WrongAnimal			nonptr = WrongCat(); // = copy constructer and assignment and will then destroy the temporary wrongcat and animal?

	msgs.stagger_print(LINE "\n", 10);

	std::cout << pupper->getType() << std::endl;
	std::cout << kitty->getType() << std::endl;
	std::cout << sus_kitty->getType() << std::endl;


	msgs.stagger_print(LINE "\n", 10);

	meta->makeSound();
	kitty->makeSound(); //will output the cat sound!
	pupper->makeSound();
	sus_kitty->makeSound();
	nonptr.makeSound();


	msgs.stagger_print(LINE "\n", 10);

	delete meta;
	delete pupper;
	delete kitty;
	delete sus_kitty;
	return 0;
}
