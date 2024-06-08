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
	if (argc == 2)
	{
		int	lvl_nbr = yelling_guy.get_level(argv[1]);
		switch (lvl_nbr)
		{
			case 0 :
				yelling_guy.complain("DEBUG");
			case 1 :
				yelling_guy.complain("INFO");
			case 2 :
				yelling_guy.complain("WARNING");
			case 3 :
				yelling_guy.complain("ERROR");
				break ;
			default:
				yelling_guy.invalid_lvl();
		};
	}
	else
		std::cout << "please give 1 and only 1 argument\n";
	return (0);
}
