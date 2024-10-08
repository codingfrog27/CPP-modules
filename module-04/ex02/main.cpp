/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-cloe <mde-cloe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:23:13 by mde-cloe          #+#    #+#             */
/*   Updated: 2024/08/30 17:25:59 by mde-cloe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "NicePrint.hpp"

int main()
{
	NicePrint	msgs;
	msgs.stagger_print(YEL LINE_S "---\n|starting program|\n---"\
						 LINE_S RESET "\n", 15);


	Cat		kitty;
	Dog		Doggo;
	// Animal	shallNotCompile;

	Animal *Doggy = new Dog;
	// Animal	*Illegal = new Animal;

	delete Doggy;
	msgs.high_five_loop();
	msgs.stagger_print(YEL LINE_S "---\n|End of program|\n---"\
					LINE_S RESET "\n(below will be stack destructors)\n", 15);

	return 0;
}

//would write more test but exercise is v straightforward
