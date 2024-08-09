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

// int main()
// {
// 	count_down(3);
// 	Animal		whatAmI;
// 	Dog			Pupper;
// 	Cat			kitty;
	// const WrongCat*	sus_kitty = new WrongCat();

// 	whatAmI.makeSound();
// 	Pupper.makeSound();
// 	kitty.makeSound();
// 	sus_kitty->makeSound();
// 	return 0;
// }

// finish cool util functions if i want :)

int main()
{
	NicePrint	msgs;
	msgs.stagger_print(YEL LINE_S "---\n|starting program|\n---"\
						 LINE_S RESET "\n", 15);
	msgs.stagger_print(LINE "\n", 25);

	const Animal* 		meta = new Animal();
	const Animal* 		pupper = new Dog();
	const Animal* 		kitty = new Cat();
	const WrongAnimal* 	sus_kitty = new WrongCat();
	WrongAnimal			nonptr = WrongCat(); // = copy constructer and assignment

	msgs.stagger_print(LINE "\n", 25);

	std::cout << pupper->getType() << " " << std::endl;
	std::cout << kitty->getType() << " " << std::endl;
	std::cout << sus_kitty->getType() << " " << std::endl;


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
