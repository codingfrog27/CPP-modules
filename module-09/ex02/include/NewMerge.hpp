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
		std::vector<int>					_nbrVec;
		std::vector<std::vector<int>>		_pairs;
		int									_nbrSize;
		std::vector<int>					_jacobseq;
		

		void							makeFirstPairs();
		std::vector<std::vector<int>>	groupPairs \
		(std::vector<std::vector<int>> groups);

		void							createJacobSeq(int n);
		void							binaryInsert();
		
		public:
		// Constructors and Destructors
		NewMerge(void) = delete;
		NewMerge(char **argv, int argc);
		NewMerge(const NewMerge &rhs) = delete;
		NewMerge &operator=(const NewMerge &rhs) = delete;
		~NewMerge(void);
		
		// Public Methods
		void	sort();
		void	printPairs();

} ;
