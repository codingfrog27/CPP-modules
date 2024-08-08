/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/07 18:02:45 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/08/07 18:02:45 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"


class Cat: public Animal {
public:
	// Constructors
	Cat();
	Cat(const Cat &other);
	Cat& operator=(const Cat &other);
	~Cat();

	// Getters
	// Setters
	// Other member functions
	void	makeSound() const override;

private:
	// Member variables
};

#endif // CAT_HPP
