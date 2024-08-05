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

int	main(void)
{
	FragTrap frfr("cool guy");


	frfr.takeDamage(40);
	frfr.status();
	frfr.attack("the president of the united states");
	frfr.highFivesGuys();
	frfr.takeDamage(60);
	frfr.takeDamage(99);


	return 0; //status and death check only in ex02 Claptrap (replace all of em with newest?)
}
