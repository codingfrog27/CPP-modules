#include "NewMerge.hpp"

int g_compare = 0;

// ************************************************************************** //
//						Constructors and Destructors						//
// ************************************************************************** //

NewMerge::NewMerge(char **argv, int argc) : _recLvl(0), _compare(0)
{
	int	curNbr;
	if (argc < 3)
			throw(std::invalid_argument("Can't sort without at least 2 numbers"));

	for (size_t i = 1; argv[i]; i++)
	{
		curNbr = std::stoi(argv[i]); //should throw if out of range
		if (curNbr < 0)
			throw (std::invalid_argument("no negative ints allowed"));
		_nbrVec.push_back(curNbr);
		_pairs.emplace_back(std::vector<int>{curNbr});
	}
	_nbrSize = _nbrVec.size();
	_pairs.reserve(_nbrSize / 2);
	//would reserve inner vectors too but can only be done after initialisation
	//else could count how many times you can half nbrVec and reserve size would be divcount to power of 2
}

NewMerge::~NewMerge(void)
{
	std::cout << RED << "NewMerge: Destructor called" << RESET << std::endl;
}

void	NewMerge::sort()
{
	_nbrVec = fordJohnson(_nbrVec);
	// createJacobSeq(_pairs.front().size());

	std::cout << "vec size == " << _nbrVec.size() << std::endl;
	for (int num : _nbrVec)
		std::cout << num << " " << std::endl;
}

// Merge winner and loser into a new group
// std::vector<int> mergedGroup;
// mergedGroup.insert(mergedGroup.end(), group1.begin(), group1.end());
// mergedGroup.insert(mergedGroup.end(), group2.begin(), group2.end());
std::vector<int>	NewMerge::fordJohnson(std::vector<int> groups)
{

	std::vector<int> main;	// Winners
	std::vector<int> pend;	// Losers to insert

	std::cout << "Processing level " << _recLvl++ << "with " << groups.size() << " groups" << std::endl;
	if (groups.size() <= 1)
		return groups;
	
	for (size_t i = 0; i + 1 < groups.size(); i += 2)
	{
		int group1 = groups[i];
		int group2 = groups[i + 1];

		if (group1 < group2)
			std::swap(group1, group2);
		main.push_back(group1);
		pend.push_back(group2);
	}
	if (groups.size() % 2 == 1)
		pend.push_back(groups.back());
	
	std::vector<int> sortedMain = fordJohnson(main);
	_recLvl--;
	
	insertPendIntoMain(sortedMain, pend);
	
	return sortedMain;
}

bool	compare(int x, int y)
{
	g_compare++;
	if (x < y)
		return true;
	return false;
}

// ************************************************************************** //
//								private methods							  //
// ************************************************************************** //
void NewMerge::insertPendIntoMain(std::vector<int>& main, const std::vector<int>& pend)
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

// Jacobsthal is a sequence similar to fibonacci, its 0, 1 and then every step the last number gets added
// and the second last multiplied by 2
// 0, 1, 1, 3, 5, 11, 21, 43 etc.
std::vector<int> NewMerge::createJacobSeq(int n)
{
	std::vector<int> jacobSeq;
	int j0 = 0, j1 = 1;


	jacobSeq.push_back(0);
	while (true)
	{
		int j2 = j1 + (2 * j0);
		if (j2 > n)
			break;

		jacobSeq.push_back(j2);
		
		//add all indices inbetween
		for (int i = j2 - 1; i > j1 && i <= n; i--)
			jacobSeq.push_back(i);

		j0 = j1;
		j1 = j2;
	}

	//fill in last indices between last jacobs and n
	for (int i = n; i > j1; i--)
	{
		jacobSeq.push_back(i);
	}

	std::cout << "JACOB_SEQ --> ";

	for (size_t i = 0; i < jacobSeq.size(); i++)
	{
		std::cout << jacobSeq[i] << " ";
	}
	std::cout << std::endl;
	return (jacobSeq);
}


// ************************************************************************** //
//								Public methods							  //
// ************************************************************************** //

void	NewMerge::printPairs()
{
	std::cout << "PAIRS ARE: --> " << std::endl;
	for (size_t i = 0; i < _pairs.size(); i++)
	{
		std::cout << "[";
		for (size_t j = 0; j < _pairs[i].size(); ++j) {
			std::cout << _pairs[i][j];
			if (j + 1 < _pairs[i].size())
				std::cout << ", ";
		}
		std::cout << "]" << std::endl;
	}
}




// The main is initialised with the elements {b1, a1} and then with the rest of a's.
// The pend is initialised with the rest of bs starting from b2.
void	NewMerge::binaryInsert()
{
	size_t	i = 0, next = 1, groupAmount = 0, groupSize = _pairs[0].size(), halfSize = groupSize / 2;
	std::vector<int> currentGroup;
	while (!_pairs.empty())
	{
		while (groupAmount < _pairs.size() && groupSize == _pairs[groupAmount].size())
			groupAmount++;

			
			currentGroup.insert(_pairs[next].begin(), _pairs[next].end());
			_pairs.erase(_pairs.begin() + next);
			_pairs.insert(_pairs.begin() + i, currentGroup);
	}
}


// INSERT SORT

// 1 MAKE PAIRS (biggest on top)

// 2 START UR BIG GROUP
// 	every split check het bovenste nummer (top of stack) van de lagere helft 


// 	(de bovenste helft gaat sws naar rechts/hoger want dat weet je al door het vormen van de paren) 



// lage deel van pair gaat altijd links van de stack waaar die uitkomt)


// CHECK ALLEEN TOP OF STACK


// (hoogste en laagste stacks weet je altijd al)


// gedurende did check of leftover stacks zelfde size zijn om ze in te voegen

