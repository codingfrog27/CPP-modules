#include "VecMerge.hpp"



int vecCompareCount = 0;

// ************************************************************************** //
//						Constructors and Destructors						//
// ************************************************************************** //

VecMerge::VecMerge(char **argv, int argc) : _recLvl(0), _startTime(std::chrono::high_resolution_clock::now())
{
	int	curNbr;
	if (argc < 3)
			throw(std::invalid_argument("Can't sort without at least 2 numbers"));
		
	_nbrVec.reserve(argc - 1);

	for (size_t i = 1; argv[i]; i++)
	{
		curNbr = std::stoi(argv[i]); 
		if (curNbr < 0)
			throw (std::invalid_argument("no negative ints allowed"));
		//more checks?
		_nbrVec.push_back(curNbr);
	}
}



static bool	compare(int x, int y)
{
	vecCompareCount++;
	if (x < y)
		return true;
	return false;
}

// ************************************************************************** //
//								private methods							  //
// ************************************************************************** //

std::vector<int>	VecMerge::fordJohnsonVec(std::vector<int> groups)
{

	std::vector<int>	main;
	std::vector<int>	pend;
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
		vecCompareCount++;
		main.push_back(group1);
		pend.push_back(group2);
	}
	if (groups.size() % 2 == 1)
		pend.push_back(groups.back());
	_recLvl++;
	std::vector<int> sortedMain = fordJohnsonVec(main);
	_recLvl--;
	insertPendIntoMain(sortedMain, pend);
	return sortedMain;
}


void VecMerge::insertPendIntoMain(std::vector<int>& main, const std::vector<int>& pend)
{
	std::vector<int>	jacob = createJacobSeq(pend.size());
	int					curJacob, inserNbr;
	for (size_t i = 0; i < jacob.size(); i++)
	{
		curJacob = jacob[i] - 1;
		if (curJacob <= 0) //could just make sure jacob doesnt have idx 0
			continue;
		inserNbr = pend[curJacob];
		auto insertIt = std::lower_bound(main.begin(), main.end(), inserNbr, compare);
		main.insert(insertIt, inserNbr);
	}
}


// ************************************************************************** //
//								Public methods							  //
// ************************************************************************** //

void	VecMerge::sort()
{
	printVec("vector before: sort\t", _nbrVec);

	_nbrVec = fordJohnsonVec(_nbrVec);

	std::chrono::duration<double, std::micro> time =  std::chrono::high_resolution_clock::now() - _startTime;
	printVec("\nafter:\t", _nbrVec);
	std::cout << "\nTime to process a range of " << _nbrVec.size() \
				<< " elements with std::vector: " << time.count() << " us" << std::endl;
}

