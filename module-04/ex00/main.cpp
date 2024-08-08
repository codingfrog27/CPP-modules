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
#include "utils.hpp"

void	count_down(int counter);
void	stagger_print(std::string msg);

// int main()
// {
// 	count_down(3);
// 	stagger_print("starting program\n");
// 	Animal		whatAmI;
// 	Dog			Pupper;
// 	Cat			kitty;
	const WrongCat*	sus_kitty = new WrongCat();

// 	whatAmI.makeSound();
// 	Pupper.makeSound();
// 	kitty.makeSound();
// 	sus_kitty->makeSound();
// 	return 0;
// }

// finish cool util functions if i want :)

int main()
{
	const Animal* meta = new Animal();
	const Animal* pupper = new Dog();
	const Animal* kitty = new Cat();
	const WrongAnimal* sus_kitty = new WrongCat();
	WrongAnimal	yo = WrongCat();
	std::cout << pupper->getType() << " " << std::endl;
	std::cout << kitty->getType() << " " << std::endl;
	std::cout << sus_kitty->getType() << " " << std::endl;
	meta->makeSound();
	kitty->makeSound(); //will output the cat sound!
	pupper->makeSound();
	sus_kitty->makeSound();
	yo.makeSound();

	return 0;
}
