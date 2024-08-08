/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/08 18:53:07 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/08/08 18:53:07 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"


class Dog: public Animal {
public:
	// Constructors
	Dog();
	Dog(const Dog &other);
	Dog& operator=(const Dog &other);
	~Dog();

	// Getters
	// Setters
	// Other member functions
	void	makeSound() const override;

private:
	// Member variables
};

#endif // DOG_HPP
