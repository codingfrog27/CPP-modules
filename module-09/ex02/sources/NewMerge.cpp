#include "NewMerge.hpp"



// ************************************************************************** //
//                        Constructors and Destructors                        //
// ************************************************************************** //

NewMerge::NewMerge(char **argv, int argc)
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


// ************************************************************************** //
//                                private methods                              //
// ************************************************************************** //


void	NewMerge::makeFirstPairs()
{
	//what about dupes?
	int	nbr;
	// int j = 0;
	for (size_t i = 0; i < _nbrVec.size(); i++)
	{
		nbr = _nbrVec.at(i);
		// if (i % 2 == 0)
		_pairs.emplace_back(std::vector<int>{nbr});
		// else
		// {
		// 	_pairs.at(j).emplace_back(nbr);
		// 	if (nbr > _pairs.at(j).front())
		// 		std::swap(_pairs.at(j).front(), _pairs.at(j).back());
		// 	j++;
		// }
	}
}

//keeps merging the groups untill no size doubling is possible anymore
void	NewMerge::groupPairs()
{
	size_t i = 0, next = 1, groupSize = _pairs[i].size();
	while (_nbrVec.size() > 1)
	{
		if (next > _nbrVec.size() || next > _pairs.size() ||  _pairs[next].size() != groupSize)
			break; //split this if too see if can be simplified and exit condition can be improved! :)

		if (_nbrVec[i] < _nbrVec[next])
		{
			std::swap(_nbrVec[i], _nbrVec[next]);
			std::swap(_pairs[i], _pairs[next]);
		}

		_pairs[i].insert(_pairs[i].end(), _pairs[next].begin(), _pairs[next].end());
		_pairs.erase(_pairs.begin() + next);
		
		//main chain will only have the winners (up to only the largest number) so others get removed
		// (This also will keep it the index in line with pairs) :)
		_nbrVec.erase(_nbrVec.begin() + next);
		i++;
		next++;
	}
	//remove trailing nbr if its there
	if (i < _nbrVec.size() && _nbrVec.size() > 1)
		_nbrVec.erase(_nbrVec.begin() + i);
	

		
		// printPairs();

	//keep going untill no doubling is possible anymore 
	// if (_pairs.front().size() == _pairs.at(next).size())
	if (_pairs.front().size() != groupSize)
	{
		// std::cout << "new groupsize == " << _pairs.front().size() << " old size == " << groupSize << "\ngrouping again" << std::endl;
		groupPairs();
	}
	else
		std::cout << "amogus" << std::endl;
}

// Jacobsthal is a sequence similar to fibonacci, its 0, 1 and then every step the last number gets added
// and the second last multiplied by 2
// 0, 1, 1, 3, 5, 11, 21, 43 etc.
void NewMerge::createJacobSeq(int n)
{

	int j0 = 0, j1 = 1;


	// _jacobseq.push_back(1);
	while (true)
	{
		int j2 = j1 + (2 * j0);
		if (j2 > n)
			break;

		_jacobseq.push_back(j2);
		
		//add all indices inbetween
		for (int i = j2 - 1; i > j1 && i <= n; i--)
			_jacobseq.push_back(i);

		j0 = j1;
		j1 = j2;
	}

	//fill in last indices between last jacobs and n
	for (int i = n; i > j1; i--)
	{
		_jacobseq.push_back(i);
	}

	std::cout << "JACOB_SEQ --> ";

	for (size_t i = 0; i < _jacobseq.size(); i++)
	{
		std::cout << _jacobseq[i] << " ";
	}
	std::cout << std::endl;
}


// ************************************************************************** //
//                                Public methods                              //
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

void	NewMerge::sort()
{
	makeFirstPairs();
	groupPairs();
	createJacobSeq(_pairs.front().size());

	std::cout << "vec size == " << _nbrVec.size() << std::endl;
	for (int num : _nbrVec)
		std::cout << num << " " << std::endl;
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

// void	NewMerge::BinaryInsert()
// {

// }


// std::vector<int> MergeMe::generateJacobsthalSequence(int n)
// {
//     std::vector<int> sequence;
//     std::vector<int> ret;
//     if (n <= 0) return ret;  // Return empty sequence for invalid n
    
//     // Start with J(0)=0 and J(1)=1
//     sequence.push_back(0);
//     sequence.push_back(1);
    
//     // Generate Jacobsthal numbers up to n
//     int next;
//     while (true) {
//         next = sequence[sequence.size() - 1] + 2 * sequence[sequence.size() - 2];
//         if (next <= n)
//             sequence.push_back(next);
//         else
//             break;
//     }
    
//     // The first position is special - add it first if needed
//         ret.push_back(0);  // First position
    
//     // Build insertion sequence from Jacobsthal numbers, skipping 0
//     for (size_t i = 1; i < sequence.size(); i++) {
//         int start = sequence[i-1] + 1;
//         int end = sequence[i];
        
//         // Add in reverse order from current to next Jacobsthal number
//         for (int j = end; j >= start && j < n; j--) {
//             ret.push_back(j);
//         }
//     }
    
//     // Add any remaining elements
//     int start = sequence.back() + 1;
//     for (int j = start; j < n; j++) {
//         ret.push_back(j);
//     }
    
//     return ret;
// }


