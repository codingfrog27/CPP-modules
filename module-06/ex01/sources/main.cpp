/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coding_frog <coding_frog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:44:25 by coding_frog       #+#    #+#             */
/*   Updated: 2025/01/23 22:37:05 by coding_frog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

//extra testin and mb make Data a class or struct with it's own include file
int main()
{
	Data	egg = {"yummy", 42, "rich in protein! :)"};
	uintptr_t raw = Serialize::serialize(&egg);
	Data	*newEgg = Serialize::deserialize(raw);
	std::cout << "egg address ==\t\t" GREEN << &egg << std::endl \
	 << RESET "uint_ptr ==\t\t " GREEN << raw << std::endl \
	 <<RESET "new egg adress ==\t" GREEN << newEgg << RESET << std::endl;
	
	//class not instantiable like asked
	// Serialize test;
	return 0;
}
