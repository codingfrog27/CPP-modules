/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/08 16:45:05 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/06/08 16:45:05 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP

#define HARL_HPP

#include <iostream>

class Harl
{
	private:
	std::string levels[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "INVALID_INPUT"};
	void (Harl::*Func_ptr_arr[4])() = {&Harl::debug, &Harl::info, \
										&Harl::warning, &Harl::error};
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

	public:
	void	complain(std::string level);
	void	cycle_all_levels(void);
	int		get_level(std::string level);
	void	invalid_lvl(void);
	Harl() = default;
	~Harl() = default;
};



#endif // !HARL_HPP
