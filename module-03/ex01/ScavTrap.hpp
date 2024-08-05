#ifndef SCAVTRAP_HPP

#define SCAVTRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap :  public ClapTrap {
public:
	// Constructors
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &other);
	ScavTrap& operator=(const ScavTrap &other);
	~ScavTrap();

	// Getters
	// Setters
	// Other member functions
	void	attack(const std::string& target) override;
	void	guardGate();
};


#endif // SCAVTRAP_HPP
