#include <iostream>
#include <exception>
#include <vector>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"
class MergeMe
{
	private:
		std::vector<int>					_nbrVec;
		std::vector<std::pair<int, int>>	_pairs;
		std::vector<int>					_mainChain;
		std::vector<int>					_leftovers;
		int									_straggler;
		
		void	makePairs();
		void	groupPairs();
		void	sortPairs(int start);
		void	mergeInsertSort();
		void	printResult() const;
		void	sortMainChain();
		void	insertLeftovers();
		void	insertPendingElements();

		std::vector<int>	generateJacobsthalSequence(int n);



	public:
		// Constructors and Destructors
		MergeMe(void) = delete;
		MergeMe(char **argv, int argc);
		MergeMe(const MergeMe &rhs);
		MergeMe &operator=(const MergeMe &rhs) = delete;
		~MergeMe(void);

		// Public Methods
		void	sortVector();
		void	timeAndSortVec();

} ;