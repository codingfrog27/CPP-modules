/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/12 13:10:38 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/08/12 13:10:38 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP


#include "NicePrint.hpp"

#define IDEAS_ARR_SIZE 100

class Brain {
public:
	// Constructors
				Brain();
				Brain(const Brain &other);
	Brain& 		operator=(const Brain &other);
				~Brain();

	// Getters
	std::string getIdea(size_t i) const;
	// Setters
	void 		setIdea(std::string setme, size_t i);
	std::string	ideas[IDEAS_ARR_SIZE]; //get and setter redundant cuz

private:
	// Member variables
};

#define BRAIN_HPP


#endif // BRAIN_HPP
