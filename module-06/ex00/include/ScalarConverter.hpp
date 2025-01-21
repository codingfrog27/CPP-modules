/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-cloe <mde-cloe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:13:35 by mde-cloe          #+#    #+#             */
/*   Updated: 2025/01/21 15:11:57 by mde-cloe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class ScalarConverter
{
	private:
		// Private Attributes
		

	public:
		// Constructors and Destructors
		ScalarConverter(void) = delete;
		ScalarConverter(const ScalarConverter &rhs) = delete;
		ScalarConverter &operator=(const ScalarConverter &rhs) = delete;
		~ScalarConverter(void) = delete;

		// Public Methods
		static void	convert(std::string literal);
} ;
