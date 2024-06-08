/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/08 17:03:38 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/06/08 17:03:38 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level)
{
	for (size_t i = 0; levels[i] != "INVALID_INPUT"; i++)
	{
		if (level == this->levels[i])
		{
			(this->*Func_ptr_arr[i])();
			return;
		}
	}
	std::cout << "NOT A VALID LEVEL YA DINGUS D:<\n" << std::endl;
}

void	Harl::cycle_all_levels(void)
{
	for (size_t i = 0; levels[i] != "INVALID_INPUT"; i++)
			(this->*Func_ptr_arr[i])();
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]\nBow chicka wow wow \nThat's what my baby says\n" \
				<< std::endl;
}
void	Harl::info(void)
{
	std::cout << "[ INFO ]\nMow, mow, mow and my heart starts pumpin'\n" \
				<< std::endl;
}
void	Harl::warning(void)
{
	std::cout << "[ WARNING ]\nChicka chicka choo wap \nNever gonna stop\n"\
				<< std::endl;
}
void	Harl::error(void)
{
	std::cout << "[ ERROR ]\nGitchee gitchee goo means that I love you!💞\n" \
				<< std::endl;
}
