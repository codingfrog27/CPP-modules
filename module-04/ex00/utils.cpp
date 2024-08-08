/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/08 20:09:30 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/08/08 20:09:30 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

void	high_five_loop()
{
	std::string me = "<(▼▽▼)っ";
	std::string you = "୧(^ ᵕ ^   )っ";
	std::string epic = "E P I C";
	int distance = 20;
	while (distance > 0)
	{
		system("clear");
		std::cout << me;
		for (int i = 0; i < distance; ++i) std::cout << " ";
		std::cout << you << std::endl;
		if (distance % 2)
			me.insert(0, 1, ' ');
		std::this_thread::sleep_for(std::chrono::milliseconds(20));
		distance--;
	}
}

void	stagger_print(std::string msg)
{
	for (size_t i = 0; msg[i]; i++)
	{
		std::cout << msg[i] << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(20));
	}
}

void	count_down(int counter)
{
	while (counter > 0)
	{
		system("clear");
		std::cout << YEL << counter << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(450));
		counter--;
	}

}
