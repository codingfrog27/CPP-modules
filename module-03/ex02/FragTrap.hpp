/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/05 18:37:27 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/08/05 18:37:27 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP

#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	// Constructors
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &other);
	FragTrap& operator=(const FragTrap &other);
	~FragTrap();

	// Getters
	// Setters
	// Other member functions
	void	highFivesGuys(void);
	void	high_five_loop();
	void	stagger_print(std::string msg);
};


#endif // FRAGTRAP_HPP
