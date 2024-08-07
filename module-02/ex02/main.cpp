/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/10 19:33:57 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/06/10 19:33:57 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	//^here a gets incremented before being read by the expression, which is
	// why you see the new value printed right away
	std::cout << a++ << std::endl;
	// here it gets impremented after the expression (aka after the old value gets printed)
	std::cout << a << std::endl;


	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	Fixed swaggie(160), epic((float)10.1448392);
	if (swaggie > epic)
		std::cout << "swaggie is bigger!" << std::endl;
	std::cout << "added they are " << swaggie + epic << std::endl;
	std::cout << "multiplied == " << swaggie * epic << std::endl;
	std::cout << "divided == " << swaggie / epic << std::endl;
	return 0;
}
