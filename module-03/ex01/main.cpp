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
	ClapTrap	bud("little buddy");
	ScavTrap	bongo("bong");
	ScavTrap	epic("tubular droid");
	ScavTrap	copyCat(bongo);
	copyCat = epic;
	bongo.attack("capitalism");
	copyCat.attack("big corperations");

	std::cout << "the attacks go wrong and hit our little buddy instead D:\v" \
	<< std::endl;

	bud.takeDamage(20);
	epic.takeDamage(20);

	std::cout << "feeling powerless they conform to the system\v" << std::endl;

	bongo.guardGate();
	copyCat.guardGate();



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
