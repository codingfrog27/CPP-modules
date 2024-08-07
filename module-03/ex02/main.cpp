/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/01 20:36:53 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/08/01 20:36:53 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << LINE << "\n\t start of program \n" << LINE << std::endl;
	ScavTrap	bongo("bong");
	ScavTrap	epic("tubular droid");
	ScavTrap	copyCat(bongo);
	FragTrap 	high_fiver("cool guy");

	std::cout << LINE << "\n\tT H E	S T O R Y	B E G I N S\n" << LINE << std::endl;
	std::cout << "After many years of preparing tubulair droid is finally" \
	 "ready to avenge his friend.\n\nHe's enlisted the help of the dangerous high fiver.\n"  << std::endl;

	epic.attack("bong");
	bongo.takeDamage(20);
	bongo.status();
	high_fiver.attack("bong (copycat))");
	std::cout << "copycat revelas their true identity.. BABY PUNCHER" << std::endl;
	copyCat.attack("cool guy");
	high_fiver.takeDamage(20);
	std::cout << "but with cool guy's extra strength they gain the upper hand" \
	"\nand in an ironic twist of fate, Baby puncher and Bongo fall down the stairs!" << std::endl;
	copyCat.takeDamage(99);
	bongo.takeDamage(99);

	std::cout << LINE "\nSweet revenge has been had!!\n" LINE << std::endl;
	high_fiver.highFivesGuys();


	return 0;
}
