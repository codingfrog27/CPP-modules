/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongWrongCat.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/07 18:02:45 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/08/07 18:02:45 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongCat_HPP
#define WrongCat_HPP

#include "WrongAnimal.hpp"


class WrongCat: public WrongAnimal {
public:
	// Constructors
	WrongCat();
	WrongCat(const WrongCat &other);
	WrongCat& operator=(const WrongCat &other);
	~WrongCat();

	// Getters
	// Setters
	// Other member functions
	void	makeSound() const;

private:
	// Member variables
};

#endif // WrongCat_HPP
