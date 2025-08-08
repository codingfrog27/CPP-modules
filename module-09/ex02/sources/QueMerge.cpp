#include "QueMerge.hpp"
#include <algorithm>
#include <chrono>

int g_queCompareCount = 0;

// ************************************************************************** //
//						Constructors and Destructors						//
// ************************************************************************** //

QueMerge::QueMerge(char **argv, int argc) : _recLvl(0), _startTime(std::chrono::high_resolution_clock::now())
{
	int	curNbr;
	if (argc < 3)
			throw(std::invalid_argument("Can't sort without at least 2 numbers"));
		
	// _nbrque.reserve(argc - 1);

	for (size_t i = 1; argv[i]; i++)
	{
		curNbr = std::stoi(argv[i]); 
		if (curNbr < 0)
			throw (std::invalid_argument("no negative ints allowed"));
		//more checks?
		_nbrQue.push_back(curNbr);
	}
}



static bool	compare(int x, int y)
{
	g_queCompareCount++;
	if (x < y)
		return true;
	return false;
}

// ************************************************************************** //
//								private methods							  //
// ************************************************************************** //

std::deque<int>	QueMerge::fordJohnsonVec(std::deque<int> groups)
{

	std::deque<int>	main;
	std::deque<int>	pend;
	int					group1, group2;

	// std::cout << "Processing level " << _recLvl << " with " << groups.size() << " groups" << std::endl;
	if (groups.size() <= 1)
		return groups;
	
	for (size_t i = 0; i + 1 < groups.size(); i += 2)
	{
		group1 = groups[i];
		group2 = groups[i + 1];
		if (group1 < group2)
			std::swap(group1, group2);
		g_queCompareCount++;
		main.push_back(group1);
		pend.push_back(group2);
	}
	if (groups.size() % 2 == 1)
		pend.push_back(groups.back());
	_recLvl++;
	std::deque<int> sortedMain = fordJohnsonVec(main);
	_recLvl--;
	insertPendIntoMain(sortedMain, pend);
	return sortedMain;
}


void QueMerge::insertPendIntoMain(std::deque<int>& main, const std::deque<int>& pend)
{
	std::vector<int>	jacob = createJacobSeq(pend.size());
	int					curJacob, inserNbr;
	for (size_t i = 0; i < jacob.size(); i++)
	{
		curJacob = jacob[i] - 1;
		if (curJacob <= 0)
			continue;
		inserNbr = pend[curJacob];
		auto insertIt = std::lower_bound(main.begin(), main.end(), inserNbr, compare);
		main.insert(insertIt, inserNbr);
	}
}




// ************************************************************************** //
//								Public methods							  //
// ************************************************************************** //

void	QueMerge::sort()
{
	std::cout << "deque before sort:\t";
	for (int nbr : _nbrQue)
		std::cout << nbr << " ";

	_nbrQue = fordJohnsonVec(_nbrQue);

	std::chrono::duration<double, std::micro> time =  std::chrono::high_resolution_clock::now() - _startTime;
	std::cout << "\nafter:\t";
	for (int nbr : _nbrQue)
		std::cout << nbr << " ";

	std::cout << "\nTime to process a range of " << _nbrQue.size() \
				<< " elements with std::deque: " << time.count() << " us" << std::endl;
}

