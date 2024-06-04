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


// small test main, added a name after arguments functionality for fun,
// used to actually be 2 for loops but I thought this way I can keep using the
// same I variable.. which really doesnt matter but oh well xd
int main(int argc, const char** argv)
{
	if(argc > 1)
	{
		Zombie**	arg_zombies = new Zombie* [argc - 1];
		int 		i = 0;
		while (argv[i + 1])
		{
			arg_zombies[i] = newZombie(argv[i + 1]);
			arg_zombies[i]->announce();
			i++;
		}
		i--;
		while(i >= 0)
		{
			delete arg_zombies[i];
			i--;
		}
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
