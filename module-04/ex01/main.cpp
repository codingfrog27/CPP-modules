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
	msgs.stagger_print("Subject tests\n" LINE "\n", 10);

	const Animal* doggo = new Dog();
	const Animal* kitty = new Cat();

	delete doggo;
	delete kitty;

	msgs.stagger_print(LINE "\n", 10);
	msgs.stagger_print("end of subject tests, about to construct 100 animals\n"\
						LINE "\n", 10);
	msgs.promptEnter();

	msgs.stagger_print("Constructing all pets in..", 30);
	msgs.count_down(3);




	Animal *petPalace[100];

	//all even numbers will be cats and uneven dogs
	for (size_t i = 0; i < sizeof(petPalace) / sizeof(*petPalace); i++)
	{
		if (i % 2)
			petPalace[i] = new Dog();
		else
			petPalace[i] = new Cat();
	}
	std::cout << LINE << std::endl;
	msgs.stagger_print("showing deepcopies and my extra useBrain function\n", 30);
	msgs.promptEnter();


	//downside of using a base class pointer is that you can't access methods specific
	// to the derived class therefore we dynamic cast
	Dog assignDog = dynamic_cast<const Dog&>(*petPalace[47]);
	Cat CopyCat(dynamic_cast<const Cat&>(*petPalace[42]));
	std::cout << LINE << std::endl;

	CopyCat.useBrain(77);
	assignDog.useBrain(42);

	std::cout << LINE << std::endl;
	dynamic_cast<Dog*>(petPalace[47])->printBrainAdress();
	assignDog.printBrainAdress();

	CopyCat.printBrainAdress();
	(dynamic_cast<const Cat&>(*petPalace[42])).printBrainAdress();

	std::cout << LINE << std::endl;
	msgs.stagger_print("about to delete 100 animals: ", 30);
	msgs.promptEnter();
	msgs.stagger_print("Deleting all pets in: ", 30);
	msgs.count_down(3);

	for (size_t i = 0; i < sizeof(petPalace) / sizeof(*petPalace); i++)
		delete petPalace[i];

	msgs.stagger_print(YEL LINE_S "---\n|End of program|\n---"\
						 LINE_S RESET \
						 "\n(below will be stack destructors)\n", 15);
	return 0;
}
