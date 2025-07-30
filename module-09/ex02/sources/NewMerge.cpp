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
	int j = 0;
	for (size_t i = 0; i < _nbrSize; i++)
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

void	NewMerge::groupPairs()
{
	int	next, i = 0; //add bound protec
	for (; i < _nbrVec.size(); i++)
	{
		next = i + 1;
		if (next > _nbrVec.size() || next > _pairs.size() || \
			 _pairs[i].size() != _pairs[next].size())
			break;
		if (_nbrVec[i] < _nbrVec[next])
		{
			std::swap(_nbrVec[i], _nbrVec[next]);
			std::swap(_pairs[i], _pairs[next]);
		}
		//groupping pair by inserting the smaller onto the bigger and removing it after
		_pairs[i].insert(_pairs[i].end(), _pairs[next].begin(), _pairs[next].end());
		_pairs.erase(_pairs.begin() + next);
		
		//main chain will only have the winners (up to only the largest number) so others get removed
		_nbrVec.erase(_nbrVec.begin() + next);
		// This also will keep it the index in line with pairs :)
		_nbrSize = _nbrVec.size();
	}
	//remove trailing nbr if its there
	if (i < _nbrVec.size())
		_nbrVec.erase(_nbrVec.begin() + i);
}

// ************************************************************************** //
//                                Public methods                              //
// ************************************************************************** //


void	NewMerge::sort()
{
	makeFirstPairs();
	while (_nbrSize > 1)


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