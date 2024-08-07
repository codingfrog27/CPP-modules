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
