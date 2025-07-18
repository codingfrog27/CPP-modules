#include "MergeMe.hpp"
#include <algorithm>
#include <chrono>



// ************************************************************************** //
//								Constructors and Destructors								//
// ************************************************************************** //

MergeMe::MergeMe(char **argv, int argc)
{
	std::cout << GREEN << "MergeMe: Default constructor called" << RESET << std::endl;
	
	int	curNbr;
	if (argc < 3)
			throw(std::invalid_argument("Can't sort without at least 2 numbers"));



	for (size_t i = 1; argv[i]; i++)
	{
		curNbr = std::stoi(argv[i]); //should throw if out of range
		if (curNbr < 0)
			throw (std::invalid_argument("no negative ints allowed"));
		_nbrVec.push_back(curNbr);		
	}
}


void	MergeMe::sortVector()
{


	makePairs();
	groupPairs();
	insertPendingElements();
}

void	MergeMe::makePairs()
{
	std::pair<int, int> current;

	for (size_t i = 0; i < _nbrVec.size(); i++)
	{
		if (i % 2 == 0)
			current.first = _nbrVec.at(i);
		else
		{
			current.second = _nbrVec.at(i);
			_pairs.push_back(current);
		}
	}
	if (_nbrVec.size() % 2 == 1) //if uneven, throw last nbr in pair by itself and make other -1
	{
		current.second = -1;
		_pairs.push_back(current);
	}

	
	//make sure first in pair is biggest
	for (auto& pair : _pairs)
	{
		if (pair.second > pair.first && pair.second != -1)
			std::swap(pair.first, pair.second);
	}
}

void MergeMe::groupPairs()
{

	_mainChain.clear();
	_leftovers.clear();


	// Sort pairs by their first value (which will be the largest)
	std::sort(_pairs.begin(), _pairs.end(),
		[](const std::pair<int, int>& a, const std::pair<int, int>& b) { return a.first < b.first; });

	for (const auto& pair : _pairs)
	{
		_mainChain.push_back(pair.first);  // Add all larger elements to main chain
		if (pair.second != -1)
			_leftovers.push_back(pair.second);  // Collect smaller elements in leftovers
	}
}




MergeMe::~MergeMe(void)
{
	std::cout << RED << "MergeMe: Destructor called" << RESET << std::endl;
}





// ************************************************************************** //
//										  Public methods										//
// ************************************************************************** //


void MergeMe::insertPendingElements()
{
	// Calculate Jacobsthal numbers for insertion sequence
	std::vector<int> jacobsthalIndices = generateJacobsthalSequence(_leftovers.size());
	
	// Insert each pending element according to the Jacobsthal sequence
	for (size_t i = 0; i < jacobsthalIndices.size() && i < _leftovers.size(); i++)
	{
		int pendIndex = jacobsthalIndices[i];
		if (pendIndex < (int)_leftovers.size())
		{
			int valueToInsert = _leftovers[pendIndex];
			// Binary search to find insertion position
			auto pos = std::lower_bound(_mainChain.begin(), _mainChain.end(), valueToInsert);
			_mainChain.insert(pos, valueToInsert);
		}
	}
	
	// Insert any remaining pending elements
	for (size_t i = 0; i < _leftovers.size(); i++)
	{
		if (std::find(jacobsthalIndices.begin(), jacobsthalIndices.end(), i) == jacobsthalIndices.end()) {
			int valueToInsert = _leftovers[i];
			auto pos = std::lower_bound(_mainChain.begin(), _mainChain.end(), valueToInsert);
			_mainChain.insert(pos, valueToInsert);
		}
	}
	
	// Update the original vector with sorted result
	_nbrVec = _mainChain;
}

void	MergeMe::timeAndSortVec()
{
	std::cout << "before:\t";
	for (int nbr : _nbrVec)
		std::cout << nbr << " ";

	auto start = std::chrono::high_resolution_clock::now();

	sortVector();

	std::chrono::duration<double, std::micro> time =  std::chrono::high_resolution_clock::now() - start;

	std::cout << "\nafter:\t";
	for (int nbr : _nbrVec)
		std::cout << nbr << " ";

	std::cout << "\nTime to process a range of " << _nbrVec.size() \
				<< " elements with std::vector: " << time.count() << " us" << std::endl;
	
}

//Jacobsthal is a sequence similar to fibonacci, its 0, 1 and then every step the last number gets added
// and the second last multiplied by 2
// 0, 1, 1, 3, 5, 11, 21, 43 etc.
std::vector<int> MergeMe::generateJacobsthalSequence(int n)
{
	std::vector<int> result;
	std::vector<int> sequence;
	if (n <= 0) return result;
	
	// First two Jacobsthal numbers

	//first is kinda weird maybe add 0 first?
	result.push_back(0);
	result.push_back(1);
	if (n == 1) return result;
		
	// Generate Jacobsthal numbers until we have enough
	int next;
	while (true)
	{
		next = (2 * result.at(result.size() - 2)) + result.back();
		if (next <= n)
				result.push_back(next);
		else
			break;
	}
	 
	 // Create insertion sequence from Jacobsthal numbers
	for (size_t i = 0; i < result.size(); i++)
	{
		sequence.push_back(result[i]);
		
		// Add indices between current and next Jacobsthal number
		int current = result[i];
		if (i + 1 < result.size())
			next = result[i + 1];
		else
			next = n + 1;

		for (int j = current + 1; j < next && j <= n; j++)
			sequence.push_back(j);
	 }
	 
	 return sequence;
}