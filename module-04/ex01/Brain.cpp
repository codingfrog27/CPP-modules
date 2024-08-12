/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/12 13:22:03 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/08/12 13:22:03 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// ************************************************************************** //
//                        Constructors and Destructors                        //
// ************************************************************************** //

Brain::Brain(void)
{
	std::cout << GREEN << "Brain: Default constructor called" << RESET << std::endl;
	const std::string realthoughts[] = \
			{"I'm hungry",
			"Think positive",
			"Stay focused",
			"Be kind",
			"Work hard",
			"Stay humble",
			"Keep learning",
			"Embrace change",
			"Be grateful",
			"Stay curious",
			"Help others"};
	for (size_t i = 0; i < IDEAS_ARR_SIZE; i++)
		ideas[i] = realthoughts[i % sizeof(realthoughts) / sizeof(realthoughts[0])];

}

Brain::Brain(const Brain &rhs)
{
	std::cout << GREEN << "Brain: Copy constructor called" << RESET << std::endl;
	for (size_t i = 0; i < IDEAS_ARR_SIZE; i++)
		ideas[i] = rhs.ideas[i];
}

Brain &Brain::operator=(const Brain &rhs)
{
	std::cout << GREEN << "Brain: Assignment operator called" << RESET << std::endl;

	if (this != &rhs)
	{
		for (size_t i = 0; i < IDEAS_ARR_SIZE; i++)
		ideas[i] = rhs.ideas[i];
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << RED << "Brain: Destructor called" << RESET << std::endl;
}

// ************************************************************************** //
//                                Public methods                              //
// ************************************************************************** //

std::string Brain::getIdea(size_t i) const
{
	if (i < IDEAS_ARR_SIZE)
		return (ideas[i]);
	return "";
}

void Brain::setIdea(std::string setme, size_t i)
{
	if (i < IDEAS_ARR_SIZE)
		ideas[i] = setme;
}
