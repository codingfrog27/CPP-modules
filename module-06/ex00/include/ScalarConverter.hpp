/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-cloe <mde-cloe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:13:35 by mde-cloe          #+#    #+#             */
/*   Updated: 2024/11/27 21:28:51 by mde-cloe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "string"

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
