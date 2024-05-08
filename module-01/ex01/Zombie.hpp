#include <iostream>

class Zombie
{
	private:
		std::string	name;
	public:
					Zombie(void);
					Zombie(std::string	name);
					~Zombie(void);
			void	announce(void);
			void	setname(std::string	name);
};


Zombie* zombieHorde( int N, std::string name );
