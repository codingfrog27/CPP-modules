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
		int									_recLvl;
		std::vector<int>					_jacobseq;
		int									_compare;
		

		void							makeFirstPairs();
		std::vector<std::vector<int>>	groupPairs \
		(std::vector<std::vector<int>> groups);

		std::vector<int>				createJacobSeq(int n);
		void							binaryInsert();
		std::vector<int>	fordJohnson(std::vector<int> groups);
		void insertPendIntoMain(std::vector<int>& mainChain, const std::vector<int>& pend);
		bool	compare(int x, int y);

		
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
