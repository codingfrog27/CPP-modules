/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coding_frog <coding_frog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:26:20 by coding_frog       #+#    #+#             */
/*   Updated: 2025/01/24 16:37:18 by coding_frog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>
#define C_GREEN "\033[32m"
#define C_RESET "\033[0m"

template <typename T, typename F> void iter(T* array, size_t length, F func)
{
		for (size_t i = 0; i < length; ++i) {
			func(array[i]);
		}
		//used .at() instead of [] to throw an exception if out of bounds instead of crashing
		// but subject wants to use raw arrays so I'll use [] instead
}

template <typename T> void	doubleValue(T &element)
{
	element *= 2;
}

template <typename T>
void printElement(T &element) {
	std::cout << element << " ";
}

//not asked by subject, but cool that you
//can change template func behaviour based on type
template <>
void printElement<int>(int &element) {
	std::cout << C_GREEN << element << " " C_RESET;
}