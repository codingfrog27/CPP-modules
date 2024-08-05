#ifndef CLAPTRAP_HPP

#define CLAPTRAP_HPP
#include <iostream>

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

#define LINE "-----------------------------------------------"

class ClapTrap {
public:
	// Constructors
	ClapTrap();
	ClapTrap(std::string Name);
	ClapTrap(const ClapTrap &other);
	ClapTrap& operator=(const ClapTrap &other);
	~ClapTrap();

	// Getters
	// Setters
	// Other member functions
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	bool	hasEnergy(void);
	bool	isAlive(void);
	void	status(void);

protected:
	std::string		_name;
	size_t			_health;
	size_t			_energy;
	size_t			_attack_damage;
};


#endif // CLAPTRAP_HPP
