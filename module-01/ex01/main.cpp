/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/08 16:53:36 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/05/08 16:53:36 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//could make the program argument the hoard nbr but..maybe should just keep
//making exercised instead of overperfecting tests 😅
int main(void)
{
	int	hordesize = 5;
	Zombie *horde = zombieHorde(hordesize, "Zombente");
	for (int i = 0; i < hordesize; i++)
		horde[i].announce();
	delete[] horde;
	return 0;
}
