#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <exception>

class NewMerge
{
	private:
		// Private Attributes
		std::vector<int>		_nbrVec;
		std::vector<std::queue<int>>		_pairs;
		

		void	makeFirstPairs();

	public:
		// Constructors and Destructors
		NewMerge(void) = delete;
		NewMerge(char **argv, int argc);
		NewMerge(const NewMerge &rhs) = delete;
		NewMerge &operator=(const NewMerge &rhs) = delete;
		~NewMerge(void);

		// Public Methods

} ;
