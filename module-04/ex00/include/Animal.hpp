/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/07 18:01:09 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/08/07 18:01:09 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
public:
	// Constructors
	Animal();
	Animal(const Animal &other);
	Animal& operator=(const Animal &other);
	~Animal();

	// Getters
	// Setters
	// Other member functions
	virtual void		makeSound() const;
	const std::string	&getType() const;
protected:
	std::string type;
	// Member variables
};

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define BLK "\e[0;30m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"


#endif // ANIMEL_HPP
