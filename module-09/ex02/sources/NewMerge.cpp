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
		if (i % 2 == 0)
			_pairs.emplace_back(nbr);
		else
		{
			_pairs.at(j).emplace_back(nbr);
			if (nbr > _pairs.at(j).front())
				std::swap(_pairs.at(j).front(), _pairs.at(j).back());
				// _pairs.at(j).insert(_pairs.at(j).begin(), nbr);
			j++;
		}
	}
}

void	NewMerge::swapPair(std::vector<int> &pair)
{
	int	halfSize = pair.size() / 2;
	int	halfSize = pair.size() / 2;
	int	tmp;
	for (size_t i = 0; i < halfSize; i++)
	{
		
	}
	
}

// ************************************************************************** //
//                                Public methods                              //
// ************************************************************************** //


// INSERT SORT

// 1 MAKE PAIRS (biggest on top)

// 2 START UR BIG GROUP
// 	every split check het bovenste nummer (top of stack) van de lagere helft 


// 	(de bovenste helft gaat sws naar rechts/hoger want dat weet je al door het vormen van de paren) 



// lage deel van pair gaat altijd links van de stack waaar die uitkomt)


// CHECK ALLEEN TOP OF STACK


// (hoogste en laagste stacks weet je altijd al)


// gedurende did check of leftover stacks zelfde size zijn om ze in te voegen