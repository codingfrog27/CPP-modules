#ifndef DOG_HPP

#include "Animal.hpp"
#define DOG_HPP


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
	void	makeSound() override;

private:
	// Member variables
};

#endif // DOG_HPP
