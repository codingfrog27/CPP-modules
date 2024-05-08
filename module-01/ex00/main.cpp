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

int main(int argc, const char** argv)
{
	if(argc > 1)
	{
		Zombie**	arg_zombies = new Zombie *[argc - 1];
		for (size_t i = 0; argv[i + 1]; i++)
		{
			arg_zombies[i] = newZombie(argv[i + 1]);
			arg_zombies[i]->announce();
		}
		for (int i = argc - 1; i >= 0; i--)
			delete arg_zombies[i];
		delete[] arg_zombies;
	}
	else
	{
		Zombie	steve("steve");
		randomChump("silly little guy that exists just to scream");
		Zombie	*steve2 = newZombie("steve2");
		steve.announce();
		steve2->announce();
	}
	return 0;
}
