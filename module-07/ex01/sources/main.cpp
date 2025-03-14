/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coding_frog <coding_frog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:35:17 by coding_frog       #+#    #+#             */
/*   Updated: 2025/01/24 17:00:43 by coding_frog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int main() {
	int intArray[] = {1, 2, 3, 4, 5};
	std::string strArray[] = {"Hello", "World", "!"};

	std::cout << "Int array: ";
	iter(intArray, 5, printElement<int>);
	//unfortunately since template func does want to know what type it is
	// upon calling have to specify int on printELement
	std::cout << std::endl;

	std::cout << "String array: ";
	iter(strArray, 3, printElement<std::string>);
	std::cout << std::endl;

	// Using a lambda function
	std::cout << "Int array doubled: ";
	iter(intArray, 5, doubleValue<int>);
	iter(intArray, 5, printElement<int>);
	std::cout << std::endl;

	return 0;
}