/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/08 16:56:42 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/06/08 16:56:42 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


int main(int argc, const char** argv)
{
	Harl	yelling_guy;
	if (argc > 1)
	{
		for (size_t i = 1; argv[i]; i++)
			yelling_guy.complain(argv[i]);
	}
	else
		yelling_guy.cycle_all_levels();
	return (0);
}
