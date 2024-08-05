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

#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << LINE << "\n\t start of program \n" << LINE << std::endl;

	ClapTrap	bud("little buddy");
	ScavTrap	bongo("bong");
	ScavTrap	epic("tubular droid");
	ScavTrap	copyCat(bongo);
	copyCat = epic;


	std::cout << LINE << "\n\tT H E	S T O R Y	B E G I N S\n" << LINE << std::endl;

	bongo.attack("capitalism");
	copyCat.attack("big corperations");

	std::cout << "\n The attacks miss the big corporations and hit our " \
	 << "cool droid and his innocent little buddy instead!! D:\v" << std::endl;

	epic.takeDamage(20);
	bud.takeDamage(20);

	std::cout << "feeling powerless they conform to the system\v" << std::endl;

	bongo.guardGate();
	copyCat.guardGate();

	std::cout << "Tubular droid vows to one day take revenge!\n" \
	<< LINE << "\n\tT H E	E N D	? ? ?\n" << LINE << std::endl;


	return 0;
}

	// ClapTrap	itsme("baby puncher");
	// ClapTrap	funny("just a funny guy");

	// itsme.attack("just a funny guy");
	// funny.takeDamage(0);

	// std::cout << "the funny guy trips and falls down the stairs D:" << std::endl;
	// funny.takeDamage(20);
	// std::cout << "baby puncher is struck with grief and deals with it the only way they know how" << std::endl;
	// funny.attack("me");
	// itsme.attack("you");
	// itsme.attack("everyone in this room");
	// itsme.attack("an innocent person on the street");
	// itsme.attack("your mom?!?!?!");
	// itsme.attack("steve (who?)");
	// itsme.attack("a baby");
	// itsme.attack("another baby");
	// itsme.attack("YET ANOTHER BABY??");
	// itsme.attack("how do they keep finding babies??");
	// itsme.attack("the last baby");
